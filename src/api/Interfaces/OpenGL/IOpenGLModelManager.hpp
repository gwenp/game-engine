#ifndef DEF_IOPENGLMODELMANAGER
#define DEF_IOPENGLMODELMANAGER

#include "../../Plugin.hpp"
#include "../../IApplication.hpp"

#include <sigc++/sigc++.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>

#include <string>

class IOpenGLModelManager : public Plugin
{
public:
	IOpenGLModelManager(IApplication* app, std::string name) : Plugin(app, name, TOOL) {};
};

#endif /* DEF_IOPENGLMODELMANAGER */
