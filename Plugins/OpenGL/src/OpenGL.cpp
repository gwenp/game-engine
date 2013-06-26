#include "OpenGL.hpp"

OpenGL::OpenGL(IApplication* app) : IOpenGL(app, "OpenGL")
{

}

OpenGL::~OpenGL()
{}

bool OpenGL::init()
{
	// Initialise GLFW
	if( !glfwInit() )
	{
	    // fprintf( stderr, "Failed to initialize GLFW\n" );
	    return false;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x antialiasing
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
	 
	// Open a window and create its OpenGL context
	if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	{
	    // fprintf( stderr, "Failed to open GLFW window\n" );
	    glfwTerminate();
	    return false;
	}
	 
	// Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
	    // fprintf(stderr, "Failed to initialize GLEW\n");
	    return false;
	}
	 
	glfwSetWindowTitle( "OpenGL Window" );

	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );
}

bool OpenGL::mainLoop()
{
	do{
	    // Draw nothing, see you in tutorial 2 !
	 
		// Swap buffers
		glfwSwapBuffers();
	 
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && glfwGetWindowParam( GLFW_OPENED ) );

	return true;
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new OpenGL(app);
	}
}
