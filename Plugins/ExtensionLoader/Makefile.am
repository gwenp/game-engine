AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = ExtensionLoader.plg


ExtensionLoader_plg_LDFLAGS = -shared -fPIC
ExtensionLoader_plg_LDADD = 

AM_CPPFLAGS = $(LUA_CFLAGS)
AM_CPPFLAGS += -fPIC

ExtensionLoader_plg_SOURCES = src/ExtensionLoader.cpp \
			    ../../src/api/Plugin.cpp \
				../../src/api/CommunicativeObject.cpp

