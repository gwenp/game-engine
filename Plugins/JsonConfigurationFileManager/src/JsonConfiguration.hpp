#ifndef DEF_JSONCONFIGURATION
#define DEF_JSONCONFIGURATION

#include "../../src/api/Interfaces/Configuration/IConfiguration.hpp"
#include <json/json.h>
#include <fstream>

class JsonConfiguration : public IConfiguration
{
public:
	JsonConfiguration(std::string fileUrl);

	virtual std::string getValue(std::string path);

private:
	Json::Value root;
	Json::Reader reader;

};

#endif /* DEF_JSONCONFIGURATION */