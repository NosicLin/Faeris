#include "material/FsPositionAlphaTextureMaterial.h"
#include "graphics/FsProgram.h"


NS_FS_BEGIN

static const char quad_material_vert_str[]=
"attribute vec2 a_position; 	    		\n\
attribute vec2  a_texCoord;					\n\
attribute float a_alpha;					\n\
varying vec2 v_texCoord;					\n\
varying float v_alpha;						\n\
void main() 								\n\
{ 											\n\
	gl_Position=gl_ModelViewProjectionMatrix*vec4(a_position,0,1);		\n\
	v_texCoord=a_texCoord;					\n\
	v_alpha=a_alpha;						\n\
}											\n\
";

static const char quad_material_frag_str[]=
"varying vec2 v_texCoord; 			\n\
varying  float v_alpha;				\n\
uniform sampler2D u_texture0;       \n\
uniform vec4 	 u_color;			\n\
uniform float 	 u_opacity;			\n\
void main()							\n\
{									\n\
	vec4 tmp=texture2D(u_texture0,v_texCoord)*u_color;  \n\
	gl_FragColor=vec4(tmp.rgb,tmp.a*u_opacity*v_alpha);	\n\
}														\n\
";

static PositionAlphaTextureMaterial* s_shareMatrial=NULL;
PositionAlphaTextureMaterial* PositionAlphaTextureMaterial::shareMaterial()
{
	if(s_shareMatrial==NULL)
	{
		s_shareMatrial=PositionAlphaTextureMaterial::create();
	}

	s_shareMatrial->addRef();
	return s_shareMatrial;
}

void PositionAlphaTextureMaterial::purgeShareMaterial()
{
	s_shareMatrial->forceDestroy();
	s_shareMatrial=NULL;
}


PositionAlphaTextureMaterial* PositionAlphaTextureMaterial::create()
{
	return new PositionAlphaTextureMaterial();
}

void PositionAlphaTextureMaterial::setColor(Color c)
{
	m_color=c;
}

Color PositionAlphaTextureMaterial::getColor()
{
	return m_color;
}


void PositionAlphaTextureMaterial::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float PositionAlphaTextureMaterial::getOpacity()
{
	return m_opacity;
}


int PositionAlphaTextureMaterial::getPostionLocaition()
{
	return m_positionAttribute;
}

int PositionAlphaTextureMaterial::getTexCoordLocation()
{
	return m_textcoordAttribute;
}
int PositionAlphaTextureMaterial::getAlphaLocation()
{
	return m_alphaAttribute;
}


void PositionAlphaTextureMaterial::load(Render* r)
{
	float color[4]=
	{
		m_color.r/255.0f,
		m_color.g/255.0f,
		m_color.b/255.0f,
		m_color.a/255.0f,
	};

	int texture0=0;

	configRender(r);
	r->setProgram(m_program);
	r->setUniform(m_opacityUniform,Render::U_F_1,1,&this->m_opacity);
	r->setUniform(m_colorUniform,Render::U_F_4,1,color);
	r->setUniform(m_textureUniform,Render::U_I_1,1,&texture0);
}
void PositionAlphaTextureMaterial::unload(Render* )
{

}
const char* PositionAlphaTextureMaterial::className()
{
	return FS_POSITION_ALPHA_TEXTURE_MATERIAL_CLASS_NAME;
}




PositionAlphaTextureMaterial::PositionAlphaTextureMaterial()
{
	m_program=Program::create(quad_material_vert_str,sizeof(quad_material_vert_str),
							  quad_material_frag_str,sizeof(quad_material_frag_str));
	if(m_program)
	{
		m_program->addAttribute("a_position");
		m_program->addAttribute("a_texCoord");
		m_program->addAttribute("a_alpha");

		m_program->addUniform("u_opacity");
		m_program->addUniform("u_color");
		m_program->addUniform("u_texture0");

		m_opacityUniform=m_program->getUniformLocation("u_opacity");
		m_colorUniform=m_program->getUniformLocation("u_color");
		m_textureUniform=m_program->getUniformLocation("u_texture0");
		
		m_positionAttribute=m_program->getAttributeLocation("a_position");
		m_textcoordAttribute=m_program->getAttributeLocation("a_texCoord");
		m_alphaAttribute=m_program->getAttributeLocation("a_alpha");

	}
	else 
	{
		m_opacityUniform=-1;
		m_colorUniform=-1;
		m_textureUniform=-1;

		m_positionAttribute=-1;
		m_textcoordAttribute=-1;
		m_alphaAttribute=-1;
	}


	setDepthTest(false);
	m_color=Color::WHITE;
	m_opacity=1.0f;
}

PositionAlphaTextureMaterial::~PositionAlphaTextureMaterial()
{
	m_program->decRef();
}

NS_FS_END




























