#include "graphics/FsRender.h"
#include "graphics/FsTexture2D.h"
#include "FsConfig.h"


NS_FS_BEGIN

const char* Render::className()
{
	return FS_RENDER_CLASS_NAME;
}
Render* Render::create()
{
	Render* ret=new Render;
	return ret;
}

int Render::sizeofUniformType(int type)
{
	int size;
	switch(type)
	{
		case U_F_1:
			size=sizeof(float)*1;
			break;
		case U_F_2:
			size=sizeof(float)*2;
			break;
		case U_F_3:
			size=sizeof(float)*3;
			break;
		case U_F_4:
			size=sizeof(float)*4;
			break;
		case U_I_1:
			size=sizeof(int)*1;
			break;
		case U_I_2:
			size=sizeof(int)*2;
			break;
		case U_I_3:
			size=sizeof(int)*3;
			break;
		case U_I_4:
			size=sizeof(int)*4;
			break;
		case U_UI_1:
			size=sizeof(uint)*1;
			break;
		case U_UI_2:
			size=sizeof(uint)*2;
			break;
		case U_UI_3:
			size=sizeof(uint)*3;
			break;
		case U_UI_4:
			size=sizeof(uint)*4;
			break;
		case U_M_2:
			size=sizeof(float)*4;
			break;
		case U_M_3:
			size=sizeof(float)*9;
			break;
		case U_M_4:
			size=sizeof(float)*16;
			break;
		default:
			size=-1;
	}
	return size;

}
int Render::uniformTypeComponent(int type)
{
	int compoents=0;
	switch(type)
	{
		case Render::U_F_1: 
		case Render::U_I_1:
		case Render::U_UI_1:
			compoents=1;
			break;
		case Render::U_F_2:
		case Render::U_I_2:
		case Render::U_UI_2:
			compoents=2;
			break;
		case Render::U_F_3:
		case Render::U_I_3:
		case Render::U_UI_3:
			compoents=3;
			break;
		case Render::U_F_4:
		case Render::U_I_4:
		case Render::U_UI_4:
			compoents=4;
			break;
		case U_M_2:
			compoents=4;
			break;
		case U_M_3:
			compoents=9;
			break;
		case U_M_4:
			compoents=16;
			break;
		default:
			compoents=-1;
			break;
	}
	return compoents;
}

void Render::setShadeMode(int mode)
{
	/* TODO */
}
void Render::setOpacity(float value)
{
	/*TODO*/
}


NS_FS_END

#if FS_CONFIG(FS_GL_RENDER) 
#include "platform/FsGLRender.cc"
#else 
#error "unsupport render platform"
#endif /*FS_GL_RENDER*/

