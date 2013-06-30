#ifndef DEF_IOPENGL
#define DEF_IOPENGL

#include "../../Plugin.hpp"
#include "../../IApplication.hpp"

#include <sigc++/sigc++.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include <string>

class IOpenGL : public Plugin
{
public:
	IOpenGL(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};

	virtual void registerFunctionInMainLoop(sigc::slot<void> slot) =0;
	virtual void signal_onOpenGLLoadedHook(sigc::slot<void> slot) =0;
	virtual bool mainLoop() =0;
};

#endif /* DEF_IOPENGL */
