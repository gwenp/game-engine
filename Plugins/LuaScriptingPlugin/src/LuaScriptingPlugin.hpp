#ifndef DEF_LUASCRIPTINGPLUGIN
#define DEF_LUASCRIPTINGPLUGIN

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "../../src/api/Interfaces/ITestPlugin.hpp"
#include <iostream>

class LuaScriptingPlugin : public ITestPlugin
{
public:
	LuaScriptingPlugin(IApplication* app);
	~LuaScriptingPlugin();

	void onLoad();

	void displayTestInformation();
private:
	lua_State *_l;
};

#endif /* DEF_LUASCRIPTINGPLUGIN */
