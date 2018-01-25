#include <string>
#include <memory>
#include <plantgl/math/util_math.h>
#include <plantgl/scenegraph/geometry/lineicmodel.h>
#include <plantgl/scenegraph/geometry/polyline.h>
#include <plantgl/scenegraph/geometry/curve.h>
#include <plantgl/scenegraph/geometry/extrusion.h>
#include <plantgl/scenegraph/container/pointarray.h>
#include <plantgl/algo/base/tesselator.h>
#include <plantgl/tool/util_tuple.h>
#include "UnityTurtle.h"
#include "Debug.h"

UnityTurtle::UnityTurtle(PGL::TurtleParam *param) :
	PGL::Turtle(param),
	_colorListSize(0),
	_cylinderCallback(nullptr),
	_coneCallback(nullptr),
	_sphereCallback(nullptr),
	_boxCallback(nullptr),
	_circleCallback(nullptr),
	_quadCallback(nullptr),
	_surfaceCallback(nullptr),
	_polygonCallback(nullptr),
	_generalizedGeometryCallback(nullptr)
{
	this->register_warning_handler(Warning);
	this->register_error_handler(Error);
}

UnityTurtle::~UnityTurtle()
{}

void UnityTurtle::getTriangles(PGL::TriangleSetPtr model, GeometryInfo &info)
{
	info.triangleSize = model->getIndexListSize();
	info.triangles = new Triangle[info.triangleSize];
	int index = 0;

	for (auto it = model->getIndexList()->begin(); it != model->getIndexList()->end(); ++it)
	{
		for (auto i = 0; i < 3; i++)
		{
			info.triangles[index].points[i].x = model->getPointAt(it->getAt(i)).y();
			info.triangles[index].points[i].y = model->getPointAt(it->getAt(i)).z();
			info.triangles[index].points[i].z = model->getPointAt(it->getAt(i)).x();
		}
		index++;
	}
}

GeometryInfo UnityTurtle::getGeometryInfoOfExtrusion(std::shared_ptr<PGL::Extrusion> extrusion)
{
	GeometryInfo info;
	PGL::Tesselator t;
	extrusion->apply(t);

	auto model = t.getTriangulation();
	UnityTurtle::getTriangles(model, info);

	return info;
}

Matrix4 UnityTurtle::getCurrentRotationMatrix()
{
	auto data = this->__params->getOrientationMatrix().getData();
	/*Matrix4 rotMatrix = {
		{ data[0], -data[1], data[2], 0 },
		{ data[3], -data[4], data[5], 0 },
		{ data[6], -data[7], data[8], 0 },
		{ 0, 0, 0, 0 },
	};*/
	Matrix4 rotMatrix = {
		{ data[0], -data[1], data[2], 0 },
		{ data[3], -data[4], data[5], 0 },
		{ data[6], -data[7], data[8], 0 },
		{ 0, 0, 0, 0 },
	};
	/*
	Debug("Lib Matrix4 1: (" +
		std::to_string(rotMatrix.column1[0]) + ", " +
		std::to_string(rotMatrix.column1[1]) + ", " +
		std::to_string(rotMatrix.column1[2]) + ", " +
		std::to_string(rotMatrix.column1[3]) + ")");
	Debug("Lib Matrix4 2: (" +
		std::to_string(rotMatrix.column2[0]) + ", " +
		std::to_string(rotMatrix.column2[1]) + ", " +
		std::to_string(rotMatrix.column2[2]) + ", " +
		std::to_string(rotMatrix.column2[3]) + ")");
	Debug("Lib Matrix4 3: (" +
		std::to_string(rotMatrix.column3[0]) + ", " +
		std::to_string(rotMatrix.column3[1]) + ", " +
		std::to_string(rotMatrix.column3[2]) + ", " +
		std::to_string(rotMatrix.column3[3]) + ")");
	Debug("Lib Matrix4 4: (" +
		std::to_string(rotMatrix.column4[0]) + ", " +
		std::to_string(rotMatrix.column4[1]) + ", " +
		std::to_string(rotMatrix.column4[2]) + ", " +
		std::to_string(rotMatrix.column4[3]) + ")");
		*/
	return rotMatrix;
}

Vector3 UnityTurtle::getCurrentPosition()
{
	Vector3 pos = {
		this->__params->position.y(),
		this->__params->position.z(),
		this->__params->position.x()
	};
	return pos;
}

size_t UnityTurtle::getColorListSize() const
{
	return this->_colorListSize;
}

void UnityTurtle::_frustum(real_t length, real_t topradius)
{
	if (this->_coneCallback)
		this->_coneCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			this->getWidth(),
			topradius,
			length,
			this->__params->sectionResolution,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_cylinder(real_t length)
{
	if (this->_cylinderCallback)
		this->_cylinderCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			this->getWidth(),
			length,
			this->__params->sectionResolution,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_polygon(const PGL::Point3ArrayPtr& points, bool concavetest)
{
	Vector3 *vec = new Vector3[points->getSize()];
	int index = 0;

	for (auto it = points->begin(); it != points->end(); ++it)
	{
		std::string str = "";
		str += "x = " + std::to_string(it->x()) + " ";
		str += "y = " + std::to_string(it->y()) + " ";
		str += "z = " + std::to_string(it->z());

		Debug(str);

		vec[index++] = { it->x(), it->y(), it->z() };
	}

	if (this->_polygonCallback)
		this->_polygonCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			vec, points->getSize(),
			concavetest,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_generalizedCylinder(const PGL::Point3ArrayPtr& points,
	const std::vector<TOOLS(Vector3)>& leftList,
	const std::vector<real_t>& radiusList,
	const PGL::Curve2DPtr& crossSection,
	bool crossSectionCCW,
	bool currentcolor)
{
	if (points->size() == 2 && norm(points->getAt(0) - points->getAt(1)) < GEOM_EPSILON) return;
	PGL::LineicModelPtr axis = PGL::LineicModelPtr(new PGL::Polyline(PGL::Point3ArrayPtr(
		new PGL::Point3Array(*points))));
	PGL::Point2ArrayPtr radius(new PGL::Point2Array(radiusList.size()));
	PGL::Point2Array::iterator it2 = radius->begin();
	for (std::vector<real_t>::const_iterator it = radiusList.begin();
		it != radiusList.end(); it++) {
		*it2 = TOOLS::Vector2(*it, *it); it2++;
	}
	PGL::Curve2DPtr mcrossSection = crossSection;
	if (!mcrossSection) {
		mcrossSection = PGL::Curve2DPtr(PGL::Polyline2D::Circle(1, __params->sectionResolution));
		crossSectionCCW = true;
		// error("Invalid cross section");
	}
	assert(mcrossSection);
	std::shared_ptr<PGL::Extrusion> extrusion = std::make_shared<PGL::Extrusion> (axis, mcrossSection, radius);
	extrusion->getCCW() = crossSectionCCW;
	extrusion->getInitialNormal() = leftList[0];

	if (this->_generalizedGeometryCallback)
		this->_generalizedGeometryCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			UnityTurtle::getGeometryInfoOfExtrusion(extrusion),
			this->popId());
}

void UnityTurtle::_sphere(real_t radius)
{
	if (this->_cylinderCallback)
		this->_sphereCallback(this->getCurrentPosition(),
			radius,
			this->__params->sectionResolution,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_circle(real_t radius)
{
	if (this->_circleCallback)
		this->_circleCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			radius,
			this->__params->sectionResolution,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_box(real_t length, real_t botradius, real_t topradius)
{
	if (this->_boxCallback)
		this->_boxCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			length,
			botradius,
			topradius,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_quad(real_t length, real_t botradius, real_t topradius)
{
	if (this->_quadCallback)
		this->_quadCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			length,
			botradius,
			topradius,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_surface(const std::string& name, real_t scale)
{
	if (this->_surfaceCallback)
		this->_surfaceCallback(this->getCurrentPosition(),
			this->getCurrentRotationMatrix(),
			const_cast<char *> (name.c_str()),
			scale,
			this->__params->color,
			this->popId());
}

void UnityTurtle::_frame(real_t heigth, real_t cap_heigth_ratio, real_t cap_radius_ratio, real_t color, real_t transparency)
{
	std::string str;

	str += "In _frame with param : \n";
	str += "\t heigth = " + std::to_string(heigth) + "\n";
	str += "\t cap_heigth_ratio = " + std::to_string(cap_heigth_ratio) + "\n";
	str += "\t cap_radius_ratio = " + std::to_string(cap_radius_ratio) + "\n";
	str += "\t color = " + std::to_string(color) + "\n";
	str += "\t transparency = " + std::to_string(transparency);

	Debug(str);
}

void UnityTurtle::_label(const std::string& text, int size)
{
	std::string str;

	str += "In _label with param : \n";
	str += "\t text = " + text + "\n";
	str += "\t size = " + std::to_string(size);
	Debug(str);
}