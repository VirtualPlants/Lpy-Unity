#include <iostream>
#include <memory>
#include <exception>
#include <axialtree.h>
#include <lsystem.h>
#include <boost/python/errors.hpp>
#include <Python.h>
#include <boost/python/import.hpp>
#include <fstream>

int main(void)
{
	Py_Initialize();
	
	std::string file = "E:\\test.lpy";

	//boost::python::api::object main_module = boost::python::import("__main__");
	//boost::python::api::object main_namespace = main_module.attr("__dict__");

	try
	{
		std::cout << "before Lsystem" << std::endl;
		//boost::python::exec("import sys ; print sys.path", main_namespace);
		//boost::python::exec("import openalea.lpy ; print 'lpy imported'", main_namespace);
		LPY::Lsystem * system = new LPY::Lsystem();
		std::cout << "after Lsystem" << std::endl;
		//system->setFilename()
	}
	catch (boost::python::error_already_set e)
	{
		PyErr_Print();
	}
	Py_Finalize();
	std::cin.get();
	return 0;
}