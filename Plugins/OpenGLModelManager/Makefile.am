AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/  -I/usr/include/sigc++-2.0/

bin_PROGRAMS = OpenGLModelManager.plg

OpenGLModelManager_plg_LDFLAGS = -shared -fPIC
OpenGLModelManager_plg_LDADD = $(GL_LIBS) $(GLEW_LIBS) $(GLFW_LIBS) $(ASSIMP_LIBS) $(IMAGEMAGICK_LIBS) $(LIBSIGC_LIBS)

AM_CPPFLAGS = $(GL_CFLAGS) $(GLEW_CFLAGS) $(GLFW_CFLAGS) $(ASSIMP_CFLAGS) $(IMAGEMAGICK_CFLAGS) $(LIBSIGC_CFLAGS)
AM_CPPFLAGS += -fPIC -g

OpenGLModelManager_plg_SOURCES = src/OpenGLModelManager.cpp \
					src/Mesh.cpp
				    ../../src/api/Plugin.cpp \
					../../src/api/CommunicativeObject.cpp