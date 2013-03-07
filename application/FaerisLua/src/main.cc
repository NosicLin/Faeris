#include "sys/FsWindow.h"
#include "sys/FsFrame.h"
#include "graphics/FsRender.h"
#include "loader/FsMeshLoader.h"
#include "FsLuaEngine.h"


NS_FS_USE

static int s_quit_flags=0;
static int s_quit(lua_State* L)
{
	Frame::shareFrame()->stop();
	s_quit_flags=1;
	return 0;
}

int main(int argc,char** argv)
{
	const char* loadfile="main.lua";
	if(argc==2)
	{
		loadfile=argv[1];
	}

	/* get share object */
	Window* win=Window::shareWindow();
	Render* render=Render::shareRender();
	Frame* frame=Frame::shareFrame();
	LuaEngine* engine=LuaEngine::shareEngine();


	/* default init */
	win->show();
	win->setSize(640,480);
	win->setPosition(100,100);
	render->setRenderTarget(win);

	render->setClearColor(Color(255,255,0));


	/* set lua global */
	engine->setGlobalCFunction("g_quit",s_quit);
	engine->setGlobalUserType("g_render",render,"Render");
	engine->setGlobalUserType("g_frame",frame,"Frame");
	engine->setGlobalUserType("g_window",win,"Window");



	frame->setFPS(60);

	/*load file */
	engine->executeFile(loadfile);


	/* check where script stop running */
	if(!s_quit_flags)
	{
		frame->start();
	}

	/* relese resource */
	LuaEngine::purgeShareEngine();
	Render::purgeShareRender();
	Window::purgeShareWindow();
	Frame::purgeShareFrame();
	return 0;
}
