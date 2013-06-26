#include "Logger.hpp"

Logger::Logger(IApplication* app) : ILogger(app, "Logger")
{

}

Logger::~Logger()
{}

void Logger::operator ()(std::string category, std::string message)
{
	std::cout << "[" << category <<"] " << message << std::endl;
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new Logger(app);
	}
}
