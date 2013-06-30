#include "OpenGLModelManager.hpp"

OpenGLModelManager::OpenGLModelManager(IApplication* app) : IOpenGLModelManager(app, "OpenGLModelManager")
{

}

OpenGLModelManager::~OpenGLModelManager()
{}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new OpenGLModelManager(app);
	}
}