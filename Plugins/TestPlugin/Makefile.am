AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = TestPlugin.plg

TestPlugin_plg_SOURCES = src/TestPlugin.cpp \
			    ../../src/api/Plugin.cpp \
				../../src/api/CommunicativeObject.cpp

TestPlugin_plg_LDFLAGS = -shared -fPIC
AM_CPPFLAGS = -fPIC -g
