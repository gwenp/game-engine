#include "OpenGLScene.hpp"

OpenGLScene::OpenGLScene(IApplication* app) : IOpenGLScene(app, "OpenGLScene")
{

}

OpenGLScene::~OpenGLScene()
{}

void OpenGLScene::onLoad()
{
	std::cout << "OpenGLScene::onLoad@begin" << std::endl;

	IOpenGL* openGLPlugin = (IOpenGL*) getPlugin("OpenGL");

	if(openGLPlugin != NULL)
	{
		openGLPlugin->registerFunctionInMainLoop(sigc::mem_fun(this, &OpenGLScene::mainLoop));
	
		initTriangle();
	}
	else
	{
		std::cout << "OpenGL plugin impossible to reach !" << std::endl;
	}

	textureRegistrar = (ITextureRegistrar*) getPlugin("TextureRegistrar");

	if(textureRegistrar != NULL)
	{
		textureRegistrar->loadTexture("grass","data/textures/grass.bmp");
	}
	else
	{
		std::cout << "TextureRegistrar plugin impossible to reach !" << std::endl;
	}
}

void OpenGLScene::initTriangle()
{
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	 
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	 
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void OpenGLScene::mainLoop()
{
	textureRegistrar->useTexture("grass");

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	
	 // Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	 
	glDisableVertexAttribArray(0);
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new OpenGLScene(app);
	}
}