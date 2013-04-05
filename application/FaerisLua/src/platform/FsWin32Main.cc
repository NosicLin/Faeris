#include "FsMacros.h"
#include "common/FsGlobal.h"
#include "FsLuaEngine.h"
#include "io/FsPackage.h"
#include "io/FsVFS.h"
NS_FS_USE


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

	Package* package=Package::create("faeris.so.apk",Package::PACKAGE_ZIP);
	if(package==NULL)
	{
		FS_TRACE_WARN("create package failed");
	}
	else 
	{
		FS_TRACE_WARN("create package success");
	}
	VFS::mapPackage("",package);

	VFS::PrefixNameFilter* filter=VFS::PrefixNameFilter::create("assets/");
	VFS::addFilter(filter);

	/* default init */
	win->setSize(1024,800);
	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);

	render->setClearColor(Color(0,0,0));

	/*load file */
	engine->executeFile(loadfile);


	/* check where script stop running */
	Global::director()->setAutoSwapBuffers(true);
	Global::scheduler()->mainLoop();
	Global::sysDispatcher()->clearPending();
	Global::sysDispatcher()->dispatchSysEvent(SysDispatcher::EXIT);
	Global::sysDispatcher()->update(0,0);


	/* relese resource */
	engine->decRef();
	Global::moduleExit();
	return 0;
}


