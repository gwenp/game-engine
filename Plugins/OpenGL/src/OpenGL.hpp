#ifndef DEF_OPENGL
#define DEF_OPENGL

#include "../../src/api/Interfaces/OpenGL/IOpenGL.hpp"
#include "../../src/api/Interfaces/Configuration/IConfigurationManager.hpp"
#include <iostream>
#include <string>

#include <sigc++/sigc++.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

class OpenGL : public IOpenGL
{
public:
	OpenGL(IApplication* app);
	~OpenGL();

	void onLoad();

	void registerFunctionInMainLoop(sigc::slot<void> slot);
	void signal_onOpenGLLoadedHook(sigc::slot<void> slot);

	bool mainLoop();
private:
	sigc::signal<void> signal_onOpenGLLoaded;
	sigc::signal<void> signal_mainLoop;

	void initConfiguration();
	IConfiguration* _cfg;
};

#endif /* DEF_OPENGL */