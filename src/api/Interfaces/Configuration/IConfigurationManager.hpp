#ifndef DEF_ICONFIGURATIONMANAGER
#define DEF_ICONFIGURATIONMANAGER

#include "IConfiguration.hpp"

#include "../../Plugin.hpp"
#include "../../IApplication.hpp"

#include <string>

class IConfigurationManager : public Plugin
{
public:
	IConfigurationManager(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual IConfiguration* initializeSource(std::string sourceUrl) =0;
};

#endif /* DEF_ICONFIGURATIONMANAGER */