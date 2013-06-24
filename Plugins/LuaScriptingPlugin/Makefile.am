AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = LuaScriptingPlugin.plg


LuaScriptingPlugin_plg_LDFLAGS = -shared -fPIC
LuaScriptingPlugin_plg_LDADD = $(LUA_LIBS)

AM_CPPFLAGS = $(LUA_CFLAGS)
AM_CPPFLAGS += -fPIC

LuaScriptingPlugin_plg_SOURCES = src/LuaScriptingPlugin.cpp \
			    ../../src/api/Plugin.cpp \
				../../src/api/CommunicativeObject.cpp

