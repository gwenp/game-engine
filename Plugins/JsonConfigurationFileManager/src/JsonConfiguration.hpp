#ifndef DEF_JSONCONFIGURATION
#define DEF_JSONCONFIGURATION

#include "../../src/api/Interfaces/Configuration/IConfiguration.hpp"
#include <json/json.h>
#include <fstream>

class JsonConfiguration : public IConfiguration
{
public:
	JsonConfiguration(std::string fileUrl);

	virtual std::string valueString(std::string path, std::string defaultValue);
	virtual int valueInt(std::string path, int defaultValue);

private:
	Json::Value root;
	Json::Reader reader;

};

#endif /* DEF_JSONCONFIGURATION */