#include "scene/FsColorLayer.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
ColorLayer* ColorLayer::create()
{
	ColorLayer* ret=new ColorLayer;
	return ret;
}

ColorLayer* ColorLayer::create(Color c)
{
	ColorLayer* ret=new ColorLayer;
	ret->setColor(c);
	return ret;
}

void ColorLayer::setColor(Color c)
{
	m_color=c;
}
Color ColorLayer::getColor()
{
	return m_color;
}


void ColorLayer::draw(Render*  r)
{
	r->setMaterial(NULL);
	r->setProgram(NULL);
	Matrix4 mat;
	mat.makeOrthographic(0,1,0,1,0,100);
	r->setProjectionMatrix(mat);

	r->setActiveTexture(0);
	r->disableAllClientArray();

	r->enableClientArray(Render::VERTEX_ARRAY|Render::COLOR_ARRAY);
	Vector3 vv[4]=
	{
		Vector3(0,0,0),
		Vector3(1,0,0),
		Vector3(1,1,0),
		Vector3(0,1,0),
	};
	Color vc[4]=
	{
		m_color,
		m_color,
		m_color,
		m_color
	};


	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};
	r->setVVertexPointer(vv,4);
	r->setVColorPointer(vc,4);

	r->drawFace3(faces,2);
}

const char* ColorLayer::className()
{
	return FS_COLOR_LAYER_CLASS_NAME;
}

ColorLayer::ColorLayer()
{
	m_color=Color(255,255,255,135);
}

ColorLayer::~ColorLayer()
{
}

NS_FS_END 


