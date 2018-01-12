#ifndef MODULE_PARAM_H
#define MODULE_PARAM_H

#include <boost/python/list.hpp>

class ModuleParam
{
public:
	struct ParamInfo
	{
		int type;
		char *data;
	};

	static boost::python::list interpretParamsInfos(ParamInfo *infos, int len);
	
private:
	static void appendParams(boost::python::list &list, const ParamInfo &info);
};

#endif