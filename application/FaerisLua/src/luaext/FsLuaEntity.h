#ifndef _FS_LUA_ENTITY_H_
#define _FS_LUA_ENTITY_H_
#include "FsMacros.h"
#include "FsLuaMacros.h"
#include "luaext/FsLuaEntity.h"
#include "luaext/FsTEntity.h"
#include "entity/FsEntity.h"
#include "entity/FsColorQuad2D.h"

NS_FS_BEGIN
class LuaEntity:public TEntity<Entity>
{
	public:
		static LuaEntity* create()
		{
			return new LuaEntity;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_ENTITY_CLASS_NAME;
		}
	protected:
		LuaEntity(){}
		~LuaEntity(){}
};


class LuaColorQuad2D:public TEntity<ColorQuad2D>
{
	public:
		static LuaColorQuad2D* create(const Rect2D& rect,Color c)
		{
			LuaColorQuad2D* ret=new LuaColorQuad2D;
			ret->setRect(rect);
			ret->setColor(c);
			return ret;
		}
		static LuaColorQuad2D* create()
		{
			return new LuaColorQuad2D;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_COLOR_QUAD_CLASS_NAME;
		}
	protected:
		LuaColorQuad2D(){}
		~LuaColorQuad2D(){}
};

NS_FS_END

#endif /*_FS_LUA_ENTITY_H_*/

