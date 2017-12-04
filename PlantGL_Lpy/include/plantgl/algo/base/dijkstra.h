/* -*-c++-*-
 *  ----------------------------------------------------------------------------
 *
 *       PlantGL: Modeling Plant Geometry
 *
 *       Copyright 2000-2009 - Cirad/Inria/Inra - Virtual Plant Team
 *
 *       File author(s): F. Boudon (frederic.boudon@cirad.fr) et al.
 *
 *       Development site : https://gforge.inria.fr/projects/openalea/
 *
 *  ----------------------------------------------------------------------------
 *
 *                      GNU General Public Licence
 *
 *       This program is free software; you can redistribute it and/or
 *       modify it under the terms of the GNU General Public License as
 *       published by the Free Software Foundation; either version 2 of
 *       the License, or (at your option) any later version.
 *
 *       This program is distributed in the hope that it will be useful,
 *       but WITHOUT ANY WARRANTY; without even the implied warranty of
 *       MERCHANTABILITY or FITNESS For A PARTICULAR PURPOSE. See the
 *       GNU General Public License for more details.
 *
 *       You should have received a copy of the GNU General Public
 *       License along with this program; see the file COPYING. If not,
 *       write to the Free Software Foundation, Inc., 59
 *       Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  ----------------------------------------------------------------------------
 */

#ifndef __dijkstra_h__
#define __dijkstra_h__

#include "../algo_config.h"
#include <plantgl/scenegraph/container/indexarray.h>
#include <plantgl/tool/util_array.h>

#include <memory>

// #define PGL_USE_PRIORITY_QUEUE

#ifndef PGL_USE_PRIORITY_QUEUE
#ifdef WITH_BOOST
#include <boost/version.hpp>

#if BOOST_VERSION >= 104900
    #include <boost/heap/fibonacci_heap.hpp>
    #define PGL_USE_FIBONACCI_HEAP
#endif
#endif
#endif

#ifndef PGL_USE_FIBONACCI_HEAP
    #include <queue>
    #include <vector>
    #ifndef PGL_USE_PRIORITY_QUEUE
        #define PGL_USE_PRIORITY_QUEUE
    #endif
#endif
    

PGL_BEGIN_NAMESPACE

struct Node {
    uint32_t id;
    uint32_t parent;
    real_t distance;
    Node(uint32_t _id, uint32_t _parent, real_t _distance) 
        : id(_id), parent(_parent), distance(_distance) {}
} ;

typedef std::vector<Node> NodeList;


struct nodecompare {
       const TOOLS(RealArrayPtr)& __distances;

       nodecompare(const TOOLS(RealArrayPtr)& distances) : __distances(distances) {}
       bool operator()(const uint32_t& a,const uint32_t& b) const { return __distances->getAt(a) > __distances->getAt(b); }
};


#ifdef PGL_USE_FIBONACCI_HEAP
  typedef boost::heap::fibonacci_heap<uint32_t, boost::heap::compare<nodecompare > > dijkstraheap;
  typedef typename dijkstraheap::handle_type dijkstrahandle;
#else
  typedef std::priority_queue<uint32_t, std::vector<uint32_t>, nodecompare > dijkstraheap;
#endif



enum color { black, grey, white };


typedef std::vector<std::pair<uint32_t, real_t> > NodeDistancePairList;

struct DijkstraAllocator {
    void allocate(size_t nbnodes, TOOLS(RealArrayPtr)& distances,  uint32_t *& parents, color *& colored) const {
        distances = TOOLS(RealArrayPtr)(new TOOLS(RealArray)(nbnodes,REAL_MAX));
        parents = new uint32_t[nbnodes];
        colored = new color[nbnodes];

        // for (real_t * itdist = distances ; itdist != distances+nbnodes ; ++itdist) *itdist = REAL_MAX;
        for (color * itcol = colored ; itcol != colored+nbnodes ; ++itcol) *itcol = black;
    }

    
    void desallocate(TOOLS(RealArrayPtr) distances, uint32_t * parents, color * colored)  const {
        delete [] parents;        
        delete [] colored;
    }

#ifdef PGL_USE_FIBONACCI_HEAP
    void allocate(size_t nbnodes, dijkstrahandle *& handles)  const {
        handles = new dijkstrahandle[nbnodes];
    }

    void desallocate( dijkstrahandle * handles ) const {
        delete [] handles;
    }
#endif

};

class DijkstraReusingAllocator {
    class Cache {
    public:
        TOOLS(RealArrayPtr) distances;  
        uint32_t * parents;
        color * colored;
#ifdef PGL_USE_FIBONACCI_HEAP
        dijkstrahandle * handles
#endif

        Cache() : distances(), parents(NULL), colored(NULL)
#ifdef PGL_USE_FIBONACCI_HEAP
        handles(NULL)
#endif
        {}

        ~Cache(){
            delete [] parents;
            delete [] colored;
#ifdef PGL_USE_FIBONACCI_HEAP
            delete [] handles;
#endif
        }

    };

public:
    DijkstraReusingAllocator() : __cache(new Cache()) {}
    ~DijkstraReusingAllocator() {
        if (__cache) delete __cache;
    }

    void allocate(size_t nbnodes, TOOLS(RealArrayPtr)& distances,  uint32_t *& parents, color *& colored) const {
        if (__cache->parents == NULL){
            __cache->distances = TOOLS(RealArrayPtr)(new TOOLS(RealArray)(nbnodes,REAL_MAX));
            __cache->parents = new uint32_t[nbnodes];
            __cache->colored = new color[nbnodes];
        }

        distances = __cache->distances;
        parents = __cache->parents;
        colored = __cache->colored;

        for (TOOLS(RealArray)::iterator itdist = distances->begin() ; itdist != distances->end() ; ++itdist) *itdist = REAL_MAX;
        for (color * itcol = colored ; itcol != colored+nbnodes ; ++itcol) *itcol = black;
        for (uint32_t * itpar = parents ; itpar != parents+nbnodes ; ++itpar) *itpar = 0;
    }

    
    void desallocate(TOOLS(RealArrayPtr) distances, uint32_t * parents, color * colored)  const {
    }

#ifdef PGL_USE_FIBONACCI_HEAP
    void allocate(size_t nbnodes, dijkstrahandle *& handles)  const {
        if (__cache->parents == NULL){
            __cache->handles = new dijkstrahandle[nbnodes];
        }
        handles = __cache->handles;
    }

    void desallocate( dijkstrahandle * handles ) const {
    }
#endif

protected:
    Cache * __cache;

};

template<class EdgeWeigthEvaluation, class Allocator>
NodeList  dijkstra_shortest_paths_in_a_range(const IndexArrayPtr& connections, 
                                             uint32_t root, 
                                             EdgeWeigthEvaluation& distevaluator,
                                             real_t maxdist,
                                             uint32_t maxnbelements,
                                             const Allocator& allocator )
 {

     NodeList result;

     size_t nbnodes = connections->size();
     size_t nbprocessednodes = 0;

     TOOLS(RealArrayPtr) distances = NULL;
     uint32_t * parents = NULL;
     color * colored = NULL;

     allocator.allocate(nbnodes, distances, parents, colored);

     assert (is_valid_ptr(distances));
     assert (parents != NULL);
     assert (colored != NULL);

     distances->setAt(root,0);
     parents[root] = root;
 

     struct nodecompare comp(distances);
     dijkstraheap Q(comp);

#ifdef PGL_USE_FIBONACCI_HEAP
     dijkstrahandle * handles = NULL;
     allocator.allocate(nbnodes, handles);
     assert (handles != NULL);
     handles[root] = Q.push(root);
#else
     Q.push(root);
#endif

/*
     for(NodeDistancePairList::const_iterator itdist = precomputed.begin(); itdist != precomputed.end(); ++itdist){
        if (itdist->second < maxdist){
            distances->setAt(itdist->first,itdist->second);
            parents[itdist->first] = root;
#ifdef PGL_USE_FIBONACCI_HEAP
            handles[itdist->first] = Q.push(itdist->first);
#endif
        }
     }
*/
     while((!Q.empty()) && (nbprocessednodes < maxnbelements)){
         uint32_t current = Q.top(); Q.pop();
#ifdef PGL_USE_PRIORITY_QUEUE
         if(colored[current] == white) continue;
#endif
         result.push_back(Node(current, parents[current], distances->getAt(current)));
         colored[current] = white;

         nbprocessednodes += 1;

         const Index& nextchildren = connections->getAt(current);
         for (Index::const_iterator itchildren = nextchildren.begin();
             itchildren != nextchildren.end(); ++itchildren)
         {
             uint32_t v = *itchildren;

             real_t weigthuv = distevaluator(current,v); 
             real_t distance = weigthuv + distances->getAt(current);

             if (distance <= maxdist && distance < distances->getAt(v)) {
                distances->setAt(v, distance);
                parents[v]   = current;

                if (colored[v] == black) {
                    colored[v] = grey;
#ifdef PGL_USE_FIBONACCI_HEAP
                    handles[v] = Q.push(v);
#else
                    Q.push(v);
#endif
                }
                else if (colored[v] == grey){
#ifdef PGL_USE_FIBONACCI_HEAP
                    Q.decrease(handles[v], v);
#else
                    Q.push(v);
#endif
                }

             }
         }
     }
#ifdef PGL_USE_FIBONACCI_HEAP
     allocator.desallocate(handles);
#endif
     allocator.desallocate(distances, parents, colored);
     return result;
 }


template<class EdgeWeigthEvaluation>
NodeList  dijkstra_shortest_paths_in_a_range(const IndexArrayPtr& connections, 
                                             uint32_t root, 
                                             EdgeWeigthEvaluation& distevaluator,
                                             real_t maxdist = REAL_MAX,
                                             uint32_t maxnbelements = UINT32_MAX)
                                             
 { return dijkstra_shortest_paths_in_a_range(connections,root,distevaluator,maxdist,maxnbelements,DijkstraAllocator());  }
 
template<class EdgeWeigthEvaluation>
std::pair<TOOLS(Uint32Array1Ptr),TOOLS(RealArrayPtr)>  dijkstra_shortest_paths(const IndexArrayPtr& connections, 
                                   uint32_t root, 
                                   EdgeWeigthEvaluation& distevaluator)
 {


     size_t nbnodes = connections->size();
     TOOLS(RealArrayPtr) distances(new TOOLS(RealArray)(nbnodes,REAL_MAX));
     distances->setAt(root,0);

     TOOLS(Uint32Array1Ptr) parents(new TOOLS(Uint32Array1)(nbnodes,UINT32_MAX));
     parents->setAt(root,root);

     std::vector<color> colored(nbnodes,black);



     struct nodecompare comp(distances);
     dijkstraheap Q(comp);

#ifdef PGL_USE_FIBONACCI_HEAP
     handle * handles = new handle[nbnodes];
     handles[root] = Q.push(root);
#else
     Q.push(root);
#endif

     while(!Q.empty()){
         uint32_t current = Q.top(); Q.pop(); 
#ifdef PGL_USE_PRIORITY_QUEUE
         if(colored[current] == white) continue;
#endif
         colored[current] = white;
         const Index& nextchildren = connections->getAt(current);
         for (Index::const_iterator itchildren = nextchildren.begin();
             itchildren != nextchildren.end(); ++itchildren)
         {
             uint32_t v = *itchildren;
             real_t weigthuv = distevaluator(current,v); 
             real_t distance = weigthuv+distances->getAt(current);
             if (distance < distances->getAt(v)){
                 // printf("consider child %i %f %f %i\n", v, distance, (distances->getAt(v)!=REAL_MAX?distances->getAt(v):-1), int(colored[v]));
                 distances->setAt(v,distance);
                 parents->setAt(v,current);
                if (colored[v] == black) {
                    colored[v] = grey;
#ifdef PGL_USE_FIBONACCI_HEAP
                    handles[v] = Q.push(v);
#else
                    Q.push(v);
#endif
                }
                else if (colored[v] == grey){
#ifdef PGL_USE_FIBONACCI_HEAP
                    Q.decrease(handles[v], v);
#else
                    Q.push(v);
#endif
                }
             }
         }
     }
     return std::pair<TOOLS(Uint32Array1Ptr),TOOLS(RealArrayPtr)>(parents,distances);
 }

 /*
 DIJKSTRA(G, s, w)
  for each vertex u in V
    d[u] := infinity 
    p[u] := u 
    color[u] := WHITE
  end for
  color[s] := GRAY 
  d[s] := 0 
  INSERT(Q, s)
  while (Q != �)
    u := EXTRACT-MIN(Q)
    S := S U { u }
    for each vertex v in Adj[u]
      if (w(u,v) + d[u] < d[v])
        d[v] := w(u,v) + d[u]
        p[v] := u 
        if (color[v] = WHITE) 
          color[v] := GRAY
          INSERT(Q, v) 
        else if (color[v] = GRAY)
          DECREASE-KEY(Q, v)
      else
        ...
    end for
    color[u] := BLACK
  end while
  return (d, p)
  */

PGL_END_NAMESPACE

#endif
