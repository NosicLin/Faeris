#include "material/FsColorQuad2DMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN
static const char color_program_vert_str[]=
"#ifdef GL_ES						\n\
precision lowp float;				\n\
#endif								\n\
uniform float u_opacity; 			\n\
varying vec4 v_fragmentColor;       \n\
void main()   						\n\
{									\n\
	gl_Position=ftransform();		\n\
	v_fragmentColor=vec4(gl_Color.rgb,gl_Color.a*u_opacity); \n\
}  									\n\
";

static const char color_program_frag_str[]=
"varying vec4 v_fragmentColor; 			\n\
void main() 					        \n\
{										\n\
	gl_FragColor=v_fragmentColor;		\n\
}										\n\
";

	


static Program* material_share_program=NULL;
static Program* useColorQuad2DProgram()
{
	if(material_share_program==NULL)
	{
		int length_vert=sizeof(color_program_vert_str);
		int length_frag=sizeof(color_program_frag_str);
		material_share_program=Program::create(color_program_vert_str,length_vert,
												color_program_frag_str,length_frag);
		if(material_share_program)
		{
			material_share_program->addUniform("u_opacity");
		}
		return material_share_program;
	}
	material_share_program->addRef();
	return material_share_program;
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
	r->setProgram(m_program);
	r->setUniform(m_opacityLocation,Render::U_F_1,1,&this->m_opacity);
}

void ColorQuad2DMaterial::unload(Render* r)
{

}

ColorQuad2DMaterial::ColorQuad2DMaterial()
{
	m_opacity=1.0f;
	m_opacityLocation=-1;
	m_program=useColorQuad2DProgram();
	if(m_program==NULL)
	{
		FS_TRACE_WARN("Create Program Failed");
	}
	else 
	{
		m_opacityLocation=m_program->getUniformLocation("u_opacity");
	}
	setDepthTest(false);

}

ColorQuad2DMaterial::~ColorQuad2DMaterial()
{
	unuseColorQuad2DProgram();
}

NS_FS_END


