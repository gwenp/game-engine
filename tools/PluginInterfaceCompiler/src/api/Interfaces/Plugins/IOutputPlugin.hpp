#ifndef DEF_IOUTPUTPLUGIN
#define DEF_IOUTPUTPLUGIN

#include "../../Plugin.hpp"

class IOutputPlugin : public Plugin
{
public:
	IOutputPlugin(IApplication* app, std::string name, PluginType type) : Plugin(app, name, type) {};
	~IOutputPlugin();

	virtual bool doExport(std::string basePath) =0;
};

#endif /* DEF_IOUTPUTPLUGIN */