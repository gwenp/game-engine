AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ -I/usr/include/sigc++-2.0/

bin_PROGRAMS = OpenGLScene.plg

OpenGLScene_plg_LDFLAGS = -shared -fPIC
OpenGLScene_plg_LDADD = $(GL_LIBS) $(GLEW_LIBS) $(GLFW_LIBS) $(LIBSIGC_LIBS)

AM_CPPFLAGS = $(GL_CFLAGS) $(GLEW_CFLAGS) $(GLFW_CFLAGS) $(LIBSIGC_CFLAGS)
AM_CPPFLAGS += -fPIC -g

OpenGLScene_plg_SOURCES = src/OpenGLScene.cpp \
				    ../../src/api/Plugin.cpp \
					../../src/api/CommunicativeObject.cpp

