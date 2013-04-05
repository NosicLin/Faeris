#include "FsMacros.h"
#include "common/FsGlobal.h"
#include "FsLuaEngine.h"
#include "io/FsPackage.h"
#include "io/FsVFS.h"
#include "util/FsPathUtil.h"
#include "util/FsScriptUtil.h"
#include "util/FsDict.h"
#include "util/FsArray.h"

#if FS_PLATFORM_OS(FS_OS_WIN32)
	#define FS_CONFIGURE_FILE "win32.fgame"
#elif FS_PLATFORM_OS(FS_OS_LINUX)
	#define FS_CONFIGURE_FILE "linux.fgame"
#endif 

NS_FS_USE


int main(int argc,char** argv)
{

	const char* config=FS_CONFIGURE_FILE;
	if(argc==2)
	{
		config=argv[1];
	}

	Global::moduleInit();

		/* get share object */
	Window* win=Global::window();
	Render* render=Global::render();

	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);
	render->setClearColor(Color(0,0,0));



	std::string dir_name=PathUtil::getDirName(config);
	VFS::setRoot(dir_name.c_str());

	std::string file_name=PathUtil::getFileName(config);

	FsFile* file=VFS::open(file_name.c_str());
	if(file==NULL)
	{
		goto error;
	}


	FsDict* dict=ScriptUtil::parseScript(file);
	file->decRef();



	if(!dict)
	{
		FS_TRACE_WARN("file(%s) is bad format",config);
		goto error;
	}

	Global::loadConfig(dict);

	FsDict* script=ScriptUtil::getDict(dict,"script");
	if(!script)
	{
		dict->decRef();
		goto error;
	}


	FsString* entry=ScriptUtil::getString(script,"entry");
	if(!entry)
	{
		FS_TRACE_WARN("Can't Find Script Entry");
		script->decRef();
		dict->decRef();
		goto error;
	}

	LuaEngine* engine=LuaEngine::create();
	Global::setScriptEngine(engine);
	engine->executeFile(entry->cstr());

	



	/* check where script stop running */
	Global::director()->setAutoSwapBuffers(true);
	Global::scheduler()->mainLoop();

	/* exit */
	Global::sysDispatcher()->clearPending();
	Global::sysDispatcher()->dispatchSysEvent(SysDispatcher::EXIT);
	Global::sysDispatcher()->update(0,0);


	/* relese resource */
	engine->decRef();


error:
	Global::moduleExit();
	return 0;
}


