#ifndef DEF_OPENGL
#define DEF_OPENGL

#include "../../src/api/Interfaces/IOpenGL.hpp"
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

class OpenGL : public IOpenGL
{
public:
	OpenGL(IApplication* app);
	~OpenGL();

	bool init();
	bool mainLoop();
private:
};

#endif /* DEF_OPENGL */