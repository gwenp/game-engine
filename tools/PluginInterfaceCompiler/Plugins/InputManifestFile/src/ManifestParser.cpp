#include "ManifestParser.hpp"

using std::string;
using std::cout;
using std::ifstream;

void ManifestParser::parseFile(std::string filePath)
{
	ifstream f(filePath.c_str());

	_name = "TestPlugin";
	
	std::cout << _name << std::endl;

	string line;
	while (std::getline(f, line)) { // Use the read operation as the test in the loop.
		removeComment(line);
		format(line);

		matchCategories(line);
	}
}

void ManifestParser::removeComment(string &line) const
{
	if (line.find('#') != line.npos)
		line.erase(line.find('#'));
}

inline void ManifestParser::format(string &s) 
{
	bool multipleSpacesConsecutive = true;
	for (int i=0; i < s.length(); i++)
	{
		if (s[i] == '\t')
			s.erase(i, 1), i--;
		if (s[i] == ' ')
		{
			if(multipleSpacesConsecutive)
				s.erase(i, 1), i--;
			else
				multipleSpacesConsecutive = true;
		}
		else
		{
			multipleSpacesConsecutive = false;
		}
	}
}

inline void ManifestParser::matchCategories(string &s) 
{
	//TODO The complexity of these cases could be simplified, factoring with "-"
	if(s.find("- General") == 0 || s.find("-General") == 0)
		_currentCategory = ParserCategory::GENERAL;
	else if(s.find("- Dependencies") == 0 || s.find("-Dependencies") == 0)
		_currentCategory = ParserCategory::DEPENDENCIES;
	else if(s.find("- Includes") == 0 || s.find("-Includes") == 0)
		_currentCategory = ParserCategory::INCLUDES;
	else if(s.find("- CallableMethods") == 0 || s.find("-CallableMethods") == 0)
		_currentCategory = ParserCategory::CALLABLEMETHODS;
	else if(s.find("- Listens") == 0 || s.find("-Listens") == 0)
		_currentCategory = ParserCategory::LISTENS;
	else
		switch(_currentCategory)
		{
			case ParserCategory::GENERAL:
				matchCategoryGeneral(s);
				break;
			case ParserCategory::DEPENDENCIES:
				matchCategoryDependencies(s);
				break;
			case ParserCategory::INCLUDES:
				matchCategoryIncludes(s);
				break;
			case ParserCategory::CALLABLEMETHODS:
				matchCategoryCallableMethods(s);
				break;
			case ParserCategory::LISTENS:
				matchCategoryListens(s);
				break;
		}
}

inline void ManifestParser::matchCategoryGeneral(string &s)
{
	//TODO nuke this ugly shit
	if(size_t pos = s.find("Version") == 0)
	{
		s.erase(pos -1 , 8);
		_version = s;
	}
	//TODO nuke this ugly shit
	if(size_t pos = s.find("Inherits") == 0)
	{
		s.erase(pos -1 , 9);
		_inherits = s;
	}
}

inline void ManifestParser::matchCategoryDependencies(string &s)
{
	if(!emptyLine(s))
		std::cout << "dependancy :" << s << std::endl;
}

inline void ManifestParser::matchCategoryIncludes(string &s)
{
	_includes.push_back(s);
}

inline void ManifestParser::matchCategoryCallableMethods(string &s)
{
	_methods.push_back(s);
}

inline void ManifestParser::matchCategoryListens(string &s)
{
	if(!emptyLine(s))
		std::cout << "listens :" << s << std::endl;
}

inline bool ManifestParser::emptyLine(string &s)
{
	if(s == "" and s == " ")
		return true;
	else
		return false;
}
