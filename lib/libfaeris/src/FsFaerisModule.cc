#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "scheduler/FsScheduler.h"
#include "stage/FsDirector.h"
#include "graphics/FsRender.h"
#include "sys/event/FsTouchDispatcher.h"
#include "sys/event/FsSysDispatcher.h"
#include "sys/FsWindow.h"
#include "extends/FsScriptEngine.h"
#include "mgr/FsTextureMgr.h"
#include "mgr/FsFontTTFDataMgr.h"
#include "mgr/FsSprite2DDataMgr.h"

#include "graphics/material/FsMat_V4F_T2F_A1F.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"

NS_FS_BEGIN

int FsFaeris_ModuleInit()
{
	VFS::moduleInit();

	Scheduler* scheduler=Scheduler::create();
	Global::setScheduler(scheduler);


	TouchDispatcher* touch_dispatcher=TouchDispatcher::create();
	Global::setTouchDispatcher(touch_dispatcher);


	SysDispatcher* sys_dispatcher=SysDispatcher::create();
	Global::setSysDispatcher(sys_dispatcher);

	Director* director=Director::create();
	Global::setDirector(director);


	Window* window=Window::create();
	Global::setWindow(window);

	Render* render=Render::create();
	Global::setRender(render);

	TextureMgr* tex_mgr=TextureMgr::create();
	Global::setTextureMgr(tex_mgr);


	FontTTFDataMgr* font_mgr=FontTTFDataMgr::create();
	Global::setFontTTFDataMgr(font_mgr);

	Sprite2DDataMgr* sprite_mgr=Sprite2DDataMgr::create();
	Global::setSprite2DDataMgr(sprite_mgr);



	/* register scheduler target */
	scheduler->add(touch_dispatcher,Scheduler::HIGH);
	scheduler->add(sys_dispatcher,Scheduler::HIGH);

	scheduler->add(director,Scheduler::MIDDLE);
	scheduler->add(director,Scheduler::LOW);

	/* set Global */
	

	
	
	
	
	
	
	

	return 0;
}


int FsFaeris_ModuleExit()
{
	Scheduler* scheduler=Global::scheduler();
	TouchDispatcher* touch_dispatcher=Global::touchDispatcher();
	SysDispatcher* sys_dispatcher=Global::sysDispatcher();

	Director* director=Global::director();
	Window* window=Global::window();
	Render* render=Global::render();

	TextureMgr* tex_mgr=Global::textureMgr();
	FontTTFDataMgr* font_mgr=Global::fontTTFDataMgr();
	Sprite2DDataMgr* sprite_mgr=Global::sprite2DDataMgr();




	/* remove scheduler target */
	scheduler->remove(sys_dispatcher,Scheduler::HIGH);
	scheduler->remove(touch_dispatcher,Scheduler::HIGH);
	scheduler->remove(director,Scheduler::MIDDLE);
	scheduler->remove(director,Scheduler::LOW);




	render->forceDestroy();
	window->forceDestroy();
	director->forceDestroy();
	touch_dispatcher->forceDestroy();
	sys_dispatcher->forceDestroy();

	scheduler->forceDestroy();

	/* mgr */
	tex_mgr->forceDestroy();
	font_mgr->forceDestroy();
	sprite_mgr->forceDestroy();

	/* material */
	Mat_V4F_T2F_A1F::purgeShareMaterial();
	Mat_V4F_T2F::purgeShareMaterial();
	VFS::moduleExit();



	/* clear global value */
	Global::dropScheduler();
	Global::dropTouchDispatcher();
	Global::dropSysDispatcher();
	Global::dropDirector();
	Global::dropWindow();
	Global::dropRender();
	Global::dropTextureMgr();
	Global::dropFontTTFDataMgr();
	Global::dropSprite2DDataMgr();
	return 0;
}

void FsFaeris_ConfigResourceMgr(ResourceMgr* mgr,FsDict* dict)
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

int FsFaeris_LoadConfig(FsDict* dict)
{
	FsDict* mgr=ScriptUtil::getDict(dict,"mgr"); 
	if(mgr)
	{
		FsFaeris_ConfigManager(mgr);
	}
	FS_SAFE_DEC_REF(mgr);

	FsDict* vfs=ScriptUtil::getDict(dict,"vfs");
	if(vfs)
	{
		FsFaeris_ConfigVFS(vfs);
	}
	FS_SAFE_DEC_REF(vfs);


	FsDict* win=ScriptUtil::getDict(dict,"win");
	if(win)
	{
		FsFaeris_ConfigWin(win);
	}
	FS_SAFE_DEC_REF(win);

	FsDict* env=ScriptUtil::getDict(dict,"evn");
	if(env)
	{
		FsFaeris_ConfigENV(env);
	}
	FS_SAFE_DEC_REF(env);
	return 0;
}



int FsFaeris_ConfigManager(FsDict* dict)
{
	/* texture mgr */
	FsDict* texmgr=ScriptUtil::getDict(dict,"textureMgr");
	if(texmgr)
	{
		TextureMgr* mgr=Global::textureMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,texmgr);
		}
		FS_SAFE_DEC_REF(mgr);
	}
	FS_SAFE_DEC_REF(texmgr);


	/* FontTTFDataMgr */
	FsDict* fontmgr=ScriptUtil::getDict(dict,"fontTTFDataMgr");
	if(fontmgr)
	{
		FontTTFDataMgr* mgr=Global::fontTTFDataMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,fontmgr);
		}
		FS_SAFE_DEC_REF(mgr);
	}
	FS_SAFE_DEC_REF(fontmgr);


	/* Sprite2DDataMgr */
	FsDict* spritemgr=ScriptUtil::getDict(dict,"sprite2DDataMgr");
	if(spritemgr)
	{
		Sprite2DDataMgr* mgr=Global::sprite2DDataMgr();
		if(mgr)
		{
			FsFaeris_ConfigResourceMgr(mgr,spritemgr);
		}
		FS_SAFE_DEC_REF(mgr);
	}
	FS_SAFE_DEC_REF(spritemgr);
	return 0;
}

int FsFaeris_ConfigVFS(FsDict* dict)
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
				else if(map_type->equal("fgz"))
				{
					Package* package=Package::create(map_url->cstr(),Package::PACKAGE_FGZ);
					if(package)
					{
						VFS::mapPackage(map_path->cstr(),package);
					}
					FS_SAFE_DEC_REF(package);
				}
			}

			FS_SAFE_DEC_REF(map_path);
			FS_SAFE_DEC_REF(map_type);
			FS_SAFE_DEC_REF(map_url);
			FS_SAFE_DEC_REF(p);
		}
	}
	FS_SAFE_DEC_REF(map_package);
	return 0;
}

int FsFaeris_ConfigWin(FsDict* dict)
{
	int width,height;
	Window* win=Global::window();
	if(win==NULL)
	{
		return 0;
	}

	if(ScriptUtil::getInteger(dict,"width",&width)&&
			ScriptUtil::getInteger(dict,"height",&height))
	{

		win->setSize(width,height);
	}

	FsString* caption=ScriptUtil::getString(dict,"caption");
	if(caption)
	{
		win->setCaption(caption->cstr());
	}
	FS_SAFE_DEC_REF(caption);
	FS_SAFE_DEC_REF(win);
	return 0;
}

int FsFaeris_ConfigENV(FsDict* dict)
{
	/*TODO*/
	return 0;
}



NS_FS_END




























