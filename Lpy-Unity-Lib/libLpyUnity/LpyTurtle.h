#include <Python.h>
#include "UnityTurtle.h"
#include "Debug.h"
#include "ModuleParam.h"

struct PythonInitializer
{
	PythonInitializer()
	{
		Py_Initialize();
	}

	~PythonInitializer()
	{
		Py_Finalize();
	}
};

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

	DLL int GetDerivationLenght();

	DLL void AddModuleAt(unsigned int pos, char *name, ModuleParam::ParamInfo *infos, int len);
	DLL void AppendModule(char *name, ModuleParam::ParamInfo *infos, int len);
	DLL int GetFirstParamModuleAt(unsigned int pos);
	DLL int GetThirdParamModuleAt(unsigned int pos);
	DLL char *GetNameModuleAt(unsigned int pos);
	DLL void ChangeParamsModuleAt(unsigned int pos, ModuleParam::ParamInfo *infos, int len);

	DLL void Interpret_LString(char *lstring);
	DLL void Interpret(int interation);
	DLL void StartInterpretFile(char *filename);
	DLL void StopInterpretFile();
	DLL void ResetAxialTree();

	DLL void SetDebug(WriteCallback callback);
	DLL void SetWarning(WriteCallback callback);
	DLL void SetError(WriteCallback callback);
}