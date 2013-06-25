#ifndef DEF_JSONCONFIGURATIONFILEMANAGER
#define DEF_JSONCONFIGURATIONFILEMANAGER

#include "../../src/api/Interfaces/Configuration/IConfigurationManager.hpp"
#include "JsonConfiguration.hpp"
#include <iostream>
#include <string>

class JsonConfigurationFileManager : public IConfigurationManager
{
public:
	JsonConfigurationFileManager(IApplication* app);
	~JsonConfigurationFileManager();

	IConfiguration* initializeSource(std::string sourcePath);

private:
};

#endif /* DEF_JSONCONFIGURATIONFILEMANAGER */