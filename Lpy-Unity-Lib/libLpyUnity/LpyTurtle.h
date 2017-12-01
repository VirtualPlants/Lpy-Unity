#include "UnityTurtle.h"
#include "Debug.h"

extern "C"
{
#ifdef _WIN32
#define DLL __declspec(dllexport)
#else
#define DLL
#endif

	DLL void SetMakeCylinder(UnityTurtle::MakeCylinder callback);
	DLL void SetMakeCone(UnityTurtle::MakeCone callback);
	DLL void SetMakeSphere(UnityTurtle::MakeSphere callback);
	DLL void SetMakeBox(UnityTurtle::MakeBox callback);

	DLL void SetMakeQuad(UnityTurtle::MakeQuad callback);
	DLL void SetMakeCircle(UnityTurtle::MakeCircle callback);

	DLL void SetMakeSurface(UnityTurtle::MakeSurface callback);
	DLL void SetMakePolygon(UnityTurtle::MakePolygon callback);

	DLL void SetMakeGeneralizedGeometry(UnityTurtle::MakeGeneralizedGeometry callback);

	DLL void SetColorListSize(int size);

	DLL void Interpret_LString(char *lstring);

	DLL void SetDebug(WriteCallback callback);
	DLL void SetWarning(WriteCallback callback);
	DLL void SetError(WriteCallback callback);
}