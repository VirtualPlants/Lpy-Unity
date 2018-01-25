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
	std::stringstream st(info.data);

	switch (info.type)
	{
	case 0:
		int valueI;
		st >> valueI;
		list.append(valueI);
		break;
	case 1:
		unsigned valueU;
		st >> valueU;
		list.append(valueU);
		break;
	case 2:
		float valueF;
		st >> valueF;
		list.append(valueF);
		break;
	case 3:
		double valueD;
		st >> valueD;
		list.append(valueD);
		break;
	case 4:
		list.append(std::string(info.data));
		break;
	case 5:
		list.append(std::string(info.data) == "True");
		break;
	default:
		break;
	}
}