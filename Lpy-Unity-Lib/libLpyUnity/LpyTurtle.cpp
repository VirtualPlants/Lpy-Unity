#include <memory>
#include <interpretation.h>
#include <axialtree.h>
#include <lsystem.h>
#include "LpyTurtle.h"

WriteCallback DebugCallback = nullptr;
WriteCallback WarningCallback = nullptr;
WriteCallback ErrorCallback = nullptr;
PythonInitializer initializer;
std::shared_ptr<UnityTurtle> turtle = std::make_shared<UnityTurtle>();

ModuleParam moduleParam;

std::shared_ptr<LPY::Lsystem> lsystem = nullptr;
LPY::AxialTree currentTree;
std::shared_ptr<LPY::AxialTree> interpretTree = nullptr;

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

DLL void AddModuleAt(unsigned int pos, char *name, ModuleParam::ParamInfo *infos, int len)
{
	moduleParam.interpretParamsInfos(infos, len);

	if (currentTree.size() == pos - 1)
		currentTree.append(LPY::ParamModule(name, moduleParam.getParams()));
	else
		currentTree.insertAt(pos, LPY::ParamModule(name, moduleParam.getParams()));
}

DLL void AppendModule(char *name, ModuleParam::ParamInfo *infos, int len)
{
	moduleParam.interpretParamsInfos(infos, len);
	currentTree.append(LPY::ParamModule(name, moduleParam.getParams()));
}

DLL int GetFirstParamModuleAt(unsigned int pos)
{
	if (pos >= currentTree.size())
		return -1;

	auto module = currentTree.getAt(pos);
	if (module.size() == 0)
		return -1;

	return boost::python::extract<int>(module.getAt(0));
}

DLL int GetThirdParamModuleAt(unsigned int pos)
{
	if (interpretTree == nullptr || pos >= interpretTree->size())
		return -1;

	auto module = interpretTree->getAt(pos);
	if (module.size() < 3)
		return -1;

	return boost::python::extract<int>(module.getAt(2));
}

DLL char *GetNameModuleAt(unsigned int pos)
{
	if (pos >= currentTree.size())
		return "";

	return (char *)currentTree.getAt(pos).name().c_str();
}

DLL void ChangeParamsModuleAt(unsigned int pos, ModuleParam::ParamInfo *infos, int len)
{
	auto module = currentTree.getAt(pos);
	moduleParam.interpretParamsInfos(infos, len);
	module.setPyArgs(moduleParam.getParams());
}

DLL int GetDerivationLenght()
{
	if (lsystem)
		return 0;

	return static_cast<int> (lsystem->derivationLength());
}

DLL void Interpret(int interation)
{
	Debug(currentTree.str());

	interpretTree = std::make_shared<LPY::AxialTree>();

	for (auto it = currentTree.begin(); it != currentTree.end(); ++it)
	{
		if (it->name() == "I")
		{
			boost::python::list pars;

			pars.append<int>(0);
			interpretTree->append(LPY::ParamModule(",", pars));

			pars = boost::python::list();
			pars.append(0.1f);
			interpretTree->append(LPY::ParamModule("_", pars));

			pars = boost::python::list();
			pars.append(it->getAt(1) + 1);
			pars.append(0.1f);
			pars.append(-1);
			interpretTree->append(LPY::ParamModule("F", pars));
		}
		else if (it->name() == "B")
		{
			boost::python::list pars;

			pars.append<int>(5);
			interpretTree->append(LPY::ParamModule(",", pars));

			pars = boost::python::list();
			pars.append(0.1f);
			interpretTree->append(LPY::ParamModule("_", pars));

			pars = boost::python::list();
			pars.append(it->getAt(1) + 1);
			pars.append(0.1f);
			pars.append(it->getAt(0));
			interpretTree->append(LPY::ParamModule("F", pars));
		}
		else
			interpretTree->append(LPY::ParamModule(it->name(), it->getPyArgs()));
	}

	LPY::turtle_interpretation(*interpretTree, *turtle);

	if (!lsystem)
		return;

	currentTree = lsystem->derive(currentTree, interation, 1, true);
	currentTree = lsystem->interpret(currentTree);
	LPY::turtle_interpretation(currentTree, *turtle);
}

DLL void ResetAxialTree()
{
	currentTree = LPY::AxialTree();
	interpretTree = nullptr;
}

DLL void StopInterpretFile()
{
	lsystem.reset();
}

DLL void StartInterpretFile(char *filename)
{
	currentTree = LPY::AxialTree();

	return;
	
	lsystem = std::make_shared<LPY::Lsystem>(filename);

	currentTree = lsystem->getAxiom();
	currentTree = lsystem->interpret(currentTree);
}

DLL void Interpret_LString(char *lstring)
{
	LPY::AxialTree tree(lstring);
	LPY::turtle_interpretation(tree, *turtle);
}