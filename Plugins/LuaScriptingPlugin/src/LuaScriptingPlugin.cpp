#include "LuaScriptingPlugin.hpp"

LuaScriptingPlugin::LuaScriptingPlugin(IApplication* app) : ITestPlugin(app, "LuaScriptingPlugin")
{
	int iErr = 0;
	_l = lua_open ();  // Open Lua

	_l = luaL_newstate();                        /* Create Lua state variable */
	luaL_openlibs(_l);                           /* Load Lua libraries */

	std::string scriptFile = "Plugins/LuaScriptingPlugin/script/plugin.lua";
	//TODO throw if file not found
	luaL_loadfile(_l, scriptFile.c_str());			/* Load but don't run the Lua script */

	lua_pcall(_l, 0, 0, 0);						/* PRIMING RUN. FORGET THIS AND YOU'RE TOAST */

}

LuaScriptingPlugin::~LuaScriptingPlugin()
{
	lua_close(_l);                               /* Clean up, free the Lua state var */
}

void LuaScriptingPlugin::onLoad()
{
	lua_getglobal(_l, "onLoad");                 /* Tell it to run callfuncscript.lua->square() */
	lua_pushlightuserdata(_l, getApplication());                       /* Submit 6 as the argument to square() */
	lua_pcall(_l, 1, 1, 0);                  /* Run the function */

	displayTestInformation();
}

void LuaScriptingPlugin::displayTestInformation()
{
	lua_getglobal(_l, "displayTestInformation");
	/* do the call (0 argument, 0 result) */
	if (lua_pcall(_l, 0, 0, 0) != 0) {
		printf("error running function `f': %s\n",lua_tostring(_l, -1));
	}
}

extern "C"
{
	Plugin* makePlugin(IApplication* app)
	{
		return new LuaScriptingPlugin(app);
	}
}
