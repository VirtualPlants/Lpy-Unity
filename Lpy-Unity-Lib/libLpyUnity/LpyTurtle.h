#include <Python.h>
#include <axialtree.h>
#include <lsystem.h>
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

struct TreeInformations
{
	TreeInformations() : interpretTree(nullptr)
	{
		this->turtle = std::make_shared<UnityTurtle>();
	}

	unsigned long fileid;
	LPY::AxialTree currentTree;
	std::shared_ptr<LPY::AxialTree> interpretTree;
	std::shared_ptr<UnityTurtle> turtle;
};

struct Rule
{
	Rule(const unsigned long &_fileid, const std::string &filename)
		: lsystem(filename), fileid(_fileid)
	{}
	Rule(const Rule &rule)
		: lsystem(rule.lsystem.getFilename()), fileid(rule.fileid)
	{}

	LPY::Lsystem lsystem;
	unsigned long fileid;
};

extern "C"
{
#ifdef _WIN32
#define DLL __declspec(dllexport)
#else
#define DLL
#endif
	DLL void SetMakeCylinder(unsigned long treeid, UnityTurtle::MakeCylinder callback);
	DLL void SetMakeCone(unsigned long treeid, UnityTurtle::MakeCone callback);
	DLL void SetMakeSphere(unsigned long treeid, UnityTurtle::MakeSphere callback);
	DLL void SetMakeBox(unsigned long treeid, UnityTurtle::MakeBox callback);

	DLL void SetMakeQuad(unsigned long treeid, UnityTurtle::MakeQuad callback);
	DLL void SetMakeCircle(unsigned long treeid, UnityTurtle::MakeCircle callback);

	DLL void SetMakeSurface(unsigned long treeid, UnityTurtle::MakeSurface callback);
	DLL void SetMakePolygon(unsigned long treeid, UnityTurtle::MakePolygon callback);

	DLL void SetMakeGeneralizedGeometry(unsigned long treeid, UnityTurtle::MakeGeneralizedGeometry callback);

	DLL void SetColorListSize(int size);

	DLL int GetDerivationLenght(unsigned long treeId);

	DLL void AddModuleAt(unsigned long treeId, unsigned int pos, char *name, ModuleParam::ParamInfo *infos, int len);
	DLL void AppendModule(unsigned long treeId, char *name, ModuleParam::ParamInfo *infos, int len);
	DLL int GetFirstParamModuleAt(unsigned long treeId, unsigned int pos);
	DLL int GetSecondParamModuleAt(unsigned long treeId, unsigned int pos);
	DLL int GetThirdParamModuleAt(unsigned long treeId, unsigned int pos);
	DLL char *GetNameModuleAt(unsigned long treeId, unsigned int pos);
	DLL void ChangeParamsModuleAt(unsigned long treeId, unsigned int pos, ModuleParam::ParamInfo *infos, int len);

	DLL void Interpret(unsigned long treeId, int iteration);
	DLL void ResetAxialTree(unsigned long treeId);

	DLL void AddNewTree(unsigned long treeid, unsigned long fileid);
	DLL void AddInterpretFile(char *filename, unsigned long fileid);

	DLL void PrintLstring(unsigned long treeId);
	DLL void SetDebug(WriteCallback callback);
	DLL void SetWarning(WriteCallback callback);
	DLL void SetError(WriteCallback callback);
}