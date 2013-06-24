
bin_PROGRAMS = PluginInterfaceCompiler

SUBDIRS = @subdirs@

INCLUDES = -I/usr/include/sigc++-2.0/


PluginInterfaceCompiler_SOURCES = 	src/core/Application.cpp \
						src/core/ConcretePluginManager.cpp \
                        src/core/main.cpp \
						src/api/CommunicativeObject.cpp \
						src/api/Plugin.cpp \
						$(NULL)

AM_CPPFLAGS = $(LIBSIGC_CFLAGS) -fPIC -g
PluginInterfaceCompiler_LDADD = $(LIBSIGC_LIBS) -ldl
