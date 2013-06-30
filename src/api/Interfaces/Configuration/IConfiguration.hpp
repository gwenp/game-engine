#ifndef DEF_ICONFIGURATION
#define DEF_ICONFIGURATION

#include <string>

class IConfiguration
{
public:
	IConfiguration(){};
	virtual std::string valueString(std::string path, std::string defaultValue) =0;
	virtual int valueInt(std::string path, int defaultValue) =0;
};

#endif /* DEF_ICONFIGURATION */