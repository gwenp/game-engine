#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <vector>
#include <string>

class StringUtils
{
	public:
		StringUtils();
		static std::vector<std::string> StringExplode(std::string str, std::string separator);
	private:
};

#endif /* STRINGUTILS_HPP */ 
