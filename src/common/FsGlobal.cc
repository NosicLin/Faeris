#include "common/FsGlobal.h"
#include "material/FsPositionAlphaTextureMaterial.h"
#include "material/FsPositionTextureMaterial.h"
#include "io/FsVFS.h"
#include "io/FsPackage.h"
#include "util/FsDict.h"
#include "util/FsArray.h"
#include "util/FsScriptUtil.h"

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


/* config */

void Global::loadConfig(FsDict* dict)
{
	FsDict* mgr=ScriptUtil::getDict(dict,"mgr"); 
	if(mgr)
	{
		configManager(mgr);
	}
	FS_SAFE_DEC_REF(mgr);

	FsDict* vfs=ScriptUtil::getDict(dict,"vfs");
	if(vfs)
	{
		configVFS(vfs);
	}
	FS_SAFE_DEC_REF(vfs);


	FsDict* win=ScriptUtil::getDict(dict,"win");
	if(win)
	{
		configWin(win);
	}
	FS_SAFE_DEC_REF(win);

	FsDict* env=ScriptUtil::getDict(dict,"evn");
	if(env)
	{
		configENV(env);
	}
	FS_SAFE_DEC_REF(env);
}


void Global::configManager(FsDict* mgr)
{
	/* texture mgr */
	FsDict* texmgr=ScriptUtil::getDict(mgr,"textureMgr");
	if(texmgr)
	{
		if(m_textureMgr)
		{
			configResourceMgr(m_textureMgr,texmgr);
		}
	}
	FS_SAFE_DEC_REF(texmgr);


	/* FontTTFDataMgr */
	FsDict* fontmgr=ScriptUtil::getDict(mgr,"fontTTFDataMgr");
	if(fontmgr)
	{
		if(m_fontTTFDataMgr)
		{
			configResourceMgr(m_fontTTFDataMgr,fontmgr);
		}
	}
	FS_SAFE_DEC_REF(fontmgr);


	/* Sprite2DDataMgr */
	FsDict* spritemgr=ScriptUtil::getDict(mgr,"sprite2DDataMgr");
	if(spritemgr)
	{
		if(m_sprite2DDataMgr)
		{
			configResourceMgr(m_sprite2DDataMgr,spritemgr);
		}
	}
	FS_SAFE_DEC_REF(spritemgr);
}


void Global::configResourceMgr(ResourceMgr* mgr,FsDict* dict)
{
	FsArray* array=ScriptUtil::getArray(dict,"searchPath");
	if(!array)
	{
		return;
	}

	int path_nu=array->size();
	for(int i=0;i<path_nu;i++)
	{
		FsString* s_path=ScriptUtil::getString(array,i);
		if(s_path)
		{
			mgr->addSearchPath(s_path->cstr());
		}
		FS_SAFE_DEC_REF(s_path);
	}
	array->decRef();
}
void Global::configVFS(FsDict* dict)
{
	/* filter */
	FsArray* filters=ScriptUtil::getArray(dict,"nameFilter");
	if(filters)
	{
		int filter_nu=filters->size();
		for(int i=0;i<filter_nu;i++)
		{
			FsDict* f=ScriptUtil::getDict(filters,i);
			if(f)
			{
				FsString* type= ScriptUtil::getString(f,"type");
				if(!type)
				{
					f->decRef();
					continue;
				}

				if(type->equal("prefix"))
				{
					FsString* value=ScriptUtil::getString(f,"value");
					if(value)
					{
						VFS::PrefixNameFilter* prefix_filter=VFS::PrefixNameFilter::create(value->cstr());
						VFS::addFilter(prefix_filter);
					}
					FS_SAFE_DEC_REF(value);
				}
				FS_SAFE_DEC_REF(type);
			}
			FS_SAFE_DEC_REF(f);
		}
	}
	FS_SAFE_DEC_REF(filters);

	/* package */
	FsArray* map_package=ScriptUtil::getArray(dict,"mapPackage");
	if(map_package)
	{
		int package_nu=map_package->size();
		for(int i=0;i<package_nu;i++)
		{
			FsDict* p=ScriptUtil::getDict(map_package,i);
			if(!p) continue;

			FsString*  map_path=ScriptUtil::getString(p,"mapPath");
			FsString*  map_type=ScriptUtil::getString(p,"packageType");
			FsString*  map_url=ScriptUtil::getString(p,"url");
			if(map_path&&map_type&&map_url)
			{
				if(map_type->equal("zip"))
				{
					Package* package=Package::create(map_url->cstr(),Package::PACKAGE_ZIP);
					if(package)
					{
						VFS::mapPackage(map_path->cstr(),package);
					}
					FS_SAFE_DEC_REF(package);
				}
				else if(map_type->equal("res"))
				{
				}
			}

			FS_SAFE_DEC_REF(map_path);
			FS_SAFE_DEC_REF(map_type);
			FS_SAFE_DEC_REF(map_url);
			FS_SAFE_DEC_REF(p);
		}
	}
	FS_SAFE_DEC_REF(map_package);
}

void Global::configWin(FsDict* dict)
{
	int width,height;

	if(ScriptUtil::getInteger(dict,"width",&width)&&
		ScriptUtil::getInteger(dict,"height",&height))
	{
		m_window->setSize(width,height);
	}

	FsString* caption=ScriptUtil::getString(dict,"caption");
	if(caption)
	{
		m_window->setCaption(caption->cstr());
	}
	FS_SAFE_DEC_REF(caption);
	
}

void Global::configENV(FsDict* dict)
{
	/* TODO */
}


NS_FS_END






































