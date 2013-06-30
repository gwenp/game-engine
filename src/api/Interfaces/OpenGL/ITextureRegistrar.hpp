#ifndef DEF_ITEXTUREREGISTRAR
#define DEF_ITEXTUREREGISTRAR

#include "../../Plugin.hpp"
#include "../../IApplication.hpp"

#include <string>

class ITextureRegistrar : public Plugin
{
public:
	ITextureRegistrar(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual void loadTexture(std::string index, std::string path) =0;
	virtual void useTexture(std::string index) =0;
};

#endif /* DEF_ITEXTUREREGISTRAR */
