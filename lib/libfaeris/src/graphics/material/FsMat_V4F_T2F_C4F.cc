#include "graphics/material/FsMat_V4F_T2F_C4F.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN

static const char  v4f_t2f_c4f_vert_str[]=
"uniform mat4 u_mvp; 				\n\
attribute vec4 a_position;          \n\
attribute vec4 a_color;             \n\
attribute vec2 a_texCoord; 			\n\
#ifdef GL_ES 				        \n\
varying lowp vec4 v_fragmentColor;  \n\
varying lowp vec2 v_texCoord;       \n\
#else 								\n\
varying vec4 v_fragmentColor;       \n\
varying vec2 v_texCoord;            \n\
#endif                              \n\
void main()							\n\
{									\n\
	gl_Position=u_mvp*a_position;   \n\
	v_fragmentColor=a_color;        \n\
	v_texCoord=a_texCoord;          \n\
};                                  \n\
";


static const char v4f_t2f_c4f_frag_str[]=
"#ifdef GL_ES 						\n\
precision lowp float;				\n\
#endif 								\n\
varying vec2  v_texCoord;           \n\
uniform sampler2D u_texture0;		\n\
uniform vec4      u_color;          \n\
uniform float     u_opacity;        \n\
void main()                         \n\
{									\n\
	vec4 tmp=texture2D(u_texture0,v_texCoord)*u_color; \n\
	gl_FragColor=vec4(tmp.rgb,tmp.a*u_opacity);        \n\
}";


static Mat_V4F_T2F_C4F* s_shareMatrial=NULL;

Mat_V4F_T2F_C4F* Mat_V4F_T2F_C4F::shareMaterial()
{
	if(s_shareMatrial==NULL)
	{
		s_shareMatrial=Mat_V4F_T2F_C4F::create();
	}
	s_shareMatrial->addRef();
	return s_shareMatrial;
}

void Mat_V4F_T2F_C4F::purgeShareMaterial()
{
	s_shareMatrial->forceDestroy();
	s_shareMatrial=NULL;
}




int Mat_V4F_T2F_C4F::getV4FLocation()
{
	return m_v4fLocation;
}

int Mat_V4F_T2F_C4F::getT2FLocation()
{
	return m_t2fLocation;
}


void Mat_V4F_T2F_C4F::onUse(Render* r)
{
	float color[4]=
	{
		m_color.r/255.0f,
		m_color.g/255.0f,
		m_color.b/255.0f,
		m_color.a/255.0f,
	};
	int texture0 =0;
	Material::onUse(r);
	r->setProgram(m_program);
	Matrix4* mat=r->getMVPMatrix();
	r->setUniform(m_mvpUniform,Render::U_M_4,1,mat);
	r->setUniform(m_colorUniform,Render::U_F_4,1,color);
	r->setUniform(m_opacityUniform,Render::U_F_1,1,&this->m_opacity);
	r->setUniform(m_textureUniform,Render::U_I_1,1,&texture0);
}

Mat_V4F_T2F_C4F::Mat_V4F_T2F_C4F()
{
	m_program=Program::create(v4f_t2f_c4f_vert_str,
			sizeof(v4f_t2f_c4f_vert_str),
			v4f_t2f_c4f_frag_str,
			sizeof(v4f_t2f_c4f_frag_str)
			);

	if(m_program)
	{
		m_opacityUniform=m_program->getUniformLocation("u_opacity");
		m_colorUniform  =m_program->getUniformLocation("u_color");
		m_textureUniform=m_program->getUniformLocation("u_texture0");
		m_mvpUniform    =m_program->getUniformLocation("m_mvp");

		m_v4fLocation=m_program->getAttributeLocation("a_position");
		m_t2fLocation=m_program->getAttributeLocation("a_texCoord");
		m_c4fLocation=m_program->getAttributeLocation("a_color");
	}
	else 
	{
		m_opacityUniform=-1;
		m_colorUniform=-1;
		m_textureUniform=-1;

		m_v4fLocation=-1;
		m_t2fLocation=-1;
		m_c4fLocation=-1;
	}
	setDepthTest(false);
	m_opacity=1.0f;
}

Mat_V4F_T2F_C4F::~Mat_V4F_T2F_C4F()
{
	m_program->decRef();
}












NS_FS_END 




















