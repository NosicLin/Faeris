#include <string.h>
#include "loader/FsLoaderUtil.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
FsInt LoaderUtil::parseFsType(const FsChar* t)
{
	if(strcmp(t,"float")==0)
	{
		return FS_FLOAT;
	}
	else if(strcmp(t,"int")==0)
	{
		return FS_INT;
	}
	else if(strcmp(t,"int8")==0)
	{
		return FS_INT8;
	}
	else if(strcmp(t,"int16")==0)
	{
		return FS_INT16;
	}
	else if(strcmp(t,"int32")==0)
	{
		return FS_INT32;
	}
	else if(strcmp(t,"uint8")==0)
	{
		return FS_UINT8;
	}
	else if(strcmp(t,"uint16")==0)
	{
		return FS_UINT16;
	}
	else if(strcmp(t,"uint32")==0)
	{
		return FS_UINT32;
	}
	return -1;
}
FsInt LoaderUtil::parseUniformType(const FsChar* t)
{
	if(strcmp(t,"float")==0)
	{
		return Render::U_F_1;
	}
	else if(strcmp(t,"fvec2")==0)
	{
		return Render::U_F_2;
	}
	else if(strcmp(t,"fvec3")==0)
	{
		return Render::U_F_3;
	}
	else if(strcmp(t,"fvec4")==0)
	{
		return Render::U_F_4;
	}
	else if(strcmp(t,"int")==0)
	{
		return Render::U_I_1;
	}
	else if(strcmp(t,"ivec2")==0)
	{
		return Render::U_I_2;
	}
	else if(strcmp(t,"ivec3")==0)
	{
		return Render::U_I_3;
	}
	else if(strcmp(t,"ivec4")==0)
	{
		return Render::U_I_4 ;
	}
	else if(strcmp(t,"uint")==0)
	{
		return Render::U_UI_1;
	}
	else if(strcmp(t,"uvec2")==0)
	{
		return Render::U_UI_2;
	}
	else if(strcmp(t,"uvec3")==0)
	{
		return Render::U_UI_3;
	}
	else if(strcmp(t,"uvec4")==0)
	{
		return Render::U_UI_4;
	}
	else if(strcmp(t,"mat2")==0)
	{
		return Render::U_M_2;
	}
	else if(strcmp(t,"mat3")==0)
	{
		return Render::U_M_3;
	}
	else if(strcmp(t,"mat4")==0)
	{
		return Render::U_M_4;
	}
	return -1;
}

NS_FS_END

