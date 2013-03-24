#ifndef _FS_LUA_SCENE_H_
#define _FS_LUA_SCENE_H_ 

#include "scene/FsScene.h"
#include "FsLuaMacros.h"
NS_FS_BEGIN
class LuaScene:public Scene 
{
	public:
		static LuaScene* create();
	public:
		/* inherit Scene */
		virtual void enter();
		virtual void exit();
		virtual void update(float dt);
		virtual void draw(Render* render);
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);
		/*
		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);
		*/

	public:
		void onEnter(){Scene::enter();}
		void onExit(){Scene::exit();}
		void onUpdate(float dt){Scene::update(dt);}
		void onDraw(Render* render){Scene::draw(render);}
		void onTouchBegin(float x,float y){Scene::touchBegin(x,y);}
		void onTouchEnd(float x,float y){Scene::touchEnd(x,y);}
		void onTouchMove(float x,float y){Scene::touchMove(x,y);}

		/* inherit FsObject */
		virtual const char* className();

	protected:
		LuaScene();
		~LuaScene();
};
NS_FS_END
#endif /*_LUA_SCENE_H_*/

