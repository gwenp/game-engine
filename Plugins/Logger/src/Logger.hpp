#ifndef DEF_LOGGER
#define DEF_LOGGER

#include "../../src/api/Interfaces/ILogger.hpp"
#include <iostream>
#include <string>

class Logger : public ILogger
{
public:
	Logger(IApplication* app);
	~Logger();

	void operator ()(std::string category, std::string message); //TODO add error level

private:
};

#endif /* DEF_LOGGER */