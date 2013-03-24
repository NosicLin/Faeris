#include "common/FsGlobal.h"
#include "luaext/FsLuaScene.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

LuaScene* LuaScene::create()
{
	LuaScene* ret=new LuaScene;
	return ret;
}

void LuaScene::enter()
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onEnter",1,0,"f",this))
	{
		Scene::enter();
	}
}
void LuaScene::exit()
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onExit",1,0,"f",this))
	{
		Scene::exit();
	}
}
void LuaScene::update(float dt)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onUpdate",2,0,"fn",this,dt))
	{
		Scene::update(dt);
	}
}
void LuaScene::draw(Render* render)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();

	if(!se->callFunctionInTable(m_data,"onDraw",2,0,"ff",this,render))
	{
		Scene::draw(render);
	}
}

void LuaScene::touchBegin(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onTouchBegin",3,0,"fnn",this,x,y))
	{
		Scene::touchBegin(x,y);
	}
}

void LuaScene::touchMove(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onTouchMove",3,0,"fnn",this,x,y))
	{
		Scene::touchMove(x,y);
	}

}

void LuaScene::touchEnd(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_data,"onTouchEnd",3,0,"fnn",this,x,y))
	{
		Scene::touchEnd(x,y);
	}
}

const char*  LuaScene::className()
{
	return FS_LUA_SCENE_CLASS_NAME;

}

LuaScene::LuaScene()
{
}

LuaScene::~LuaScene()
{
}


NS_FS_END




