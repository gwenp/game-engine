#include "TextureRegistrar.hpp"

TextureRegistrar::TextureRegistrar(IApplication* app) : ITextureRegistrar(app, "TextureRegistrar")
{
	std::cout << "TextureRegistrar::ctor" << std::endl;
	ImageLoader::init();

	_textures["none"] = 0;
}

TextureRegistrar::~TextureRegistrar()
{}

void TextureRegistrar::onLoad()
{
	IOpenGL* openGLPlugin = (IOpenGL*) getPlugin("OpenGL");

	if(openGLPlugin != NULL)
	{
		openGLPlugin->signal_onOpenGLLoadedHook(sigc::mem_fun(this, &TextureRegistrar::init));
	}
	else
	{
		std::cout << "OpenGL plugin impossible to reach !" << std::endl;
	}
}

void TextureRegistrar::init()
{
}

void TextureRegistrar::loadTexture(std::string index, std::string path)
{
	const char* path2 = "data/textures/grass.bmp";

  	GLuint newTexture = ImageLoader::loadImage_devil(path2);
  	_textures[index] = newTexture;
}

void TextureRegistrar::useTexture(std::string index)
{
	// Dbg::out("RessourceManager")<< "RessourceManager::useTexture " << name << std::endl;
    glBindTexture(GL_TEXTURE_2D,_textures[index]);
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new TextureRegistrar(app);
	}
}