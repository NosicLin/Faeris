#include "material/FsMat_V4F_T2F.h"
#include "graphics/FsProgram.h"

NS_FS_BEGIN

static const char quad_material_vert_str[]=
"attribute vec4 a_position; 	    \n\
attribute vec2 a_texCoord;			\n\
uniform mat4 u_mvp;					\n\
#ifdef GL_ES						\n\
varying mediump vec2 v_texCoord;	\n\
#else								\n\
varying vec2 v_texCoord;			\n\
#endif								\n\
void main() 						\n\
{ 									\n\
	gl_Position=u_mvp*a_position;	\n\
	v_texCoord=a_texCoord;			\n\
}									\n\
";

static const char quad_material_frag_str[]=
"#ifdef GL_ES                       \n\
precision lowp float;               \n\
#endif								\n\
varying vec2 v_texCoord; 			\n\
uniform sampler2D u_texture0;       \n\
uniform vec4 	 u_color;			\n\
uniform float 	 u_opacity;			\n\
void main()							\n\
{									\n\
	vec4 tmp=texture2D(u_texture0,v_texCoord)*u_color;  \n\
	gl_FragColor=vec4(tmp.rgb,tmp.a*u_opacity);			\n\
}														\n\
";

static Mat_V4F_T2F* s_shareMatrial=NULL;

Mat_V4F_T2F* Mat_V4F_T2F::shareMaterial()
{
	if(s_shareMatrial==NULL)
	{
		s_shareMatrial=Mat_V4F_T2F::create();
	}

	s_shareMatrial->addRef();
	return s_shareMatrial;
}

void Mat_V4F_T2F::purgeShareMaterial()
{
	s_shareMatrial->forceDestroy();
	s_shareMatrial=NULL;
}


Mat_V4F_T2F* Mat_V4F_T2F::create()
{
	return new Mat_V4F_T2F();
}
void Mat_V4F_T2F::setColor(Color c)
{
	m_color=c;
}
Color Mat_V4F_T2F::getColor()
{
	return m_color;
}


void Mat_V4F_T2F::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float Mat_V4F_T2F::getOpacity()
{
	return m_opacity;
}


int Mat_V4F_T2F::getV4FLocation()
{
	return m_positionAttribute;
}
int Mat_V4F_T2F::getT2FLocation()
{
	return m_textcoordAttribute;
}


void Mat_V4F_T2F::onUse(Render* r)
{
	float color[4]=
	{
		m_color.r/255.0f,
		m_color.g/255.0f,
		m_color.b/255.0f,
		m_color.a/255.0f,
	};

	int texture0=0;

	Material::onUse(r);
	r->setProgram(m_program);

	Matrix4* mat=r->getMVPMatrix();
	r->setUniform(m_mvpUniform,Render::U_M_4,1,mat);

	r->setUniform(m_opacityUniform,Render::U_F_1,1, &this->m_opacity);
	r->setUniform(m_colorUniform,  Render::U_F_4,1, color);
	r->setUniform(m_textureUniform,Render::U_I_1,1, &texture0);
}
const char* Mat_V4F_T2F::className()
{
	return FS_POSITION_TEXTURE_MATERIAL_CLASS_NAME;
}




Mat_V4F_T2F::Mat_V4F_T2F()
{
	m_program=Program::create(quad_material_vert_str,sizeof(quad_material_vert_str),
			quad_material_frag_str,sizeof(quad_material_frag_str));
	if(m_program)
	{

		m_opacityUniform=m_program->getUniformLocation("u_opacity");
		m_colorUniform=m_program->getUniformLocation("u_color");
		m_textureUniform=m_program->getUniformLocation("u_texture0");
		m_mvpUniform=m_program->getUniformLocation("u_mvp");

		m_positionAttribute=m_program->getAttributeLocation("a_position");
		m_textcoordAttribute=m_program->getAttributeLocation("a_texCoord");

	}
	else 
	{
		m_opacityUniform=-1;
		m_colorUniform=-1;
		m_textureUniform=-1;

		m_positionAttribute=-1;
		m_textcoordAttribute=-1;
	}
	setDepthTest(false);
	m_color=Color::WHITE;
	m_opacity=1.0f;
}

Mat_V4F_T2F::~Mat_V4F_T2F()
{
	m_program->decRef();
}



NS_FS_END 



















