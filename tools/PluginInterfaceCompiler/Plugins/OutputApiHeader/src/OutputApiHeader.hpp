#ifndef DEF_OUTPUTAPIHEADER
#define DEF_OUTPUTAPIHEADER

#include "../../src/api/Interfaces/Plugins/IOutputPlugin.hpp"
#include "../../src/api/Interfaces/Plugins/IParserPlugin.hpp"
#include "../../src/api/PluginManager.hpp"
#include "../../src/api/utility/StringCase.hpp"
#include "../../src/api/utility/FileUtils.hpp"

#include <iostream>
#include <vector>
#include <string>

class OutputApiHeader : public IOutputPlugin
{
public:
	OutputApiHeader(IApplication* app);
	~OutputApiHeader();
	
	bool doExport(std::string basePath);
private:
	bool controlDirectoryPath(std::string* path);
};

#endif /* DEF_OUTPUTAPIHEADER */
