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

	if(p != NULL)
	{		
		readManifest(findManifestPath(file), p);
		
		_plugins.push_back(p);

		std::pair<std::string, Plugin*> newPluginByName (p->getName(), p);
		_pluginsByName.insert(newPluginByName);

		std::pair<PluginKey, Plugin*> newPluginByKey(p->getKey(), p);
		_pluginsByName.insert(newPluginByKey);
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

Plugin* ConcretePluginManager::getPluginByName ( std::string name , PluginKey key)
{
	return getPluginByName(name, key, false);
}

Plugin* ConcretePluginManager::getPluginByName ( std::string name , PluginKey key, bool forceAuthorization)
{
	if(forceAuthorization)
	{
		return _pluginsByName[name];
	}

	if(isPluginAllowed(name, key))
	{
		return _pluginsByName[name];
	}
	return NULL;
}

void ConcretePluginManager::callOnLoad()
{
	for (std::map<std::string, Plugin*>::iterator it = _pluginsByName.begin(); it != _pluginsByName.end(); ++it)
	{
		(*it).second->onLoad();		
	}
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

std::string ConcretePluginManager::findManifestPath(std::string pluginSoPath)
{
	std::string::size_type i = pluginSoPath.rfind('/', pluginSoPath.length( ));
	std::string manifestFileName = "Manifest.MF";

	if (i != std::string::npos) 
	{
		pluginSoPath.replace(i+1, pluginSoPath.length(), manifestFileName);
		return pluginSoPath;
	}
}	

void ConcretePluginManager::readManifest(std::string path, Plugin* thePlugin)
{
	std::string line;
	std::ifstream manifest;
	manifest.open(path.c_str());
	if (manifest.is_open())
	{
		while (manifest.good())
		{
			getline (manifest,line);
			parseManifestLine(line, thePlugin);
		}
		manifest.close();
	}

	else std::cout 	<< "Unable to open manifest file for plugin " << thePlugin->getName() 
					<< " (path : " << path << ")" << std::endl;
}

void ConcretePluginManager::parseManifestLine(std::string line, Plugin* thePlugin)
{
	std::vector<std::string> tokens = StringUtils::explode(line, ":");
	if(tokens[0] == "uses" && tokens.size() == 2)
	{
		if ( _pluginAutorizationTable.find(thePlugin->getKey()) == _pluginAutorizationTable.end() ) {
			// not found
			_pluginAutorizationTable[thePlugin->getKey()] = std::vector<std::string> ();
		}

		std::vector<std::string> tokensUses = StringUtils::explode(tokens[1], ",");

		for (std::vector<std::string>::iterator it = tokensUses.begin(); it != tokensUses.end(); ++it)
		{
			//fill the permission table from the exploded value
			_pluginAutorizationTable[thePlugin->getKey()].push_back(*it);		
		}


	}	
	void parseManifestLine();
}

bool ConcretePluginManager::isPluginAllowed(std::string destination, PluginKey key)
{
	if(_pluginAutorizationTable[key].empty() == false)
	{
		for (std::vector<std::string>::iterator it = _pluginAutorizationTable[key].begin(); 
				it != _pluginAutorizationTable[key].end(); 
				++it)
		{
			if((*it) == destination)
			{
				return true;
			}
		}
	}

	std::cout << "[error] Plugin " << destination << " call not allowed with key " << key << "!" << std::endl;
	std::cout << "[error] Plugins allowed :" << std::endl;

	for (std::vector<std::string>::iterator it = _pluginAutorizationTable[key].begin(); it != _pluginAutorizationTable[key].end(); ++it)
	{
		std::cout << "\t" << (*it) << std::endl;
	}
	return false;
}