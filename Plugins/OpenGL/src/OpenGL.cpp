#include "OpenGL.hpp"

OpenGL::OpenGL(IApplication* app) : IOpenGL(app, "OpenGL")
{

}

OpenGL::~OpenGL()
{}

void OpenGL::onLoad()
{
	initConfiguration();

	// Initialise GLFW
	if( !glfwInit() )
	{
		// fprintf( stderr, "Failed to initialize GLFW\n" );
	    return ;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, _cfg->valueInt("aliasing", 4)); // 4x antialiasing
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, _cfg->valueInt("opengl version major", 3)); // We want OpenGL 3.3
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, _cfg->valueInt("opengl version minor", 3));
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
	 
	// Open a window and create its OpenGL context
	if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	{
	    // fprintf( stderr, "Failed to open GLFW window\n" );
	    glfwTerminate();
	    return ;
	}
	
	// Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
	    // fprintf(stderr, "Failed to initialize GLEW\n");
	    return ;
	}
	
	glfwSetWindowTitle( _cfg->valueString("window name", "default title").c_str() );

	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );
}

void OpenGL::signal_onOpenGLLoadedHook(sigc::slot<void> slot)
{
	signal_onOpenGLLoaded.connect(slot);
}

void OpenGL::registerFunctionInMainLoop(sigc::slot<void> slot)
{
	signal_mainLoop.connect(slot);
}

bool OpenGL::mainLoop()
{	
	signal_onOpenGLLoaded();

	do{

		signal_mainLoop();
		// Swap buffers
		glfwSwapBuffers();
	 
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && glfwGetWindowParam( GLFW_OPENED ) );

	return true;
}

void OpenGL::initConfiguration()
{
	IConfigurationManager* configPlugin = (IConfigurationManager*) getPlugin("JsonConfigurationFileManager");

	if(configPlugin != NULL)
	{
		_cfg = configPlugin->initializeSource("data/config/opengl.json");
	}
	else
	{
		std::cout << "ConfigurationManager plugin impossible to reach !" << std::endl;
	}
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new OpenGL(app);
	}
}