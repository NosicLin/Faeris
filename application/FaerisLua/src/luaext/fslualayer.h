#ifndef _FS_LUA_LAYER_H_
#define _FS_LUA_LAYER_H_

#include "scene/FsLayer2D.h"
#include "scene/FsColorLayer.h"
#include "FsLuaMacros.h"

#include "luaext/FsTLuaLayer.h"


NS_FS_BEGIN

/* layer2d */
class LuaLayer2DName
{
	public:
		static const char* className()
		{
			return FS_LUA_LAYER2D_CLASS_NAME;
		}
};
typedef TLuaLayer<Layer2D,LuaLayer2DName> LuaLayer2D;


/* color layer */
class  ColorLayerName 
{
	public:
		static const char* className()
		{
			return FS_COLOR_LAYER_CLASS_NAME;
		}
};

typedef  TLuaLayer<ColorLayer,ColorLayerName> LuaColorLayer;
NS_FS_END 


#endif /*_FS_LUA_LAYER_H_*/
