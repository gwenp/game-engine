#ifndef DEF_IPARSERPLUGIN
#define DEF_IPARSERPLUGIN

#include "../../Plugin.hpp"

#include <vector>
#include <string>

class IParserPlugin : public Plugin
{
public:
	IParserPlugin(IApplication* app, std::string name, PluginType type) : Plugin(app, name, type) {};

	virtual void parseFile(std::string filePath) =0;

	virtual std::string getName() =0;
	virtual std::string getVersion() =0;
	virtual std::string getInherits() =0;
	virtual std::vector<std::string> getMethods() =0;
	virtual std::vector<std::string> getIncludes() =0;
};

#endif /* DEF_IPARSERPLUGIN */