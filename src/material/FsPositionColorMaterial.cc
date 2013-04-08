#include "material/FsPositionColorMaterial.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN
static const char color_program_vert_str[]=
"uniform mat4 u_mvp;					\n\
uniform float u_opacity; 				\n\
varying vec4 v_fragmentColor;			\n\
attribute vec4 a_position;				\n\
attribute vec4 a_color;					\n\
void main()   							\n\
{										\n\
	gl_Position=u_mvp*a_position;		\n\
	v_fragmentColor=vec4(a_color.rgb,a_color.a*u_opacity); \n\
}  										\n\
";

static const char color_program_frag_str[]=
"varying vec4 v_fragmentColor; 			\n\
void main() 					        \n\
{										\n\
	gl_FragColor=v_fragmentColor;		\n\
}										\n\
";

	

static PositionColorMaterial* s_share_material=NULL;

PositionColorMaterial* PositionColorMaterial::shareMaterial()
{
	if(s_share_material==NULL)
	{
		s_share_material = PositionColorMaterial::create();
	}

	FS_SAFE_ADD_REF(s_share_material);
	return s_share_material;
}

PositionColorMaterial* PositionColorMaterial::create()
{
	PositionColorMaterial* ret=new PositionColorMaterial;
	return ret;
}


void PositionColorMaterial::onUse(Render* r)
{
	Material::onUse(r);
	r->setProgram(m_program);

	Matrix4* mat=r->getMVPMatrix();
	r->setUniform(m_mvpUniform,Render::U_M_4,1,mat);
	r->setUniform(m_opacityUniform,Render::U_F_1,1,&this->m_opacity);
}


PositionColorMaterial::PositionColorMaterial()
{
	m_opacity=1.0f;
	m_opacityUniform=-1;
	m_positionLocation=-1;
	m_colorLocation=-1;


	int length_vert=sizeof(color_program_vert_str);
	int length_frag=sizeof(color_program_frag_str);
	m_program=Program::create(color_program_vert_str,length_vert,color_program_frag_str,length_frag);
	if(m_program==NULL)
	{
		FS_TRACE_WARN("Create Program Failed");
	}
	else 
	{
		m_opacityUniform=m_program->getUniformLocation("u_opacity");
		m_mvpUniform=m_program->getUniformLocation("u_mvp");
		
		m_positionLocation=m_program->getAttributeLocation("a_position");
		m_colorLocation=m_program->getAttributeLocation("a_color");
	}
	setDepthTest(false);
}

PositionColorMaterial::~PositionColorMaterial()
{
	FS_SAFE_DEC_REF(m_program);
}

NS_FS_END


