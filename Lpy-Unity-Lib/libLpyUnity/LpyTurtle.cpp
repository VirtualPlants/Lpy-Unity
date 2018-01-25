#include <memory>
#include <interpretation.h>
#include <axialtree.h>
#include <lsystem.h>
#include "LpyTurtle.h"

WriteCallback DebugCallback = nullptr;
WriteCallback WarningCallback = nullptr;
WriteCallback ErrorCallback = nullptr;
PythonInitializer initializer;

std::map<unsigned long, TreeInformations> trees;
std::vector<Rule> rules;

typedef boost::python::object object;

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

DLL void SetMakeCylinder(unsigned long treeid, UnityTurtle::MakeCylinder callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeCylinder: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeCylinder(callback);
}

DLL void SetMakeCone(unsigned long treeid, UnityTurtle::MakeCone callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeCone: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeCone(callback);
}

DLL void SetMakeSphere(unsigned long treeid, UnityTurtle::MakeSphere callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeSphere: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeSphere(callback);
}

DLL void SetMakeBox(unsigned long treeid, UnityTurtle::MakeBox callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeBox: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeBox(callback);
}

DLL void SetMakeCircle(unsigned long treeid, UnityTurtle::MakeCircle callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeCircle: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeCircle(callback);
}

DLL void SetMakeQuad(unsigned long treeid, UnityTurtle::MakeQuad callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeQuad: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeQuad(callback);
}

DLL void SetMakeSurface(unsigned long treeid, UnityTurtle::MakeSurface callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeSurface: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeSurface(callback);
}

DLL void SetMakePolygon(unsigned long treeid, UnityTurtle::MakePolygon callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakePolygon: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakePolygon(callback);
}

DLL void SetMakeGeneralizedGeometry(unsigned long treeid, UnityTurtle::MakeGeneralizedGeometry callback)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot SetMakeGeneralizedGeometry: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.turtle->setMakeGeneralizedGeometry(callback);
}

DLL void PrintLstring(unsigned long treeid)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot PrintLstring: treeid (" + std::to_string(treeid) + ") not found");
	Debug(tree->second.currentTree.str());
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
	for (auto &it : trees)
		it.second.turtle->setColorListSize(size);
}

DLL void AddModuleAt(unsigned long treeid, unsigned int pos, char *name, ModuleParam::ParamInfo *infos, int len)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot AddModuleAt: treeid (" + std::to_string(treeid) + ") not found");

	auto params = ModuleParam::interpretParamsInfos(infos, len);

	if (tree->second.currentTree.size() == pos - 1)
		tree->second.currentTree.append(LPY::ParamModule(name, params));
	else
		tree->second.currentTree.insertAt(pos, LPY::ParamModule(name, params));
}

DLL void AppendModule(unsigned long treeid, char *name, ModuleParam::ParamInfo *infos, int len)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot AppendModule: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.currentTree.append(LPY::ParamModule(name, ModuleParam::interpretParamsInfos(infos, len)));
}

DLL int GetFirstParamModuleAt(unsigned long treeid, unsigned int pos)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
	{
		Error("Cannot GetFirstParamModuleAt: treeid (" + std::to_string(treeid) + ") not found");
		return -1;
	}

	if (pos >= tree->second.currentTree.size())
		return -1;

	auto &module = tree->second.currentTree.getAt(pos);
	if (module.size() == 0)
		return -1;

	return boost::python::extract<int>(module.getAt(0));
}

DLL int GetSecondParamModuleAt(unsigned long treeid, unsigned int pos)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
	{
		Error("Cannot GetSecondParamModuleAt: treeid (" + std::to_string(treeid) + ") not found");
		return -1;
	}

	if (tree->second.interpretTree == nullptr || pos >= tree->second.interpretTree->size())
		return -1;

	auto &module = tree->second.interpretTree->getAt(pos);
	if (module.size() < 2)
		return -1;

	return boost::python::extract<int>(module.getAt(1));
}

DLL int GetThirdParamModuleAt(unsigned long treeid, unsigned int pos)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
	{
		Error("Cannot GetThirdParamModuleAt: treeid (" + std::to_string(treeid) + ") not found");
		return -1;
	}

	if (tree->second.interpretTree == nullptr || pos >= tree->second.interpretTree->size())
		return -1;

	auto &module = tree->second.interpretTree->getAt(pos);
	if (module.size() < 3)
		return -1;

	return boost::python::extract<int>(module.getAt(2));
}

DLL char *GetNameModuleAt(unsigned long treeid, unsigned int pos)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
	{
		Error("Cannot GetNameModuleAt: treeid (" + std::to_string(treeid) + ") not found");
		return nullptr;
	}

	if (pos >= tree->second.currentTree.size())
		return "";

	return (char *)tree->second.currentTree.getAt(pos).name().c_str();
}

DLL void ChangeParamsModuleAt(unsigned long treeid, unsigned int pos, ModuleParam::ParamInfo *infos, int len)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot ChangeParamsModuleAt: treeid (" + std::to_string(treeid) + ") not found");

	auto &module = tree->second.currentTree.getAt(pos);
	module.setPyArgs(ModuleParam::interpretParamsInfos(infos, len));
}

DLL int GetDerivationLenght(unsigned long fileid)
{
	auto &rule = std::find_if(rules.begin(), rules.end(), [fileid](Rule &it) -> bool {
		if (it.fileid == fileid)
			return true;
		return false;
	});

	//auto &rule = rules.find(fileid);
	if (rule == rules.end())
	{
		Error("Cannot GetDerivationLenght: fileid (" + std::to_string(fileid) + ") not found");
		return 0;
	}

	return static_cast<int> (rule->lsystem.derivationLength());
}

DLL void Interpret(unsigned long treeid, int iteration)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot Interpret: treeid (" + std::to_string(treeid) + ") not found");
	/*
	if (!tree->second.lsystem)
		return Error("Cannot Interpret: lsystem not init");

	
	auto deriveTree = tree->second.lsystem->derive(tree->second.currentTree);
	auto interpretedTree = tree->second.lsystem->interpret(deriveTree);
	tree->second.interpretTree = std::make_shared<LPY::AxialTree>(interpretedTree);

	Debug(tree->second.interpretTree->str());
	//return;
	//LPY::turtle_interpretation(*tree->second.interpretTree, *tree->second.turtle);
	*/

	LPY::AxialTree updateTree(tree->second.currentTree);

	for (auto it = updateTree.end() - 1; it != updateTree.begin(); --it)
	{
		if (it->name() == "I")
		{
			auto children = updateTree.children(it, LPY::ConsiderFilter::consider("I T B"));
			int nbNode = 0;

			for (auto c : children)
			{
				if (c->name() == "I")
					nbNode += boost::python::extract<int>(c->getAt(0));
				else if (c->name() == "B" || c->name() == "T")
					nbNode += 1;
			}
			it->setPyArgs(boost::python::list(boost::python::make_tuple(nbNode)));
		}
	}

	tree->second.interpretTree = std::make_shared<LPY::AxialTree>();
	int branchAngle;
	bool drawLeaf;

	auto getRadius = [](const int &nbdesc) -> double
	{
		return 0.05 * std::pow(nbdesc + 1, 0.6);
	};

	for (auto it = updateTree.begin(); it != updateTree.end(); ++it)
	{
		if (it->name() == "S")
		{
			tree->second.interpretTree->append(LPY::ParamModule("@Ts", object(it->getAt(0))));
			tree->second.interpretTree->append(LPY::ParamModule("@Tp"));
			branchAngle = bp::extract<int>(it->getAt(1));
			drawLeaf = bp::extract<bool>(it->getAt(2));

			if (it + 1 == updateTree.end())
			{
				tree->second.interpretTree->append(LPY::ParamModule(";", object(2)));
				tree->second.interpretTree->append(LPY::ParamModule("@O", object(0.2), object(0)));
			}
		}
		else if (it->name() == "I")
		{
			int nbdesc = boost::python::extract<int>(it->getAt(0));
			double startRadius = (double)(int)(getRadius(nbdesc) * 1000) / 1000;
			double endRadius = (double)(int)(getRadius(nbdesc - 1) * 1000) / 1000;
			float length = 1;
			float dl = 0.1;

			tree->second.interpretTree->append(LPY::ParamModule("_", object(startRadius)));
			tree->second.interpretTree->append(LPY::ParamModule(";", object(1)));
			if (drawLeaf && (it + 1)->name() == "T")
			{
				float radius = endRadius;
				uint32_t nbSteps = uint32_t(length / dl);
				float deltaStep = length - nbSteps * dl;
				float w = startRadius;
				float dw = (radius - w) / length;
				float cw = w;

				for (uint32_t i = 1; i <= nbSteps; ++i)
				{
					cw += dw * dl;
					tree->second.interpretTree->append(LPY::ParamModule("["));
					tree->second.interpretTree->append(LPY::ParamModule("/", object(90 * i)));
					tree->second.interpretTree->append(LPY::ParamModule("&", object(90)));
					tree->second.interpretTree->append(LPY::ParamModule("\\", object(90)));
					tree->second.interpretTree->append(LPY::ParamModule("surface", object("LeaveBent_e_03"), object(6)));
					//tree->second.interpretTree->append(LPY::ParamModule("F"));
					tree->second.interpretTree->append(LPY::ParamModule("]"));
					tree->second.interpretTree->append(LPY::ParamModule("F", object(dl), object(cw)));
				}
			}
			else
				tree->second.interpretTree->append(LPY::ParamModule("nF", object(length), object(dl), object(endRadius)));
		}
		else if (it->name() == "B")
		{
			int nbdesc = boost::python::extract<int>(updateTree.parent(it, LPY::ConsiderFilter::consider("I"))->getAt(0));
			double radius = (double)(int)(getRadius(nbdesc) * 1000) / 1000;

			tree->second.interpretTree->append(LPY::ParamModule("f", object(radius)));
			tree->second.interpretTree->append(LPY::ParamModule(";", object(3)));
			tree->second.interpretTree->append(LPY::ParamModule("@O", object(0.1), object(it->getAt(0))));
		}
		else if (it->name() == "T")
		{
			tree->second.interpretTree->append(LPY::ParamModule(";", object(3)));
			tree->second.interpretTree->append(LPY::ParamModule("@O", object(0.125), object(it->getAt(0))));
		}
		else if (it->name() == "R")
		{
			auto dir = (bp::extract<bool>(it->getAt(0))) ? "+" : "-";
			tree->second.interpretTree->append(LPY::ParamModule(dir, object(branchAngle)));
		}
		else
			tree->second.interpretTree->append(LPY::ParamModule(it->name(), it->getPyArgs()));
	}

	//Debug(tree->second.interpretTree->str());

	LPY::turtle_interpretation(*tree->second.interpretTree, *tree->second.turtle);

	/*
	if (!tree->second.lsystem)
		return;

	tree->second.currentTree = tree->second.lsystem->derive(tree->second.currentTree, iteration, 1, true);
	tree->second.currentTree = tree->second.lsystem->interpret(tree->second.currentTree);
	LPY::turtle_interpretation(tree->second.currentTree, *tree->second.turtle);
	*/
}

DLL void ResetAxialTree(unsigned long treeid)
{
	auto &tree = trees.find(treeid);
	if (tree == trees.end())
		return Error("Cannot ResetAxialTree: treeid (" + std::to_string(treeid) + ") not found");

	tree->second.currentTree = LPY::AxialTree();
	tree->second.interpretTree = nullptr;
}

DLL void AddNewTree(unsigned long treeid, unsigned long fileid)
{
	auto &tree = trees.find(treeid);
	if (tree != trees.end())
		return Error("Cannot AddNewTree: treeid (" + std::to_string(treeid) + ") already exist");

	/*auto &rule = std::find_if(rules.begin(), rules.end(), [fileid](Rule &it) -> bool {
		if (it.fileid == fileid)
			return true;
		return false;
	});
	if (rule == rules.end())
		return Error("Cannot AddInterpretFile: file (" + std::to_string(fileid) + ") not found");
		*/
	trees.emplace(treeid, std::move(TreeInformations()));
	trees[treeid].fileid = fileid;
}

DLL void AddInterpretFile(char *filename, unsigned long fileid)
{
	auto &rule = std::find_if(rules.begin(), rules.end(), [fileid](Rule &it) -> bool {
		if (it.fileid == fileid)
			return true;
		return false;
	});
	if (rule != rules.end())
		return Error("Cannot AddInterpretFile: file (" + std::to_string(fileid) + ") already exist");

	rules.push_back(Rule(fileid, filename));
}