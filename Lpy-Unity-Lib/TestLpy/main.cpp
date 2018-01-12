#include <iostream>
#include <memory>
#include <exception>
#include <cmath>

#include <axialtree.h>

#include <Python.h>
#include <lsystem.h>
#include <boost/python/errors.hpp>

#include <boost/python/import.hpp>
#include <fstream>

#include "LpyTurtle.h"

int main(void)
{
	bool change = false;

	Py_Initialize();
	
	if (change)
	{
		ModuleParam::ParamInfo *param1 = new ModuleParam::ParamInfo[1];

		AddInterpretFile("C:\\Lpy\\exempleGrowInterpretation2.lpy", 0);
		AddNewTree(0, 0);

		AppendModule(0, "S", nullptr, 0);

		param1[0].type = 0;
		param1[0].data = "0";
		AppendModule(0, "I", param1, 1);

		AppendModule(0, "[", nullptr, 0);
		AppendModule(0, "+", nullptr, 0);

		param1[0].type = 0;
		param1[0].data = "1";
		AppendModule(0, "B", param1, 1);

		AppendModule(0, "]", nullptr, 0);

		param1[0].type = 0;
		param1[0].data = "0";
		AppendModule(0, "I", param1, 1);

		param1[0].type = 0;
		param1[0].data = "0";
		AppendModule(0, "T", param1, 1);

		Interpret(0, 1);
	}
	else
	{
		std::shared_ptr<LPY::Lsystem> system;

		try
		{
			system = std::make_shared<LPY::Lsystem>("C:\\Lpy\\exempleGrowInterpretation2.lpy");
			std::cout << system->getAxiom().str() << std::endl;
			auto axiom = LPY::AxialTree("SI(0)[+I(0)[+I(0)[+B(5)]I(0)T(2)]I(0)T(1)]I(0)[-I(0)[+B(4)]I(0)T(3)]I(0)T(0)");

			//std::cout << system->interpret(system->derive(axiom)).str() << std::endl;

			std::cout << "________________________" << std::endl;

			axiom = LPY::AxialTree("SI(0)[+B(1)]I(0)T(0)");

			std::cout << system->interpret(system->derive(axiom)).str() << std::endl;
		}
		catch (...)
		{
			PyErr_Print();
		}
	}
	Py_Finalize();

	std::cin.get();
	return 0;
}