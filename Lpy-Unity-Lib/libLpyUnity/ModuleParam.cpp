#include <string>
#include <strstream>
#include "ModuleParam.h"
#include "Debug.h"

boost::python::list ModuleParam::interpretParamsInfos(ModuleParam::ParamInfo *infos, int len)
{
	boost::python::list list;

	for (auto i = 0; i < len; i++)
		ModuleParam::appendParams(list, infos[i]);

	return list;
}

void ModuleParam::appendParams(boost::python::list &list, const ParamInfo &info)
{
	if (info.type == 0)
	{
		std::stringstream st(info.data);
		int value;

		st >> value;
		list.append(value);
	}
	else if (info.type == 1)
	{
		std::stringstream st(info.data);
		unsigned value;

		st >> value;
		list.append(value);
	}
	else if (info.type == 2)
	{
		std::stringstream st(info.data);
		float value;

		st >> value;
		list.append(value);
	}
	else if (info.type == 3)
	{
		std::stringstream st(info.data);
		double value;

		st >> value;
		list.append(value);
	}
	else if (info.type == 4)
	{
		list.append(std::string(info.data));
	}
}