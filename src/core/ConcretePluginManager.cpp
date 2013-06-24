#include "ConcretePluginManager.hpp"

#include "Application.hpp"


ConcretePluginManager::ConcretePluginManager(Application* app, int argc, char **argv):PluginManager(argc,argv),_app(app), _argc(argc), _argv(argv)
{}

ConcretePluginManager::~ConcretePluginManager()
{
	for (std::vector<Plugin*>::iterator it = _plugins.begin(); it != _plugins.end(); ++it)
	{
		delete (*it);
	}

}

std::pair<int,char**> ConcretePluginManager::getCommandLineArgs()
{
	std::pair<int,char **> retValue;
	retValue.first = _argc;
	retValue.second = _argv;
	return retValue;
}

bool ConcretePluginManager::loadPlugin( std::string file, std::string factory_function)
{
	Plugin* p = (Plugin*) loadObjectFromBinary(file,factory_function);
	p->onLoad();

	if(p != NULL)
	{
		_plugins.push_back(p);
		return true;
	}
	else
		return false;
}

std::vector<Plugin*> ConcretePluginManager::getPluginsByType ( PluginType plugintype )
{
	std::vector<Plugin*> pluginList;

	for (std::vector<Plugin*>::iterator it = _plugins.begin(); it != _plugins.end(); ++it)
	{
		if(*it != NULL)
		{
			if((*it)->getType()==plugintype)
			{
				pluginList.push_back(*it);
			}
		}
	}

	return pluginList;
}

Plugin* ConcretePluginManager::getPluginByName ( std::string name )
{
	for (std::vector<Plugin*>::iterator it = _plugins.begin(); it != _plugins.end(); ++it)
	{
		if(*it != NULL)
		{
			if((*it)->getName()==name)
			{
				return (*it);
			}
		}
	}
	return NULL;
}

void* ConcretePluginManager::loadObjectFromBinary( const std::string& soFile, const std::string& makerFunction )
{
	typedef void *(*maker_type)(IApplication*);

	void *hndl;
	maker_type pMaker;

	// library loading
	try {
		hndl = dlopen(soFile.c_str(), RTLD_LAZY);
	}
	catch(...) {
		std::cout << "Error while loading the plg file" << std::endl;
	}

	//in case the handler is not defined, due to errors (most of the cases the library file is not found, corrupted, or unreadable)
	if(hndl == NULL)
	{
		std::cout << BOLDRED << "dlopenError" << RESTORECOLOR << std::endl;
		std::cerr << BOLDRED << "dlopen : "<< dlerror() << RESTORECOLOR << std::endl;
		return(NULL);
	}

	// maker loading
	void *mkr;
	try {
		mkr = dlsym(hndl, makerFunction.c_str());
	}
	catch(...) {
		std::cout<< "Error while looking for the factory function" <<std::endl;
	}

	//in case mkr is not defined, due to errors (most of the cases the factory function is not found)
	if (mkr == NULL)
	{
  		std::cerr << BOLDRED << "dlsym : " << dlerror() << RESTORECOLOR << std::endl;
  		return(NULL);
	}

	//let's make mkr callable
	void *s;
	try {
		pMaker = (maker_type)mkr;

		IApplication* app = (IApplication*) _app;

		s = pMaker(app);
	}
	catch(...) {
		std::cout << "error while calling the factory function" <<std::endl;	
	}

	//byebye
	return s;
}
