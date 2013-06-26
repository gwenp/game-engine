#ifndef DEF_ILOGGER
#define DEF_ILOGGER

#include "../Plugin.hpp"
#include "../IApplication.hpp"

#include <string>

class ILogger : public Plugin
{
public:
	ILogger(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual void operator ()(std::string category, std::string message) =0; //TODO add error level
};

#endif /* DEF_ILOGGER */
