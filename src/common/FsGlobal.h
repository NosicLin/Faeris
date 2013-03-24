#ifndef _FS_GLOBAL_H_
#define _FS_GLOBAL_H_

#include "FsMacros.h"
#include "scheduler/FsScheduler.h"
#include "scene/FsDirector.h"
#include "graphics/FsRender.h"
#include "event/FsTouchDispatcher.h"
#include "sys/FsWindow.h"
#include "common/FsScriptEngine.h"


NS_FS_BEGIN
class Global
{
	public:
		static bool moduleInit();
		static void moduleExit();

	public:
		static Scheduler* scheduler();
		static TouchDispatcher* touchDispatcher();
		static Director* director();

		static Window* window();
		static Render* render();

		static ScriptEngine* scriptEngine();
		static void setScriptEngine(ScriptEngine* se);

	private:
		static Scheduler* m_scheduler;
		static Director* m_director;
		static Render* m_render;
		static TouchDispatcher* m_touchDispatcher;
		static Window* m_window;
		static ScriptEngine* m_scriptEngine;


};
NS_FS_END 

#endif /*_FS_GLOBAL_H_*/

