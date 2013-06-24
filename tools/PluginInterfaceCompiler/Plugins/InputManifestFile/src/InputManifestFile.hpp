#ifndef DEF_INPUTMANIFESTFILE
#define DEF_INPUTMANIFESTFILE

#include "../../src/api/Interfaces/Plugins/IParserPlugin.hpp"
#include "ManifestParser.hpp"
#include <iostream>

#include <vector> 
#include <string>

class InputManifestFile : public IParserPlugin, private ManifestParser
{
public:
	InputManifestFile(IApplication* app);
	~InputManifestFile();

	void parseFile(std::string filePath);

	std::string getName();
	std::string getVersion();
	std::string getInherits();
	std::vector<std::string> getIncludes();
	std::vector<std::string> getMethods();
private:

};

#endif /* DEF_INPUTMANIFESTFILE */
