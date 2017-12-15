#ifndef MODULE_PARAM_H
#define MODULE_PARAM_H

#include <boost/python/list.hpp>

class ModuleParam
{
	boost::python::list _pars;

public:
	struct ParamInfo
	{
		int type;
		char *data;
	};

public:
	ModuleParam() = default;
	~ModuleParam() = default;
	
	void interpretParamsInfos(ParamInfo *infos, int len);

	const boost::python::list &getParams() const;

private:
	void appendParams(const ParamInfo &info);
};

#endif