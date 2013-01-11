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
FsInt LoaderUtil::parseFrontSide(const FsChar* t)
{
	if(strcmp(t,"ccw")==0)
	{
		return Render::FRONT_CCW;
	}
	else if(strcmp(t,"cw")==0)
	{
		return Render::FRONT_CW;
	}
	return -1;
}
const FsChar* LoaderUtil::frontSideToStr(FsInt t)
{
	switch(t)
	{
		case Render::FRONT_CCW:
			return "ccw";
		case Render::FRONT_CW:
			return "cw";
		default:
			return "error";
	}
}

FsInt LoaderUtil::parseBlendEquation(const FsChar* str)
{
	FsInt ret;
	if(strcmp(str,"none")==0)
	{
		ret=Render::EQUATION_NONE;
	}
	else if(strcmp(str,"add")==0)
	{
		ret=Render::EQUATION_ADD;
	}
	else if(strcmp(str,"subtract")==0)
	{
		ret=Render::EQUATION_SUBTRACT;
	}
	else if(strcmp(str,"reverse_subtract")==0)
	{
		ret=Render::EQUATION_REVERSE_SUBTRACT;
	}
	else if(strcmp(str,"min")==0)
	{
		ret=Render::EQUATION_MIN;
	}
	else if(strcmp(str,"max")==0)
	{
		ret=Render::EQUATION_MAX;
	}
	else if(strcmp(str,"logic_op")==0)
	{
		ret=Render::EQUATION_LOGIC_OP;
	}
	else 
	{
		ret=-1;
	}
	return ret;
}
const FsChar* LoaderUtil::blendEquationToStr(FsInt type)
{
	switch(type)
	{
		case Render::EQUATION_NONE:
			return "none";
		case Render::EQUATION_ADD:
			return "add";
		case Render::EQUATION_SUBTRACT:
			return "subtract";
		case Render::EQUATION_REVERSE_SUBTRACT:
			return "reverse_substract";
		case Render::EQUATION_MIN:
			return "min";
		case Render::EQUATION_MAX:
			return "max";
		case Render::EQUATION_LOGIC_OP:
			return "logic_op";
		default:
			return "error";
	}
}
FsInt LoaderUtil::parseShadeMode(const FsChar* str)
{
	FsInt ret;
	if(strcmp(str,"smooth")==0)
	{
		ret=Render::SHADE_MODE_SMOOTH;
	}
	else if(strcmp(str,"flat")==0)
	{
		ret=Render::SHADE_MODE_FLAT;
	}
	else 
	{
		ret=-1;
	}
	return ret;
}
const FsChar* LoaderUtil::shadeModeToStr(FsInt t)
{
	switch(t)
	{
		case Render::SHADE_MODE_SMOOTH:
			return "smooth";
		case Render::SHADE_MODE_FLAT:
			return "flat";
		default:
			return "error";
	}
}
FsInt LoaderUtil::parseBlendFactor(const FsChar* str)
{
	FsInt ret;
	if(strcmp(str,"src_alpha")==0)
	{
		ret=Render::FACTOR_SRC_ALPHA;
	}
	else if(strcmp(str,"one_minus_src_alpha")==0)
	{
		ret=Render::FACTOR_ONE_MINUS_SRC_ALPHA;
	}
	else if(strcmp(str,"zero")==0)
	{
		ret=Render::FACTOR_ZERO;
	}
	else if(strcmp(str,"one")==0)
	{
		ret=Render::FACTOR_ONE;
	}
	else if(strcmp(str,"src_color")==0)
	{
		ret=Render::FACTOR_SRC_COLOR;
	}
	else if(strcmp(str,"one_minus_src_color")==0)
	{
		ret=Render::FACTOR_ONE_MINUS_SRC_COLOR;
	}
	else if(strcmp(str,"dst_color")==0)
	{
		ret=Render::FACTOR_DST_COLOR;
	}
	else if(strcmp(str,"one_minus_dst_color")==0)
	{
		ret=Render::FACTOR_ONE_MINUS_DST_COLOR;
	}
	else if(strcmp(str,"dst_alpha")==0)
	{
		ret=Render::FACTOR_DST_ALPHA;
	}
	else if(strcmp(str,"one_minus_dst_alpha")==0)
	{
		ret=Render::FACTOR_ONE_MINUS_DST_ALPHA;
	}
	else if(strcmp(str,"src_alpha_saturate")==0)
	{
		ret=Render::FACTOR_SRC_ALPHA_SATURATE;
	}
	else 
	{
		ret=-1;
	}
	return ret;
}


const FsChar* LoaderUtil::blendFactorToStr(FsInt factor)
{
	switch(factor)
	{
		case Render::FACTOR_ZERO:
			return "zero";
		case Render::FACTOR_ONE:
			return "one";
		case Render::FACTOR_SRC_COLOR:
			return "src_color";
		case Render::FACTOR_ONE_MINUS_SRC_COLOR:
			return "one_minus_src_color";
		case Render::FACTOR_DST_COLOR:
			return "dst_color";
		case Render::FACTOR_ONE_MINUS_DST_COLOR:
			return "one_minus_dst_color";
		case Render::FACTOR_SRC_ALPHA:
			return "src_alpha";
		case Render::FACTOR_ONE_MINUS_SRC_ALPHA:
			return "one_minus_src_alpha";
		case Render::FACTOR_DST_ALPHA:
			return "dst_alpha";
		case Render::FACTOR_ONE_MINUS_DST_ALPHA:
			return "one_minus_dst_alpha";
		case Render::FACTOR_SRC_ALPHA_SATURATE:
			return "src_alpha_saturate";
		default:
			return "error";
	}
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

const FsChar* LoaderUtil::uniformTypeToStr(FsInt type)
{
	switch(type)
	{
		case Render::U_F_1:
			return "float";
		case Render::U_F_2:
			return "fvec2";
		case Render::U_F_3:
			return "fvec3";
		case Render::U_F_4:
			return "fvec4";
		case Render::U_I_1:
			return "int";
		case Render::U_I_2:
			return "ivec2";
		case Render::U_I_3:
			return "ivec3";
		case Render::U_I_4:
			return "ivec4";
		case Render::U_UI_1:
			return "uint";
		case Render::U_UI_2:
			return "uvec2";
		case Render::U_UI_3:
			return "uvec3";
		case Render::U_UI_4:
			return "uvec4";
		case Render::U_M_2:
			return "mat2";
		case Render::U_M_3:
			return "mat3";
		case Render::U_M_4:
			return "mat4";
		default:
			return "error";
	}
}

NS_FS_END



















