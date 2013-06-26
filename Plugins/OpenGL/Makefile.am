AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = OpenGL.plg


OpenGL_plg_LDFLAGS = -shared -fPIC
OpenGL_plg_LDADD = $(GL_LIBS) $(GLEW_LIBS) $(GLFW_LIBS)

AM_CPPFLAGS = $(GL_CFLAGS) $(GLEW_CFLAGS) $(GLFW_CFLAGS)
AM_CPPFLAGS += -fPIC -g

OpenGL_plg_SOURCES = src/OpenGL.cpp \
				    ../../src/api/Plugin.cpp \
					../../src/api/CommunicativeObject.cpp

