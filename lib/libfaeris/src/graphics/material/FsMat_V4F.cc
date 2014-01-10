#include "graphics/material/FsMat_V4F.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN 

static const char mat_v4f_vert_str[]=
"uniform mat4 u_mvp;				\n\
uniform vec4  u_color;				\n\
uniform float u_pointSize;			\n\
attribute vec4 a_position;			\n\
#ifdef GL_ES						\n\
varying lowp vec4 v_fragmentColor;	\n\
#else 								\n\
varying vec4 v_fragmentColor;		\n\
#endif 								\n\
void main() 						\n\
{									\n\
	gl_Position=u_mvp*a_position;	\n\
	gl_PointSize=u_pointSize;		\n\
	v_fragmentColor=u_color;		\n\
}									\n\
";

static const  char mat_v4f_frag_str[]= 
"#ifdef GL_ES 						\n\
precision lowp float;				\n\
#endif 								\n\
varying vec4 v_fragmentColor;		\n\
uniform float u_opacity;			\n\
void main()							\n\
{									\n\
	gl_FragColor=v_fragmentColor*u_opacity;	\n\
}									\n\
";

static Mat_V4F* s_share_material=NULL;


Mat_V4F* Mat_V4F::shareMaterial()
{
	if(s_share_material==NULL)
	{
		s_share_material=Mat_V4F::create();
	}
	FS_SAFE_ADD_REF(s_share_material);
	return s_share_material;
}


Mat_V4F* Mat_V4F::create()
{
	Mat_V4F* ret= new Mat_V4F;
	return ret;
}



void Mat_V4F::onUse(Render* r)
{
	float color[4]=
	{
		m_color.r/255.0f, 
		m_color.g/255.0f,
		m_color.b/255.0f,
		m_color.a/255.0f,
	};


	Material::onUse(r);
	r->setProgram(m_program);

	Matrix4* mat=r->getMVPMatrix();
	r->setUniform(m_mvpUniform,Render::U_M_4,1,mat);
	r->setUniform(m_opacityUniform,Render::U_F_1,1,&m_opacity);
	r->setUniform(m_pointSizeUniform,Render::U_F_1,1,&m_pointSize);
	r->setUniform(m_colorUniform,Render::U_F_4,1,&color);
}

const char* Mat_V4F::className()
{
	return FS_MAT_V4F_CLASS_NAME;
}	


Mat_V4F::Mat_V4F()
{
	m_program=Program::create(mat_v4f_vert_str,sizeof(mat_v4f_vert_str),mat_v4f_frag_str,sizeof(mat_v4f_frag_str));

	FS_SAFE_ADD_REF(m_program);


	if(m_program) 
	{
		m_opacityUniform=m_program->getUniformLocation("u_opacity");
		m_colorUniform=m_program->getUniformLocation("u_color");
		m_mvpUniform=m_program->getUniformLocation("u_mvp");
		m_pointSizeUniform=m_program->getUniformLocation("u_pointSize");

		m_positionAttribute=m_program->getAttributeLocation("a_position");

	}
	else 
	{
		m_opacityUniform=-1;
		m_colorUniform=-1;
		m_mvpUniform=-1;

		m_positionAttribute=-1;
	}
	setDepthTest(false);
	m_color=Color::WHITE;
	m_opacity=1.0f;
}


Mat_V4F::~Mat_V4F()
{
	FS_SAFE_DEC_REF(m_program);
}











NS_FS_END
