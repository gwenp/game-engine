AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ -I/usr/include/sigc++-2.0/

bin_PROGRAMS = TextureRegistrar.plg

TextureRegistrar_plg_LDFLAGS = -shared -fPIC
TextureRegistrar_plg_LDADD = $(GL_LIBS) $(GLEW_LIBS) $(GLFW_LIBS) $(IL_LIBS) $(LIBSIGC_LIBS)

AM_CPPFLAGS = $(GL_CFLAGS) $(GLEW_CFLAGS) $(GLFW_CFLAGS) $(IL_CFLAGS) $(LIBSIGC_CFLAGS)
AM_CPPFLAGS += -fPIC -g

TextureRegistrar_plg_SOURCES = src/TextureRegistrar.cpp \
					src/ImageLoader.cpp \
				    ../../src/api/Plugin.cpp \
					../../src/api/CommunicativeObject.cpp

