#ifndef _FS_GLOBAL_H_
#define _FS_GLOBAL_H_

#include "FsMacros.h"
#include "scheduler/FsScheduler.h"
#include "scene/FsDirector.h"
#include "graphics/FsRender.h"
#include "event/FsTouchDispatcher.h"
#include "event/FsSysDispatcher.h"
#include "sys/FsWindow.h"
#include "common/FsScriptEngine.h"
#include "mgr/FsTextureMgr.h"
#include "mgr/FsFontTTFDataMgr.h"
#include "mgr/FsSprite2DDataMgr.h"


NS_FS_BEGIN
class Global
{
	public:
		static bool moduleInit();
		static void moduleExit();

	public:
		static Scheduler* scheduler();
		static TouchDispatcher* touchDispatcher();
		static SysDispatcher* sysDispatcher();
		static Director* director();

		static Window* window();
		static Render* render();

		static ScriptEngine* scriptEngine();
		static void setScriptEngine(ScriptEngine* se);


		/* mgr */
		static TextureMgr* textureMgr();
		static FontTTFDataMgr* fontTTFDataMgr();
		static Sprite2DDataMgr* sprite2DDataMgr();

	private:
		static Scheduler* m_scheduler;
		static Director* m_director;
		static Render* m_render;
		static TouchDispatcher* m_touchDispatcher;
		static SysDispatcher* m_sysDispatcher;
		static Window* m_window;
		static ScriptEngine* m_scriptEngine;

		/* mgr */
		static TextureMgr* m_textureMgr;
		static FontTTFDataMgr* m_fontTTFDataMgr;
		static Sprite2DDataMgr* m_sprite2DDataMgr;


};
NS_FS_END 

#endif /*_FS_GLOBAL_H_*/






