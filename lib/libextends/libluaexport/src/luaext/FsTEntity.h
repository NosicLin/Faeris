#ifndef _FS_T_ENTITY_H_
#define _FS_T_ENTITY_H_

#include "FsMacros.h"

#include "stage/entity/FsEntity.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

template <typename T_F>
class TEntity:public T_F 
{
	public:
		virtual void update(float dt)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onUpdate",2,0,"fn",this,dt))
			{
				T_F::update(dt);
			}
		}

		virtual void draw(Render* r,bool updateMatrix=true)
		{
			LuaEngine* se=(LuaEngine*)Global::scriptEngine();
			if(!se->callFunctionInTable(T_F::m_scriptData,"onDraw",2,0,"ff",this,r))
			{
				T_F::draw(r,updateMatrix);
			}
		}

	public:
		virtual void onUpdate(float dt)
		{
			T_F::update(dt);
		}
		virtual void onDraw(Render* r)
		{
			T_F::draw(r,true);
		}
};

NS_FS_END


#endif /*_FS_T_ENTITY_H_*/

