#include "material/FsColorQuad2DMaterial.h"

static const char* color_program_vert_str=
"attribute vec3 a+_

ColorQuad2DMaterial* ColorQuad2DMaterial::create()
{
	ColorQuad2DMaterial* ret=new ColorQuad2DMaterial;
	return ret;
}

void ColorQuad2DMaterial::load(Render* r)
{
	configRender(r);
	render->setUniform(m_opacityLocation,Render::U_F_1,1,&this->m_opacity);
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



