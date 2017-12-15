#ifndef UNITY_TURTLE_H_
#define UNITY_TURTLE_H_

#include <plantgl/algo/modelling/turtle.h>
#include <plantgl/scenegraph/geometry/triangleset.h>

#ifndef _WIN32
#define __stdcall
#endif

struct Vector3 {
	real_t x;
	real_t y;
	real_t z;
};

struct Matrix4 {
	real_t column1[4];
	real_t column2[4];
	real_t column3[4];
	real_t column4[4];
};

struct Triangle
{
	Vector3 points[3];
};

struct GeometryInfo
{
	int triangleSize;
	Triangle *triangles;
};

class UnityTurtle : public PGL::Turtle
{
public:
	typedef void(__stdcall *MakeCylinder)(Vector3, Matrix4, real_t, real_t, int, int, unsigned);
	typedef void(__stdcall *MakeCone)(Vector3, Matrix4, real_t, real_t, real_t, int, int, unsigned);
	typedef void(__stdcall *MakeSphere)(Vector3, real_t, int, int, unsigned);
	typedef void(__stdcall *MakeBox)(Vector3, Matrix4, real_t, real_t, real_t, int, unsigned);

	typedef void(__stdcall *MakeCircle)(Vector3, Matrix4, real_t, int, int, unsigned);
	typedef void(__stdcall *MakeQuad)(Vector3, Matrix4, real_t, real_t, real_t, int, unsigned);

	typedef void(__stdcall *MakeSurface)(Vector3, Matrix4, char *, real_t, int, unsigned);
	typedef void(__stdcall *MakePolygon)(Vector3, Matrix4, Vector3 *, int, bool, int, unsigned);

	typedef void(__stdcall *MakeGeneralizedGeometry)(Vector3, Matrix4, GeometryInfo, unsigned);

private:
	static void getTriangles(PGL::TriangleSetPtr model, GeometryInfo &info);
	static GeometryInfo getGeometryInfoOfExtrusion(std::shared_ptr<PGL::Extrusion> extrusion);

private:
	int _colorListSize;

	MakeCylinder _cylinderCallback;
	MakeCone _coneCallback;
	MakeSphere _sphereCallback;
	MakeBox _boxCallback;

	MakeCircle _circleCallback;
	MakeQuad _quadCallback;

	MakeSurface _surfaceCallback;
	MakePolygon _polygonCallback;

	MakeGeneralizedGeometry _generalizedGeometryCallback;

public:
	UnityTurtle(PGL::TurtleParam *param = nullptr);
	virtual ~UnityTurtle();

	inline void setMakeCylinder(MakeCylinder callback)
	{ this->_cylinderCallback = callback; }

	inline void setMakeCone(MakeCone callback)
	{ this->_coneCallback = callback; }
	
	inline void setMakeSphere(MakeSphere callback)
	{ this->_sphereCallback = callback; }

	inline void setMakeBox(MakeBox callback)
	{ this->_boxCallback = callback; }

	inline void setMakeCircle(MakeCircle callback)
	{ this->_circleCallback = callback; }

	inline void setMakeQuad(MakeQuad callback)
	{ this->_quadCallback = callback; }

	inline void setMakeSurface(MakeSurface callback)
	{ this->_surfaceCallback = callback; }

	inline void setMakePolygon(MakePolygon callback)
	{ this->_polygonCallback = callback; }

	inline void setMakeGeneralizedGeometry(MakeGeneralizedGeometry callback)
	{ this->_generalizedGeometryCallback = callback; }

	inline void setColorListSize(int size)
	{ this->_colorListSize = size; }

	virtual size_t getColorListSize() const;

protected:
	virtual void _frustum(real_t length, real_t topradius);
	virtual void _cylinder(real_t length);

	virtual void _polygon(const PGL::Point3ArrayPtr& points, bool concavetest = false);

	virtual void _generalizedCylinder(const PGL::Point3ArrayPtr& points,
		const std::vector<TOOLS(Vector3)>& leftList,
		const std::vector<real_t>& radiusList,
		const PGL::Curve2DPtr& crossSection,
		bool crossSectionCCW,
		bool currentcolor = false);

	virtual void _sphere(real_t radius);

	virtual void _circle(real_t radius);

	virtual void _box(real_t length, real_t botradius, real_t topradius);

	virtual void _quad(real_t length, real_t botradius, real_t topradius);

	virtual void _surface(const std::string& name, real_t scale);

	virtual void _frame(real_t heigth, real_t cap_heigth_ratio, real_t cap_radius_ratio, real_t color, real_t transparency);

	virtual void _label(const std::string& text, int size = -1);
};

#endif