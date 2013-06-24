#ifndef DEF_MANIFESTPARSER
#define DEF_MANIFESTPARSER

#include <fstream>
#include <sstream> 
#include <algorithm> 
#include <vector>
#include <iostream>

namespace ParserCategory {
	enum CategoryEnum { GENERAL, DEPENDENCIES, INCLUDES, CALLABLEMETHODS, LISTENS };

};

class ManifestParser
{
public:

protected:
	void parseFile(std::string filePath);

	std::string _name;
	std::string _version;
	std::string _inherits;
	std::vector<std::string> _includes;
	std::vector<std::string> _methods;
private:
	void removeComment(std::string &line) const;

	// trim from both ends
	inline void format(std::string &s);
	inline void matchCategories(std::string &s);

	inline void matchCategoryGeneral(std::string &s);
	inline void matchCategoryDependencies(std::string &s);
	inline void matchCategoryIncludes(std::string &s);
	inline void matchCategoryCallableMethods(std::string &s);
	inline void matchCategoryListens(std::string &s);

	inline bool emptyLine(std::string &s);
	ParserCategory::CategoryEnum _currentCategory;
};

#endif /* DEF_MANIFESTPARSER */