#include "ExtensionLoader.hpp"

ExtensionLoader::ExtensionLoader(IApplication* app) : Plugin(app, "ExtensionLoader", POLICY)
{}

ExtensionLoader::~ExtensionLoader()
{}

void ExtensionLoader::onLoad()
{}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new ExtensionLoader(app);
	}
}
