#include "entity/FsQuad2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRender.h"
#include "material/FsPositionTextureMaterial.h"
#include "common/FsGlobal.h"
#include "mgr/FsTextureMgr.h"

NS_FS_BEGIN


Quad2D* Quad2D::create(const char* tex)
{
	Quad2D* ret=new Quad2D;
	if(!ret->init(tex))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void Quad2D::setColor(Color c)
{
	m_color=c;
}
Color Quad2D::getColor()
{
	return m_color;
}

void Quad2D::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float Quad2D::getOpacity()
{
	return m_opacity;
}
void Quad2D::setTexture(Texture2D* tex)
{
	FS_SAFE_ADD_REF(tex);
	FS_SAFE_DEC_REF(m_texture);
	m_texture=tex;
}
Texture2D* Quad2D::getTexture()
{
	FS_SAFE_ADD_REF(m_texture);
	return m_texture;
}


void Quad2D::setTextureCoord(const Rect2D& coord)
{
	m_textureCoord=coord;
}

Rect2D Quad2D::getTextureCoord()
{
	return m_textureCoord;
}

void Quad2D::setRect2D(const Rect2D& rect)
{
	m_rect=rect;
}

Rect2D Quad2D::getRect2D()
{
	return m_rect;
}

void Quad2D::draw(Render* render,bool updateMatrix)
{

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	render->pushMatrix();
	render->mulMatrix(m_worldMatrix);

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);
	render->setMaterial(m_material,true);

	render->setActiveTexture(1);
	render->disableAllClientArray();
	render->disableAllAttrArray();
	render->bindTexture(m_texture,0);

	Vector3 vv[4]=
	{
		Vector3(m_rect.x,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y+m_rect.height,0.0f),
		Vector3(m_rect.x,m_rect.y+m_rect.height,0.0f),
	};
	TexCoord2 vc[4]=
	{
		TexCoord2(m_textureCoord.x,
				m_textureCoord.y+m_textureCoord.height),	  /* a */

		TexCoord2(m_textureCoord.x+m_textureCoord.width,
				m_textureCoord.y+m_textureCoord.height),	  /* b */

		TexCoord2(m_textureCoord.x+m_textureCoord.width,
				m_textureCoord.y),	  /* c */

		TexCoord2(m_textureCoord.x,
				m_textureCoord.y),	  /* d */
	};

	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	render->setAndEnableVertexAttrPointer("a_position",3,FS_FLOAT,4,0,vv);
	render->setAndEnableVertexAttrPointer("a_texCoord",2,FS_FLOAT,4,0,vc);

	render->drawFace3(faces,2);
	render->popMatrix();
}

const char* Quad2D::className()
{
	return FS_QUAD2D_CLASS_NAME;
}





Quad2D::Quad2D()
{
	m_texture=NULL;
	m_material=NULL;
}
Quad2D::~Quad2D()
{
	destory();
}

bool Quad2D::init(const char* file)
{
	Texture2D* tex=Global::textureMgr()->loadTexture(file);
	if(tex==NULL)
	{
		return false;
	}
	bool ret=init(tex);
	tex->decRef();
	return ret;
}
bool Quad2D::init(Texture2D* tex)
{
	float width=(float)tex->getWidth();
	float height=(float)tex->getHeight();

	m_rect.set(-width/2.0f,-height/2.0f,width,height);
	m_textureCoord.set(0,0,1,1);

	tex->addRef();
	m_texture=tex;
	m_material=PositionTextureMaterial::shareMaterial();
	m_color=Color::WHITE;
	m_opacity=1.0f;
	return true;
}
void Quad2D::destory()
{
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_material);
}



NS_FS_END 












