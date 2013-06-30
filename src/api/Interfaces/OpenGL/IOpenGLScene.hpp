#ifndef DEF_IOPENGLSCENES
#define DEF_IOPENGLSCENES

#include "../../Plugin.hpp"
#include "../../IApplication.hpp"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include <string>

class IOpenGLScene : public Plugin
{
public:
	IOpenGLScene(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};
};

#endif /* DEF_IOPENGLSCENES */
