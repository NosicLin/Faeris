#ifndef _FS_LUA_T_LAYER_H_
#define _FS_LUA_T_LAYER_H_

#include "scene/FsLayer.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN
template<typename T_F,typename T_NAME>
class  TLuaLayer:public T_F 
{
	public:
		virtual void update(float dt)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(m_data,"onUpdate",2,0,"fn",this,dt))
			{
				T_F::update(dt);
			}
		}
		virtual void draw(Render* render)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();

			if(!se->callFunctionInTable(m_data,"onDraw",2,0,"ff",this,render))
			{
				T_F::draw(render);
			}
		}

		virtual bool touchBegin(float x,float y)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(m_data,"onTouchBegin",3,1,"fnn",this,x,y))
			{
				return T_F::touchBegin(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		virtual bool touchMove(float x,float y)
		{


			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(m_data,"onTouchBegin",3,1,"fnn",this,x,y))
			{
				return T_F::touchBegin(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;

		}
		virtual bool touchEnd(float x,float y)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(m_data,"onTouchEnd",3,1,"fnn",this,x,y))
			{
				return  T_F::touchEnd(x,y);
			}
			bool ret=se->toBoolean(-1);
			se->pop();
			return ret;
		}
		/*
		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);
		*/
	public:
		/* inherit T_F */
		void onUpdate(float dt)
		{
			T_F::update(dt);
		}
		bool onTouchBegin(float x,float y)
		{
			return T_F::touchBegin(x,y);
		}
		bool onTouchEnd(float x,float y)
		{
			return T_F::touchEnd(x,y);
		}
		bool onTouchMove(float x,float y)
		{
			return T_F::touchMove(x,y);
		}

		/* 
		   bool onTouchesBegin(Vector2* points,int num);
		   bool onTouchesMove(Vector2* points,int num);
		   bool onTouchesEnd(Vector2* points,int num);
		   */

		/* inherit FsObject */
		virtual const char* className()
		{
			return T_NAME::className();
		}
};

NS_FS_END


#endif 
