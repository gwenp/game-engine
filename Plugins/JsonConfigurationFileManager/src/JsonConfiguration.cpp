#include "JsonConfiguration.hpp"

JsonConfiguration::JsonConfiguration(std::string fileUrl)
{
	std::ifstream stream(fileUrl.c_str(), std::ifstream::binary);
    bool parsingSuccessful = reader.parse( stream, root, false );
    if ( !parsingSuccessful )
	{
		// report to the user the failure and their locations in the document.
		std::cout  << "Failed to parse configuration\n"
				   << reader.getFormattedErrorMessages();
	}
}

std::string JsonConfiguration::valueString(std::string path, std::string defaultValue)
{
	return root.get(path, defaultValue ).asString();
}

int JsonConfiguration::valueInt(std::string path, int defaultValue)
{
	return root.get(path, defaultValue ).asInt();
}
