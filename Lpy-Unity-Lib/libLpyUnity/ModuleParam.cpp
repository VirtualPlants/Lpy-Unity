#include <string>
#include <strstream>
#include "ModuleParam.h"
#include "Debug.h"

void ModuleParam::interpretParamsInfos(ModuleParam::ParamInfo *infos, int len)
{
	this->_pars = boost::python::list();

	for (auto i = 0; i < len; i++)
		//Debug("Index " + std::to_string(i) + " : " + std::to_string(infos[i].type));
		this->appendParams(infos[i]);
}

const boost::python::list &ModuleParam::getParams() const
{
	return this->_pars;
}

void ModuleParam::appendParams(const ParamInfo &info)
{
	if (info.type == 0)
	{
		std::stringstream st(info.data);
		int value;

		st >> value;
		this->_pars.append(value);
	}
	else if (info.type == 1)
	{
		std::stringstream st(info.data);
		unsigned value;

		st >> value;
		this->_pars.append(value);
	}
	else if (info.type == 2)
	{
		std::stringstream st(info.data);
		float value;

		st >> value;
		this->_pars.append(value);
	}
	else if (info.type == 3)
	{
		std::stringstream st(info.data);
		double value;

		st >> value;
		this->_pars.append(value);
	}
	else if (info.type == 4)
		this->_pars.append(std::string(info.data));
}