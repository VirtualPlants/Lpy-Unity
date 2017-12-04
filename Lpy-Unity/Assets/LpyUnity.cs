using System.Runtime.InteropServices;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace Lpy
{
    public class LpyUnity
    {
        private List<Material> _materials;
        private List<GameObject> _surfaces;
        private GameObject _parent;

        private List<GameObject> _tree;

#if UNITY_EDITOR
        static IntPtr nativeLibraryPtr;
#endif

#region CallBacks
        private LpyStructAndType.MakeCylinderCallback _makeCylinder;
        private LpyStructAndType.MakeConeCallback _makeCone;
        private LpyStructAndType.MakeSphereCallback _makeSphere;
        private LpyStructAndType.MakeBoxCallback _makeBox;
        private LpyStructAndType.MakeCircleCallback _makeCircle;
        private LpyStructAndType.MakeQuadCallback _makeQuad;
        private LpyStructAndType.MakeSurfaceCallback _makeSurface;
        private LpyStructAndType.MakePolygonCallback _makePolygon;
        private LpyStructAndType.MakeGeneralizedGeometryCallback _makeGeneralizedGeometry;

        private LpyStructAndType.WriteCallback _debug;
        private LpyStructAndType.WriteCallback _warning;
        private LpyStructAndType.WriteCallback _error;
#endregion

#region MeshCreator
        private Mesh CreateCone(float bottomRadius, float topRadius, float height, int nbSides)
        {
            var mesh = new Mesh();

            int nbVerticesCap = nbSides + 1;
            #region Vertices

            // bottom + top + sides
            Vector3[] vertices = new Vector3[nbVerticesCap + nbVerticesCap + nbSides * 2 + 2];
            int vert = 0;
            float _2pi = Mathf.PI * 2f;

            // Bottom cap
            vertices[vert++] = new Vector3(0f, 0f, 0f);
            while (vert <= nbSides)
            {
                float rad = (float)vert / nbSides * _2pi;
                vertices[vert] = new Vector3(Mathf.Cos(rad) * bottomRadius, 0f, Mathf.Sin(rad) * bottomRadius);
                vert++;
            }

            // Top cap
            vertices[vert++] = new Vector3(0f, height, 0f);
            while (vert <= nbSides * 2 + 1)
            {
                float rad = (float)(vert - nbSides - 1) / nbSides * _2pi;
                vertices[vert] = new Vector3(Mathf.Cos(rad) * topRadius, height, Mathf.Sin(rad) * topRadius);
                vert++;
            }

            // Sides
            int v = 0;
            while (vert <= vertices.Length - 4)
            {
                float rad = (float)v / nbSides * _2pi;
                vertices[vert] = new Vector3(Mathf.Cos(rad) * topRadius, height, Mathf.Sin(rad) * topRadius);
                vertices[vert + 1] = new Vector3(Mathf.Cos(rad) * bottomRadius, 0, Mathf.Sin(rad) * bottomRadius);
                vert += 2;
                v++;
            }
            vertices[vert] = vertices[nbSides * 2 + 2];
            vertices[vert + 1] = vertices[nbSides * 2 + 3];
            #endregion

            #region Normales

            // bottom + top + sides
            Vector3[] normales = new Vector3[vertices.Length];
            vert = 0;

            // Bottom cap
            while (vert <= nbSides)
            {
                normales[vert++] = Vector3.down;
            }

            // Top cap
            while (vert <= nbSides * 2 + 1)
            {
                normales[vert++] = Vector3.up;
            }

            // Sides
            v = 0;
            while (vert <= vertices.Length - 4)
            {
                float rad = (float)v / nbSides * _2pi;
                float cos = Mathf.Cos(rad);
                float sin = Mathf.Sin(rad);

                normales[vert] = new Vector3(cos, 0f, sin);
                normales[vert + 1] = normales[vert];

                vert += 2;
                v++;
            }
            normales[vert] = normales[nbSides * 2 + 2];
            normales[vert + 1] = normales[nbSides * 2 + 3];
            #endregion

            #region UVs
            Vector2[] uvs = new Vector2[vertices.Length];

            // Bottom cap
            int u = 0;
            uvs[u++] = new Vector2(0.5f, 0.5f);
            while (u <= nbSides)
            {
                float rad = (float)u / nbSides * _2pi;
                uvs[u] = new Vector2(Mathf.Cos(rad) * .5f + .5f, Mathf.Sin(rad) * .5f + .5f);
                u++;
            }

            // Top cap
            uvs[u++] = new Vector2(0.5f, 0.5f);
            while (u <= nbSides * 2 + 1)
            {
                float rad = (float)u / nbSides * _2pi;
                uvs[u] = new Vector2(Mathf.Cos(rad) * .5f + .5f, Mathf.Sin(rad) * .5f + .5f);
                u++;
            }

            // Sides
            int u_sides = 0;
            while (u <= uvs.Length - 4)
            {
                float t = (float)u_sides / nbSides;
                uvs[u] = new Vector3(t, 1f);
                uvs[u + 1] = new Vector3(t, 0f);
                u += 2;
                u_sides++;
            }
            uvs[u] = new Vector2(1f, 1f);
            uvs[u + 1] = new Vector2(1f, 0f);
            #endregion

            #region Triangles
            int nbTriangles = nbSides + nbSides + nbSides * 2;
            int[] triangles = new int[nbTriangles * 3 + 3];

            // Bottom cap
            int tri = 0;
            int i = 0;
            while (tri < nbSides - 1)
            {
                triangles[i] = 0;
                triangles[i + 1] = tri + 1;
                triangles[i + 2] = tri + 2;
                tri++;
                i += 3;
            }
            triangles[i] = 0;
            triangles[i + 1] = tri + 1;
            triangles[i + 2] = 1;
            tri++;
            i += 3;

            // Top cap
            //tri++;
            while (tri < nbSides * 2)
            {
                triangles[i] = tri + 2;
                triangles[i + 1] = tri + 1;
                triangles[i + 2] = nbVerticesCap;
                tri++;
                i += 3;
            }

            triangles[i] = nbVerticesCap + 1;
            triangles[i + 1] = tri + 1;
            triangles[i + 2] = nbVerticesCap;
            tri++;
            i += 3;
            tri++;

            // Sides
            while (tri <= nbTriangles)
            {
                triangles[i] = tri + 2;
                triangles[i + 1] = tri + 1;
                triangles[i + 2] = tri + 0;
                tri++;
                i += 3;

                triangles[i] = tri + 1;
                triangles[i + 1] = tri + 2;
                triangles[i + 2] = tri + 0;
                tri++;
                i += 3;
            }
            #endregion

            mesh.vertices = vertices;
            mesh.normals = normales;
            mesh.uv = uvs;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();

            return mesh;
        }

        private Mesh CreateCylinder(float radius, float height, int nbSides)
        {
            var mesh = new Mesh();

            // Outter shell is at radius1 + radius2 / 2, inner shell at radius1 - radius2 / 2
            float bottomRadius1 = radius;// / 3f;
            float bottomRadius2 = 0;
            float topRadius1 = radius;// / 3f;
            float topRadius2 = 0;

            int nbVerticesCap = nbSides * 2 + 2;
            int nbVerticesSides = nbSides * 2 + 2;
            #region Vertices

            // bottom + top + sides
            Vector3[] vertices = new Vector3[nbVerticesCap * 2 + nbVerticesSides * 2];
            int vert = 0;
            float _2pi = Mathf.PI * 2f;

            // Bottom cap
            int sideCounter = 0;
            while (vert < nbVerticesCap)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;
                float cos = Mathf.Cos(r1);
                float sin = Mathf.Sin(r1);
                vertices[vert] = new Vector3(cos * (bottomRadius1 - bottomRadius2 * .5f), 0f, sin * (bottomRadius1 - bottomRadius2 * .5f));
                vertices[vert + 1] = new Vector3(cos * (bottomRadius1 + bottomRadius2 * .5f), 0f, sin * (bottomRadius1 + bottomRadius2 * .5f));
                vert += 2;
            }

            // Top cap
            sideCounter = 0;
            while (vert < nbVerticesCap * 2)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;
                float cos = Mathf.Cos(r1);
                float sin = Mathf.Sin(r1);
                vertices[vert] = new Vector3(cos * (topRadius1 - topRadius2 * .5f), height, sin * (topRadius1 - topRadius2 * .5f));
                vertices[vert + 1] = new Vector3(cos * (topRadius1 + topRadius2 * .5f), height, sin * (topRadius1 + topRadius2 * .5f));
                vert += 2;
            }

            // Sides (out)
            sideCounter = 0;
            while (vert < nbVerticesCap * 2 + nbVerticesSides)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;
                float cos = Mathf.Cos(r1);
                float sin = Mathf.Sin(r1);

                vertices[vert] = new Vector3(cos * (topRadius1 + topRadius2 * .5f), height, sin * (topRadius1 + topRadius2 * .5f));
                vertices[vert + 1] = new Vector3(cos * (bottomRadius1 + bottomRadius2 * .5f), 0, sin * (bottomRadius1 + bottomRadius2 * .5f));
                vert += 2;
            }

            // Sides (in)
            sideCounter = 0;
            while (vert < vertices.Length)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;
                float cos = Mathf.Cos(r1);
                float sin = Mathf.Sin(r1);

                vertices[vert] = new Vector3(cos * (topRadius1 - topRadius2 * .5f), height, sin * (topRadius1 - topRadius2 * .5f));
                vertices[vert + 1] = new Vector3(cos * (bottomRadius1 - bottomRadius2 * .5f), 0, sin * (bottomRadius1 - bottomRadius2 * .5f));
                vert += 2;
            }
            #endregion

            #region Normales

            // bottom + top + sides
            Vector3[] normales = new Vector3[vertices.Length];
            vert = 0;

            // Bottom cap
            while (vert < nbVerticesCap)
            {
                normales[vert++] = Vector3.down;
            }

            // Top cap
            while (vert < nbVerticesCap * 2)
            {
                normales[vert++] = Vector3.up;
            }

            // Sides (out)
            sideCounter = 0;
            while (vert < nbVerticesCap * 2 + nbVerticesSides)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;

                normales[vert] = new Vector3(Mathf.Cos(r1), 0f, Mathf.Sin(r1));
                normales[vert + 1] = normales[vert];
                vert += 2;
            }

            // Sides (in)
            sideCounter = 0;
            while (vert < vertices.Length)
            {
                sideCounter = sideCounter == nbSides ? 0 : sideCounter;

                float r1 = (float)(sideCounter++) / nbSides * _2pi;

                normales[vert] = -(new Vector3(Mathf.Cos(r1), 0f, Mathf.Sin(r1)));
                normales[vert + 1] = normales[vert];
                vert += 2;
            }
            #endregion

            #region UVs
            Vector2[] uvs = new Vector2[vertices.Length];

            vert = 0;
            // Bottom cap
            sideCounter = 0;
            while (vert < nbVerticesCap)
            {
                float t = (float)(sideCounter++) / nbSides;
                uvs[vert++] = new Vector2(0f, t);
                uvs[vert++] = new Vector2(1f, t);
            }

            // Top cap
            sideCounter = 0;
            while (vert < nbVerticesCap * 2)
            {
                float t = (float)(sideCounter++) / nbSides;
                uvs[vert++] = new Vector2(0f, t);
                uvs[vert++] = new Vector2(1f, t);
            }

            // Sides (out)
            sideCounter = 0;
            while (vert < nbVerticesCap * 2 + nbVerticesSides)
            {
                float t = (float)(sideCounter++) / nbSides;
                uvs[vert++] = new Vector2(t, 0f);
                uvs[vert++] = new Vector2(t, 1f);
            }

            // Sides (in)
            sideCounter = 0;
            while (vert < vertices.Length)
            {
                float t = (float)(sideCounter++) / nbSides;
                uvs[vert++] = new Vector2(t, 0f);
                uvs[vert++] = new Vector2(t, 1f);
            }
            #endregion

            #region Triangles
            int nbFace = nbSides * 4;
            int nbTriangles = nbFace * 2;
            int nbIndexes = nbTriangles * 3;
            int[] triangles = new int[nbIndexes];

            // Bottom cap
            int i = 0;
            sideCounter = 0;
            while (sideCounter < nbSides)
            {
                int current = sideCounter * 2;
                int next = sideCounter * 2 + 2;

                triangles[i++] = next + 1;
                triangles[i++] = next;
                triangles[i++] = current;

                triangles[i++] = current + 1;
                triangles[i++] = next + 1;
                triangles[i++] = current;

                sideCounter++;
            }

            // Top cap
            while (sideCounter < nbSides * 2)
            {
                int current = sideCounter * 2 + 2;
                int next = sideCounter * 2 + 4;

                triangles[i++] = current;
                triangles[i++] = next;
                triangles[i++] = next + 1;

                triangles[i++] = current;
                triangles[i++] = next + 1;
                triangles[i++] = current + 1;

                sideCounter++;
            }

            // Sides (out)
            while (sideCounter < nbSides * 3)
            {
                int current = sideCounter * 2 + 4;
                int next = sideCounter * 2 + 6;

                triangles[i++] = current;
                triangles[i++] = next;
                triangles[i++] = next + 1;

                triangles[i++] = current;
                triangles[i++] = next + 1;
                triangles[i++] = current + 1;

                sideCounter++;
            }


            // Sides (in)
            while (sideCounter < nbSides * 4)
            {
                int current = sideCounter * 2 + 6;
                int next = sideCounter * 2 + 8;

                triangles[i++] = next + 1;
                triangles[i++] = next;
                triangles[i++] = current;

                triangles[i++] = current + 1;
                triangles[i++] = next + 1;
                triangles[i++] = current;

                sideCounter++;
            }
            #endregion

            mesh.vertices = vertices;
            mesh.normals = normales;
            mesh.uv = uvs;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();

            return mesh;
        }

        private Mesh CreateSphere(float radius, int nbSides)
        {
            Mesh mesh = new Mesh();

            // Longitude |||
            int nbLong = nbSides;
            // Latitude ---
            int nbLat = nbSides;

            #region Vertices
            Vector3[] vertices = new Vector3[(nbLong + 1) * nbLat + 2];
            float _pi = Mathf.PI;
            float _2pi = _pi * 2f;

            vertices[0] = Vector3.up * radius;
            for (int lat = 0; lat < nbLat; lat++)
            {
                float a1 = _pi * (float)(lat + 1) / (nbLat + 1);
                float sin1 = Mathf.Sin(a1);
                float cos1 = Mathf.Cos(a1);

                for (int lon = 0; lon <= nbLong; lon++)
                {
                    float a2 = _2pi * (float)(lon == nbLong ? 0 : lon) / nbLong;
                    float sin2 = Mathf.Sin(a2);
                    float cos2 = Mathf.Cos(a2);

                    vertices[lon + lat * (nbLong + 1) + 1] = new Vector3(sin1 * cos2, cos1, sin1 * sin2) * radius;
                }
            }
            vertices[vertices.Length - 1] = Vector3.up * -radius;
            #endregion

            #region Normales		
            Vector3[] normales = new Vector3[vertices.Length];
            for (int n = 0; n < vertices.Length; n++)
                normales[n] = vertices[n].normalized;
            #endregion

            #region UVs
            Vector2[] uvs = new Vector2[vertices.Length];
            uvs[0] = Vector2.up;
            uvs[uvs.Length - 1] = Vector2.zero;
            for (int lat = 0; lat < nbLat; lat++)
                for (int lon = 0; lon <= nbLong; lon++)
                    uvs[lon + lat * (nbLong + 1) + 1] = new Vector2((float)lon / nbLong, 1f - (float)(lat + 1) / (nbLat + 1));
            #endregion

            #region Triangles
            int nbFaces = vertices.Length;
            int nbTriangles = nbFaces * 2;
            int nbIndexes = nbTriangles * 3;
            int[] triangles = new int[nbIndexes];

            //Top Cap
            int i = 0;
            for (int lon = 0; lon < nbLong; lon++)
            {
                triangles[i++] = lon + 2;
                triangles[i++] = lon + 1;
                triangles[i++] = 0;
            }

            //Middle
            for (int lat = 0; lat < nbLat - 1; lat++)
            {
                for (int lon = 0; lon < nbLong; lon++)
                {
                    int current = lon + lat * (nbLong + 1) + 1;
                    int next = current + nbLong + 1;

                    triangles[i++] = current;
                    triangles[i++] = current + 1;
                    triangles[i++] = next + 1;

                    triangles[i++] = current;
                    triangles[i++] = next + 1;
                    triangles[i++] = next;
                }
            }

            //Bottom Cap
            for (int lon = 0; lon < nbLong; lon++)
            {
                triangles[i++] = vertices.Length - 1;
                triangles[i++] = vertices.Length - (lon + 2) - 1;
                triangles[i++] = vertices.Length - (lon + 1) - 1;
            }
            #endregion

            mesh.vertices = vertices;
            mesh.normals = normales;
            mesh.uv = uvs;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();

            return mesh;
        }

        private Mesh CreateBox(float length, float botradius, float topradius)
        {
            Mesh mesh = new Mesh();

            #region Vertices
            Vector3 p0 = new Vector3(-botradius * .5f, 0, botradius * .5f);
            Vector3 p1 = new Vector3(botradius * .5f, 0, botradius * .5f);
            Vector3 p2 = new Vector3(botradius * .5f, 0, -botradius * .5f);
            Vector3 p3 = new Vector3(-botradius * .5f, 0, -botradius * .5f);

            Vector3 p4 = new Vector3(-topradius * .5f, length, topradius * .5f);
            Vector3 p5 = new Vector3(topradius * .5f, length, topradius * .5f);
            Vector3 p6 = new Vector3(topradius * .5f, length, -topradius * .5f);
            Vector3 p7 = new Vector3(-topradius * .5f, length, -topradius * .5f);

            Vector3[] vertices = new Vector3[]
            {
            // Bottom
            p0, p1, p2, p3,
 
	        // Left
	        p7, p4, p0, p3,
 
        	// Front
	        p4, p5, p1, p0,
 
	        // Back
	        p6, p7, p3, p2,
 
	        // Right
	        p5, p6, p2, p1,
 
	        // Top
	        p7, p6, p5, p4
            };
            #endregion

            #region UVs
            Vector2 _00 = new Vector2(0f, 0f);
            Vector2 _10 = new Vector2(1f, 0f);
            Vector2 _01 = new Vector2(0f, 1f);
            Vector2 _11 = new Vector2(1f, 1f);

            Vector2[] uvs = new Vector2[]
            {
	        // Bottom
	        _11, _01, _00, _10,
 
	        // Left
        	_11, _01, _00, _10,
 
	        // Front
	        _11, _01, _00, _10,
 
	        // Back
        	_11, _01, _00, _10,
 
	        // Right
        	_11, _01, _00, _10,
 
	        // Top
	        _11, _01, _00, _10,
            };
            #endregion

            #region Triangles
            int[] triangles = new int[]
            {
	        // Bottom
	        3, 1, 0,
            3, 2, 1,			
 
	        // Left
	        3 + 4 * 1, 1 + 4 * 1, 0 + 4 * 1,
            3 + 4 * 1, 2 + 4 * 1, 1 + 4 * 1,
 
	        // Front
        	3 + 4 * 2, 1 + 4 * 2, 0 + 4 * 2,
            3 + 4 * 2, 2 + 4 * 2, 1 + 4 * 2,
 
	        // Back
        	3 + 4 * 3, 1 + 4 * 3, 0 + 4 * 3,
            3 + 4 * 3, 2 + 4 * 3, 1 + 4 * 3,
 
	        // Right
	        3 + 4 * 4, 1 + 4 * 4, 0 + 4 * 4,
            3 + 4 * 4, 2 + 4 * 4, 1 + 4 * 4,
 
	        // Top
	        3 + 4 * 5, 1 + 4 * 5, 0 + 4 * 5,
            3 + 4 * 5, 2 + 4 * 5, 1 + 4 * 5,
            };
            #endregion

            mesh.vertices = vertices;
            mesh.uv = uvs;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();
            mesh.RecalculateNormals();

            return mesh;
        }

        private Mesh CreateCircle(float radius, int nbSides)
        {
            Mesh mesh = new Mesh();

            #region Vertices

            Vector3[] vertices = new Vector3[(nbSides + 1) * 2];
            int index = 0;
            float angleInc = 360 / nbSides;
            while (index < vertices.Length)
            {
                vertices[index++] = new Vector3(0, 0, 0);
                for (float a = 0; a < 360; a += angleInc)
                {
                    float x = 0;
                    float y = Mathf.Sin(Mathf.Deg2Rad * a) * radius;
                    float z = Mathf.Cos(Mathf.Deg2Rad * a) * radius;
                    vertices[index++] = new Vector3(x, y, z);
                }
            }
            #endregion

            #region Normales

            Vector3[] normales = new Vector3[vertices.Length];
            Vector3 left = Vector3.left;
            Vector3 right = Vector3.right;

            for (var i = 0; i < normales.Length; i++)
                normales[i] = (i < normales.Length / 2) ? left : right;

            #endregion

            #region Triangles

            int[] triangles = new int[(nbSides * 3 + 3) * 2];
            index = 0;
            int indexV = 0;

            for (indexV = 0; indexV + 1 < vertices.Length / 2; indexV++)
            {
                triangles[index++] = 0;
                triangles[index++] = indexV + 1;
                triangles[index++] = (indexV + 2 < vertices.Length / 2) ? (indexV + 2) : 1;
            }
            indexV++;
            while (indexV + 1 < vertices.Length)
            {
                triangles[index++] = nbSides + 1;
                triangles[index++] = (indexV + 2 < vertices.Length) ? (indexV + 2) : nbSides + 2;
                triangles[index++] = indexV + 1;
                indexV++;
            }

            #endregion

            mesh.vertices = vertices;
            mesh.normals = normales;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();

            return mesh;
        }

        private Mesh CreateQuad(float length, float botradius, float topradius)
        {
            Mesh mesh = new Mesh();

            #region Vertices
            Vector3 p0 = new Vector3(0, 0, -botradius);
            Vector3 p1 = new Vector3(0, 0, botradius);
            Vector3 p2 = new Vector3(0, length, topradius);
            Vector3 p3 = new Vector3(0, length, -topradius);

            Vector3[] vertices = new Vector3[]
            {
            p0, p1, p2, p3,

            p0, p1, p2, p3,
            };
            #endregion

            #region Normales
            Vector3 left = Vector3.left;
            Vector3 right = Vector3.right;

            Vector3[] normales = new Vector3[]
            {
            right, right, right, right,

            left, left, left, left
            };
            #endregion

            #region UVs
            Vector2 _00 = new Vector2(0f, 0f);
            Vector2 _10 = new Vector2(1f, 0f);
            Vector2 _01 = new Vector2(0f, 1f);
            Vector2 _11 = new Vector2(1f, 1f);

            Vector2[] uvs = new Vector2[]
            {
	        // Top
	        _11, _01, _00, _10,

	        // Bottom
	        _11, _01, _00, _10,
            };
            #endregion

            #region Triangles
            int[] triangles = new int[]
            {
	        // Top
	        3, 1, 0,
            3, 2, 1,

	        // Bottom
            3 + 4, 0 + 4, 1 + 4,
            3 + 4, 1 + 4, 2 + 4,
            };
            #endregion

            mesh.vertices = vertices;
            mesh.normals = normales;
            mesh.uv = uvs;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();

            return mesh;
        }

        private Mesh CreatePolygon(LpyStructAndType.LpyVector3[] points, bool concavetest)
        {
            Mesh mesh = new Mesh();

            #region Vec3ToVec2
            Vector3[] vertices3d = new Vector3[points.Length];
            for (var i = 0; i < points.Length; i++)
            {
                vertices3d[i] = new Vector3(points[i].x, points[i].y, points[i].z);
                Debug.Log(vertices3d[i]);
            }
            Vector2[] vertices2d = new Vector2[points.Length];

            Vector3 firstPoint = vertices3d[0];
            Vector3 takenVec;
            int index = 1;

            do
            {
                if (index >= points.Length)
                    return null;
                takenVec = vertices3d[index++];
            } while (takenVec == firstPoint);

            Vector3 normal = Vector3.Cross(firstPoint, takenVec);
            Vector3 bound = Vector3.Cross(firstPoint, normal);

            for (var i = 0; i < vertices3d.Length; i++)
            {
                vertices2d[i].x = Vector3.Dot(firstPoint, vertices3d[i]);
                vertices3d[i].y = Vector3.Dot(bound, vertices3d[i]);
            }

            #endregion

            Vector3[] vertices = null;
            int[] triangles = null;

            if (concavetest)
            {
                Triangulator tr = new Triangulator(vertices2d);
                triangles = tr.Triangulate();

                vertices = new Vector3[vertices2d.Length];
                for (int i = 0; i < vertices.Length; i++)
                {
                    vertices[i] = new Vector3(vertices2d[i].x, vertices2d[i].y, 0);
                }
            }

            mesh.vertices = vertices;
            mesh.triangles = triangles;

            mesh.RecalculateBounds();
            mesh.RecalculateNormals();

            return mesh;
        }
#endregion

        private static void MarshalUnmananagedArray2Struct<T>(IntPtr unmanagedArray, int length, out T[] mangagedArray)
        {
            var size = Marshal.SizeOf(typeof(T));
            mangagedArray = new T[length];

            for (int i = 0; i < length; i++)
            {
                IntPtr ins = new IntPtr(unmanagedArray.ToInt64() + i * size);
                mangagedArray[i] = (T)Marshal.PtrToStructure(ins, typeof(T));
            }
        }

        private static unsafe Quaternion MatrixToQuaternionRotation(LpyStructAndType.LpyMatrix4 matrix)
        {
            Vector4[] vec = new Vector4[4];

            vec[0] = new Vector4(matrix.column1[0], matrix.column1[1], matrix.column1[2], matrix.column1[3]);
            vec[1] = new Vector4(matrix.column2[0], matrix.column2[1], matrix.column2[2], matrix.column2[3]);
            vec[2] = new Vector4(matrix.column3[0], matrix.column3[1], matrix.column3[2], matrix.column3[3]);
            vec[3] = new Vector4(matrix.column4[0], matrix.column4[1], matrix.column4[2], matrix.column4[3]);

            Matrix4x4 mat = new Matrix4x4(vec[0], vec[1], vec[2], vec[3]);

            Quaternion rotation = new Quaternion();
            rotation.SetLookRotation(mat.GetColumn(2), mat.GetColumn(1));
            return rotation;
        }

        private static LpyStructAndType.LpyGeometryInfo GetGeometryInformation(LpyStructAndType.LpyGeometryInfoPtr info)
        {
            LpyStructAndType.LpyGeometryInfo newInfo = new LpyStructAndType.LpyGeometryInfo();

            MarshalUnmananagedArray2Struct(info.triangles, info.triangleSize, out newInfo.triangles);
            
            return newInfo;
        }

        public LpyUnity(GameObject parent, List<Material> materials, List<GameObject> surfaces)
        {
            this._parent = parent;
            this._materials = materials;
            this._surfaces = surfaces;

#if UNITY_EDITOR
            if (nativeLibraryPtr == IntPtr.Zero)
            {
                nativeLibraryPtr = Native.LoadLibrary("Lpy_Windows");
                if (nativeLibraryPtr == IntPtr.Zero)
                {
                    Debug.LogError("Failed to load native library");
                }
            }
#endif

            this._makeSphere =
                (LpyStructAndType.LpyVector3 pos, float radius, int resolution, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateSphere(radius, resolution);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeCylinder =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, float radius, float length, int resolution, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateCylinder(radius, length, resolution);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeCone =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, float radius, float topradius, float length, int resolution, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateCone(radius, topradius, length, resolution);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeBox =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, float length, float botradius, float topradius, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateBox(length, botradius, topradius);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeCircle =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, float radius, int resolution, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateCircle(radius, resolution);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeQuad =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, float length, float botradius, float topradius, int color) =>
                {
                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreateQuad(length, botradius, topradius);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeSurface =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, string name, float scale, int color) =>
                 {
                     GameObject find = null;

                     foreach (var s in this._surfaces)
                     {
                         if (s.name == name)
                         {
                             find = s;
                             break;
                         }
                     }

                     if (find != null)
                     {
                         var go = GameObject.Instantiate(find);
                         go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                         go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                         go.transform.localScale = new Vector3(scale, scale, scale);
                         go.transform.parent = this._parent.transform;

                         go.SetActive(false);
                         this._tree.Add(go);
                     }
                 };

            this._makePolygon =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, IntPtr points, int size, bool concavetest, int color) =>
                {
                    LpyStructAndType.LpyVector3[] pots = null;
                    MarshalUnmananagedArray2Struct(points, size, out pots);

                    var go = new GameObject();

                    MeshFilter meshFilter = go.AddComponent<MeshFilter>();
                    meshFilter.mesh = CreatePolygon(pots, concavetest);

                    MeshRenderer renderer = go.AddComponent<MeshRenderer>();
                    renderer.sharedMaterial = this._materials[color];

                    go.transform.position = new Vector3(pos.x, pos.y, pos.z);
                    go.transform.localRotation = MatrixToQuaternionRotation(rotMatrix);
                    go.transform.parent = this._parent.transform;

                    go.SetActive(false);
                    this._tree.Add(go);
                };

            this._makeGeneralizedGeometry =
                (LpyStructAndType.LpyVector3 pos, LpyStructAndType.LpyMatrix4 rotMatrix, LpyStructAndType.LpyGeometryInfoPtr info) =>
                {
                    LpyStructAndType.LpyGeometryInfo geoInfo = GetGeometryInformation(info);

                    foreach (var t in geoInfo.triangles)
                    {
                        Debug.Log("Triangle 1 : Postion x = " + t.point1.x);
                        Debug.Log("Triangle 1 : Postion y = " + t.point1.y);
                        Debug.Log("Triangle 1 : Postion z = " + t.point1.x);

                        Debug.Log("Triangle 2 : Postion x = " + t.point2.x);
                        Debug.Log("Triangle 2 : Postion y = " + t.point2.y);
                        Debug.Log("Triangle 2 : Postion z = " + t.point2.z);

                        Debug.Log("Triangle 3 : Postion x = " + t.point3.x);
                        Debug.Log("Triangle 3 : Postion y = " + t.point3.y);
                        Debug.Log("Triangle 3 : Postion z = " + t.point3.z);
                    }
                };

            this._debug =
                (string str) =>
                {
                    Debug.Log(str);
                };

            this._warning =
                (string str) =>
                {
                    Debug.LogWarning(str);
                };

            this._error =
                (string str) =>
                {
                    Debug.LogError(str);
                };

#if UNITY_EDITOR
            Native.Invoke<LpyStructAndType.SetMakeCylinder>(nativeLibraryPtr, this._makeCylinder);
            Native.Invoke<LpyStructAndType.SetMakeCone>(nativeLibraryPtr, this._makeCone);
            Native.Invoke<LpyStructAndType.SetMakeSphere>(nativeLibraryPtr, this._makeSphere);
            Native.Invoke<LpyStructAndType.SetMakeBox>(nativeLibraryPtr, this._makeBox);
            Native.Invoke<LpyStructAndType.SetMakeCircle>(nativeLibraryPtr, this._makeCircle);
            Native.Invoke<LpyStructAndType.SetMakeQuad>(nativeLibraryPtr, this._makeQuad);
            Native.Invoke<LpyStructAndType.SetMakeSurface>(nativeLibraryPtr, this._makeSurface);
            Native.Invoke<LpyStructAndType.SetMakePolygon>(nativeLibraryPtr, this._makePolygon);
            Native.Invoke<LpyStructAndType.SetMakeGeneralizedGeometry>(nativeLibraryPtr, this._makeGeneralizedGeometry);

            Native.Invoke<LpyStructAndType.SetColorListSize>(nativeLibraryPtr, this._materials.Count);

            Native.Invoke<LpyStructAndType.SetDebug>(nativeLibraryPtr, this._debug);
            Native.Invoke<LpyStructAndType.SetWarning>(nativeLibraryPtr, this._warning);
            Native.Invoke<LpyStructAndType.SetError>(nativeLibraryPtr, this._error);
#else
            LpyStructAndType.SetMakeCylinder(this._makeCylinder);
            LpyStructAndType.SetMakeCone(this._makeCone);
            LpyStructAndType.SetMakeSphere(this._makeSphere);
            LpyStructAndType.SetMakeBox(this._makeBox);
            LpyStructAndType.SetMakeCircle(this._makeCircle);
            LpyStructAndType.SetMakeQuad(this._makeQuad);
            LpyStructAndType.SetMakeSurface(this._makeSurface);
            LpyStructAndType.SetMakePolygon(this._makePolygon);
            LpyStructAndType.SetMakeGeneralizedGeometry(this._makeGeneralizedGeometry);

            LpyStructAndType.SetColorListSize(this._materials.Count);

            LpyStructAndType.SetDebug(this._debug);
            LpyStructAndType.SetWarning(this._warning);
            LpyStructAndType.SetError(this._error);
#endif
        }

        ~LpyUnity()
        {
#if UNITY_EDITOR
            if (nativeLibraryPtr == IntPtr.Zero) return;

            Debug.Log(Native.FreeLibrary(nativeLibraryPtr)
                          ? "Native library successfully unloaded."
                          : "Native library could not be unloaded.");
#endif
        }

        public List<GameObject> Interpret(string lstring)
        {
            this._tree = new List<GameObject>();
#if UNITY_EDITOR
            Native.Invoke<LpyStructAndType.Interpret_LString>(nativeLibraryPtr, lstring);
#else
            LpyStructAndType.Interpret_LString(lstring);
#endif
            return this._tree;
        }
    }
}