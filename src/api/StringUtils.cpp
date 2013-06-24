#include "StringUtils.hpp"


StringUtils::StringUtils()
{
	
}

std::vector<std::string> StringUtils::StringExplode(std::string str, std::string separator)
{
    std::vector<std::string> results;

    int found;
    found = str.find_first_of(separator);
    while(found != std::string::npos){
        if(found > 0){
            results.push_back(str.substr(0,found));
        }
        str = str.substr(found+1);
        found = str.find_first_of(separator);
    }
    if(str.length() > 0){
        results.push_back(str);
    }

    return results;
}

