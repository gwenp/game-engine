#ifndef DEF_OPENGLSCENE
#define DEF_OPENGLSCENE

#include "../../src/api/Interfaces/OpenGL/IOpenGL.hpp"

#include "../../src/api/Interfaces/OpenGL/IOpenGLScene.hpp"
#include "../../src/api/Interfaces/OpenGL/ITextureRegistrar.hpp"
#include "../../src/api/Interfaces/Configuration/IConfigurationManager.hpp"
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

class OpenGLScene : public IOpenGLScene
{
public:
	OpenGLScene(IApplication* app);
	~OpenGLScene();

	void onLoad();
	void initTriangle();

	void mainLoop();
private:
	ITextureRegistrar* textureRegistrar;
};


	// This will identify our vertex buffer
	GLuint vertexbuffer;

// An array of 3 vectors which represents 3 vertices
static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

#endif /* DEF_OPENGLSCENE */