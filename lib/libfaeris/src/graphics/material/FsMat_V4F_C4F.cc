#include "graphics/material/FsMat_V4F_C4F.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN
static const char color_program_vert_str[]=
"uniform mat4 u_mvp;					\n\
uniform float u_opacity; 				\n\
attribute vec4 a_position;				\n\
attribute vec4 a_color;					\n\
#ifdef GL_ES							\n\
varying lowp vec4 v_fragmentColor;		\n\
#else									\n\
varying vec4 v_fragmentColor;			\n\
#endif									\n\
void main()   							\n\
{										\n\
	gl_Position=u_mvp*a_position;		\n\
	v_fragmentColor=vec4(a_color.rgb,a_color.a*u_opacity); \n\
}  										\n\
";

static const char color_program_frag_str[]=
"#ifdef GL_ES                           \n\
precision lowp float;                   \n\
#endif                                  \n\
varying vec4 v_fragmentColor; 			\n\
void main() 					        \n\
{										\n\
	gl_FragColor=v_fragmentColor;		\n\
}										\n\
";

	

static Mat_V4F_C4F* s_share_material=NULL;

Mat_V4F_C4F* Mat_V4F_C4F::shareMaterial()
{
	if(s_share_material==NULL)
	{
		s_share_material = Mat_V4F_C4F::create();
		FS_NO_REF_DESTROY(s_share_material);
	}

	return s_share_material;
}
void Mat_V4F_C4F::purgeShareMaterial()
{
	FS_SAFE_DESTROY(s_share_material);
	s_share_material=NULL;
}


Mat_V4F_C4F* Mat_V4F_C4F::create()
{
	Mat_V4F_C4F* ret=new Mat_V4F_C4F;
	return ret;
}


void Mat_V4F_C4F::onUse(Render* r)
{
	Material::onUse(r);
	r->setProgram(m_program);

	Matrix4* mat=r->getMVPMatrix();
	r->setUniform(m_mvpUniform,Render::U_M_4,1,mat);
	r->setUniform(m_opacityUniform,Render::U_F_1,1,&this->m_opacity);
}


Mat_V4F_C4F::Mat_V4F_C4F()
{
	m_opacity=1.0f;
	m_opacityUniform=-1;
	m_positionLocation=-1;
	m_colorLocation=-1;


	int length_vert=sizeof(color_program_vert_str);
	int length_frag=sizeof(color_program_frag_str);
	m_program=Program::create(color_program_vert_str,length_vert,color_program_frag_str,length_frag);
	FS_SAFE_ADD_REF(m_program);
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

Mat_V4F_C4F::~Mat_V4F_C4F()
{
	FS_SAFE_DEC_REF(m_program);
}

NS_FS_END


