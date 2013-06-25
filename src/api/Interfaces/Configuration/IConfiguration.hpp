#ifndef DEF_ICONFIGURATION
#define DEF_ICONFIGURATION

#include <string>

class IConfiguration
{
public:
	IConfiguration(){};
	virtual std::string getValue(std::string path) =0;
};

#endif /* DEF_ICONFIGURATION */