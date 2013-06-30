#ifndef DEF_STRINGUTILS
#define DEF_STRINGUTILS

#include <string>
#include <vector>
#include <sstream>
#include <utility>

class StringUtils
{
public:
	static std::vector<std::string> explode(std::string str, std::string separator);	
};

#endif /* DEF_STRINGUTILS */