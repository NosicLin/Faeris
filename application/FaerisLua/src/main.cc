#include "FsMacros.h"
#include "common/FsGlobal.h"
#include "FsLuaEngine.h"

NS_FS_USE

static int s_quit(lua_State* L)
{
	Global::scheduler()->stop();
	return 0;
}

int main(int argc,char** argv)
{
	const char* loadfile="main.lua";
	if(argc==2)
	{
		loadfile=argv[1];
	}

	Global::moduleInit();

	/* get share object */
	Window* win=Global::window();
	Render* render=Global::render();

	LuaEngine* engine=LuaEngine::create();
	Global::setScriptEngine(engine);


	/* default init */
	win->setSize(1024,800);
	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);

	render->setClearColor(Color(255,255,0));


	/* set lua global */
	engine->setGlobalCFunction("g_quit",s_quit);
	engine->setGlobalUserType("g_render",render,"Render");
	engine->setGlobalUserType("g_window",win,"Window");

	/*load file */
	engine->executeFile(loadfile);


	/* check where script stop running */
	Global::scheduler()->mainLoop();
	Global::sysDispatcher()->clearPending();
	Global::sysDispatcher()->dispatchSysEvent(SysDispatcher::EXIT);
	Global::sysDispatcher()->update(0,0);


	/* relese resource */
	engine->decRef();
	Global::moduleExit();
	return 0;
}
