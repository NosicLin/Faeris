#ifndef _FS_LUA_ENTITY_H_
#define _FS_LUA_ENTITY_H_

#include "FsMacros.h"
#include "FsLuaMacros.h"
#include "core/FsObject.h"
#include "luaext/FsLuaEntity.h"
#include "luaext/FsTEntity.h"
#include "entity/FsEntity.h"
#include "entity/FsColorQuad2D.h"
#include "entity/FsQuad2D.h"

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
			return FS_LUA_COLOR_QUAD2D_CLASS_NAME;
		}
	protected:
		LuaColorQuad2D(){}
		~LuaColorQuad2D(){}
};
class LuaQuad2D:public TEntity<Quad2D>
{
	public:
		static LuaQuad2D* create(const char* name)
		{
			LuaQuad2D* ret=new LuaQuad2D();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			return ret;
		}
		static LuaQuad2D* create(const char* name,const Rect2D& rect)
		{
			LuaQuad2D* ret=new LuaQuad2D();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			ret->setRect2D(rect);
			return ret;

		}
	public:
		virtual const char* className()
		{
			return FS_LUA_QUAD2D_CLASS_NAME;
		}
	protected:
		LuaQuad2D(){}
		~LuaQuad2D(){}
};

NS_FS_END

#endif /*_FS_LUA_ENTITY_H_*/











