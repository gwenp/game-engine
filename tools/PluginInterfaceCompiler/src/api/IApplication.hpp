#ifndef DEF_IAPPLICATION
#define DEF_IAPPLICATION

#include "PluginManager.hpp"

#include <iostream>
class IApplication
{
public:
	std::string test(){ return "ioooo"; };
	virtual PluginManager* getPluginManager()=0;
};

#endif /* DEF_IAPPLICATION */
