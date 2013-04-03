#include "common/FsGlobal.h"
#include "material/FsPositionAlphaTextureMaterial.h"
#include "material/FsPositionTextureMaterial.h"
#include "io/FsVFS.h"

NS_FS_BEGIN
Scheduler* Global::m_scheduler=NULL;
Director* Global::m_director=NULL;
Render* Global::m_render=NULL;
TouchDispatcher* Global::m_touchDispatcher=NULL;
SysDispatcher* Global::m_sysDispatcher=NULL;
Window* Global::m_window=NULL;
ScriptEngine* Global::m_scriptEngine=NULL;

TextureMgr* Global::m_textureMgr=NULL;
FontTTFDataMgr* Global::m_fontTTFDataMgr=NULL;
Sprite2DDataMgr* Global::m_sprite2DDataMgr=NULL;





bool  Global::moduleInit()
{
	/* init global value */
	VFS::moduleInit();
	m_scheduler=Scheduler::create();
	m_touchDispatcher=TouchDispatcher::create();
	m_sysDispatcher=SysDispatcher::create();
	m_director=Director::create();
	m_window=Window::create();
	m_render=Render::create();

	/* mgr */
	m_textureMgr=TextureMgr::create();
	m_fontTTFDataMgr=FontTTFDataMgr::create();
	m_sprite2DDataMgr=Sprite2DDataMgr::create();

	/* register scheduler target */

	m_scheduler->add(m_touchDispatcher,Scheduler::HIGH);
	m_scheduler->add(m_sysDispatcher,Scheduler::HIGH);

	m_scheduler->add(m_director,Scheduler::MIDDLE);
	m_scheduler->add(m_director,Scheduler::LOW);


	return true;

}
void Global::moduleExit()
{
	/* remove scheduler target */
	m_scheduler->remove(m_sysDispatcher,Scheduler::HIGH);
	m_scheduler->remove(m_touchDispatcher,Scheduler::HIGH);

	m_scheduler->remove(m_director,Scheduler::MIDDLE);
	m_scheduler->remove(m_director,Scheduler::LOW);


	m_render->forceDestroy();
	m_window->forceDestroy();
	m_director->forceDestroy();
	m_touchDispatcher->forceDestroy();
	m_sysDispatcher->forceDestroy();

	m_scheduler->forceDestroy();

	/* mgr */
	m_textureMgr->forceDestroy();
	m_fontTTFDataMgr->forceDestroy();
	m_sprite2DDataMgr->forceDestroy();

	/* material */
	PositionAlphaTextureMaterial::purgeShareMaterial();
	PositionTextureMaterial::purgeShareMaterial();
	VFS::moduleExit();
}
Scheduler* Global::scheduler()
{
	FS_SAFE_ADD_REF(m_scheduler);
	return m_scheduler;

}

Director* Global::director()
{
	FS_SAFE_ADD_REF(m_director);
	return m_director;
}

Render* Global::render()
{
	FS_SAFE_ADD_REF(m_render);
	return m_render;
}

TouchDispatcher* Global::touchDispatcher()
{
	FS_SAFE_ADD_REF(m_touchDispatcher);
	return m_touchDispatcher;
}
SysDispatcher* Global::sysDispatcher()
{
	FS_SAFE_ADD_REF(m_sysDispatcher);
	return m_sysDispatcher;
}

Window* Global::window()
{
	FS_SAFE_ADD_REF(m_window);
	return m_window;
}

ScriptEngine* Global::scriptEngine()
{
	FS_SAFE_ADD_REF(m_scriptEngine);
	return m_scriptEngine;
}
void Global::setScriptEngine(ScriptEngine* se)
{
	FS_SAFE_DEC_REF(m_scriptEngine);
	FS_SAFE_ADD_REF(se);
	m_scriptEngine=se;
}

TextureMgr* Global::textureMgr()
{
	FS_SAFE_ADD_REF(m_textureMgr);
	return m_textureMgr;
}

FontTTFDataMgr* Global::fontTTFDataMgr()
{
	FS_SAFE_ADD_REF(m_fontTTFDataMgr);
	return m_fontTTFDataMgr;
}

Sprite2DDataMgr* Global::sprite2DDataMgr()
{
	FS_SAFE_ADD_REF(m_sprite2DDataMgr);
	return m_sprite2DDataMgr;
}


NS_FS_END










