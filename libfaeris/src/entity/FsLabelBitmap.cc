#include "entity/FsLabelBitmap.h"
#include "graphics/FsFontBitmap.h"
#include "material/FsMat_V4F_T2F.h"

NS_FS_BEGIN

LabelBitmap* create(const char* text,FontBitmap* font)
{
	LabelBitmap* ret=create(font);
	if(ret)
	{
		ret->setString(text);
	}
	return ret;
}

LabelBitmap* LabelBitmap::create(FontBitmap* font)
{
	LabelBitmap* ret=new LabelBitmap();
	if(!ret->init(font))
	{
		ret->decRef();
		ret=NULL;
	}

	return ret;
}

int LabelBitmap* LabelBitmap::setString(const char* utf8_str)
{
	return setString(utf8_str,0);
}

int LabelBitmap* LabelBitmap::setString(const char* utf8_str,int start)
{
	return setString(utf8_str,0,-1);
}

int LabelBitmap* LabelBitmap::setString(const char* utf8_str,int start,int num)
{
}

const char* LabelBitmap::getString()
{
	return m_utf8str;
}

void LabelBitmap::setColor(Color c)
{
	m_color=c;
}
Color LabelBitmap::getColor()
{
	return m_color;
}

void LabelBitmap::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float LabelBitmap::getOpacity()
{
	return m_opacity;
}

void LabelBitmap::setAlign(int alignh,int alignv)
{
	m_alignh=alignh;
	m_alignv=alignv;
}
void LabelBitmap::setAlignOffset(float x,float y)
{
	m_offsetx=x;
	m_offsety=y;
}


void LabelBitmap::getAlign(int* alignh,int* alignv)
{
	*alignh=m_alignh;
	*alignv=M_alignv;
}

void LabelBitmap::getAlignOffset(float* x,float* y)
{
	*x=m_offsetx;
	*y=m_offsety;
}

void LabelBitmap::setTextAlign(int mode)
{
	m_textAlign=mode;
}

void LabelBitmap::setBounds(float x,float y)
{
	m_boundx=x;
	m_boundy=y;
}

int LabelBitmap::getTextAlign()
{
	return m_textAlign;
}

void LabelBitmap::getBounds(float* x,float* y)
{
	*x=m_boundx;
	*y=m_boundy;
}



void LabelBitmap::draw(Render* r,bool updateMatrix)
{
	if(!m_font||!m_vertices)
	{
		return;
	}
	if(!tex)
	{
		return;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	r->pushMatrix();
	r->mulMatrix(&m_worldMatrix);
	r->translate(Vector3(m_relOffsetx,m_relOffsety,0));

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);

	r->setMaterial(m_material);

	render->setActiveTexture(1);
	render->disableAllAttrArray();
	render->bindTexture(m_texture,0);


	int pos_loc=m_material->getV4FLocation();
	int pos_tex=m_material->getT2FLocation();

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,m_vertexNu,sizeof(Fs_V2F_T2F),m_vertices);
	r->setAndEnableVertexAttrPointer(pos_tex,2,FS_FLOAT,m_vertexNu,sizeof(Fs_V2F_T2F),&m_vertices->t2);
	r->drawArray(Render::TRIANGLES,0,m_vertexNu);

	r->popMatrix();
}

bool LabelBitmap::hit2D(float x,float y)
{
	float x,y;


	Rect2D rect(m_relOffsetx,-m_height+m_relOffsety,m_width,m_height);

	Vector2 point(x,y);
	updateWorldMatrix();
	return Math::pointInRect2D(point,m_worldMatrix,rect);


}
















NS_FS_END 



























