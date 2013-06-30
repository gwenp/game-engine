#ifndef DEF_TEXTUREREGISTRAR
#define DEF_TEXTUREREGISTRAR

#include "../../src/api/Interfaces/OpenGL/IOpenGL.hpp"

#include "../../src/api/Interfaces/OpenGL/ITextureRegistrar.hpp"
#include <iostream>
#include <string>
#include <map>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include "ImageLoader.hpp"

class TextureRegistrar : public ITextureRegistrar
{
public:
	TextureRegistrar(IApplication* app);
	~TextureRegistrar();

	void onLoad();
	void init();

	void loadTexture(std::string index, std::string path);
	void useTexture(std::string name);
private:
	std::map<std::string, GLuint> _textures;
};

#endif /* DEF_TEXTUREREGISTRAR */