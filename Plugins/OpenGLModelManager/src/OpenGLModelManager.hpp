#ifndef DEF_OPENGLMODELMANAGER
#define DEF_OPENGLMODELMANAGER

#include "../../src/api/Interfaces/OpenGL/IOpenGLModelManager.hpp"
#include <iostream>
#include <string>

class OpenGLModelManager : public IOpenGLModelManager
{
public:
	OpenGLModelManager(IApplication* app);
	~OpenGLModelManager();

private:
};

#endif /* DEF_OPENGLMODELMANAGER */
