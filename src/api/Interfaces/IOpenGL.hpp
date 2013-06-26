#ifndef DEF_IOPENGL
#define DEF_IOPENGL

#include "../Plugin.hpp"
#include "../IApplication.hpp"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include <string>

class IOpenGL : public Plugin
{
public:
	IOpenGL(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual bool init() =0;
	virtual bool mainLoop() =0;
};

#endif /* DEF_IOPENGL */
