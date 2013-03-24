#include "material/FsColorQuad2DMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN
static const char* color_program_vert_str=
"attribute vec3 a+_";

static Program* material_share_program=NULL;
static Program* useColorQuad2DProgram()
{
	return NULL;

}
static void unuseColorQuad2DProgram()
{
	assert(material_share_program);
	if(material_share_program->refCnt()==1)
	{
		material_share_program->decRef();
		material_share_program=NULL;
	}
	else 
	{
		material_share_program->decRef();
	}

}

ColorQuad2DMaterial* ColorQuad2DMaterial::create()
{
	ColorQuad2DMaterial* ret=new ColorQuad2DMaterial;
	return ret;
}

void ColorQuad2DMaterial::load(Render* r)
{
	configRender(r);
	r->setUniform(m_opacityLocation,Render::U_F_1,1,&this->m_opacity);
}

void ColorQuad2DMaterial::unload(Render* r)
{

}

ColorQuad2DMaterial::ColorQuad2DMaterial()
{
	m_opacity=1.0f;
	m_progam=useColorQuad2DProgram();
	m_opacityLocation=m_progam->getUniformLocation("u_opacity");
}
ColorQuad2DMaterial::~ColorQuad2DMaterial()
{
	unuseColorQuad2DProgram();
}

NS_FS_END


