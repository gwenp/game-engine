#include "InputManifestFile.hpp"

InputManifestFile::InputManifestFile(IApplication* app) : IParserPlugin(app, "InputManifestFile", PARSER)
{

}

InputManifestFile::~InputManifestFile()
{

}

void InputManifestFile::parseFile(std::string filePath)
{
	ManifestParser::parseFile(filePath);
}

std::string InputManifestFile::getName()
{
	return ManifestParser::_name;
}

std::string InputManifestFile::getVersion()
{
	return ManifestParser::_version;
}

std::string InputManifestFile::getInherits()
{
	return ManifestParser::_inherits;
}

std::vector<std::string> InputManifestFile::getIncludes()
{
	return ManifestParser::_includes;
}

std::vector<std::string> InputManifestFile::getMethods()
{
	return ManifestParser::_methods;
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new InputManifestFile(app);
	}
}
