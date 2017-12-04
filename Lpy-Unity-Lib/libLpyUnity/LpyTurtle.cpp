#include <memory>
#include "LpyTurtle.h"

WriteCallback DebugCallback = nullptr;
WriteCallback WarningCallback = nullptr;
WriteCallback ErrorCallback = nullptr;
std::shared_ptr<UnityTurtle> turtle = std::make_shared<UnityTurtle> ();

void Debug(const std::string &str)
{
	if (DebugCallback)
		DebugCallback((char *)str.c_str());
}

void Warning(const std::string &str)
{
	if (WarningCallback)
		WarningCallback((char *)str.c_str());
}

void Error(const std::string &str)
{
	if (ErrorCallback)
		ErrorCallback((char *)str.c_str());
}

DLL void SetMakeCylinder(UnityTurtle::MakeCylinder callback)
{
	turtle->setMakeCylinder(callback);
}

DLL void SetMakeCone(UnityTurtle::MakeCone callback)
{
	turtle->setMakeCone(callback);
}

DLL void SetMakeSphere(UnityTurtle::MakeSphere callback)
{
	turtle->setMakeSphere(callback);
}

DLL void SetMakeBox(UnityTurtle::MakeBox callback)
{
	turtle->setMakeBox(callback);
}

DLL void SetMakeCircle(UnityTurtle::MakeCircle callback)
{
	turtle->setMakeCircle(callback);
}

DLL void SetMakeQuad(UnityTurtle::MakeQuad callback)
{
	turtle->setMakeQuad(callback);
}

DLL void SetMakeSurface(UnityTurtle::MakeSurface callback)
{
	turtle->setMakeSurface(callback);
}

DLL void SetMakePolygon(UnityTurtle::MakePolygon callback)
{
	turtle->setMakePolygon(callback);
}

DLL void SetMakeGeneralizedGeometry(UnityTurtle::MakeGeneralizedGeometry callback)
{
	turtle->setMakeGeneralizedGeometry(callback);
}

DLL void SetDebug(WriteCallback callback)
{
	DebugCallback = callback;
}

DLL void SetWarning(WriteCallback callback)
{
	WarningCallback = callback;
}

DLL void SetError(WriteCallback callback)
{
	ErrorCallback = callback;
}

DLL void SetColorListSize(int size)
{
	turtle->setColorListSize(size);
}

DLL void Interpret_LString(char *lstring)
{
	Debug(lstring);
	std::string lstr(lstring);
	
	turtle->start();
	turtle->setAngleIncrement(90);
	for (auto s : lstr)
	{
		switch (s)
		{
		case 'F':
			turtle->F();
			break;
		case 'f':
			turtle->f();
			break;
		case '{':
			turtle->startPolygon();
			break;
		case '}':
			turtle->stopPolygon();
			break;
		case '.':
			turtle->polygonPoint();
			break;
		case '+':
			turtle->right();
			break;
		case '-':
			turtle->left();
			break;
		case '[':
			turtle->push();
			break;
		case ']':
			turtle->pop();
			break;
		case ';':
			turtle->incColor();
			break;
		case ':':
			turtle->decColor();
			break;
		default:
			break;
		}
	}

	turtle->startGC();

	turtle->stop();
	
	/*
	turtle->start();
	turtle->startPolygon();

	turtle->polygonPoint();

	turtle.right();
	turtle.f();
	turtle.polygonPoint();

	turtle.right();
	turtle.f();
	turtle.polygonPoint();

	turtle.stopPolygon();
	
	turtle->stop();
	*/
}