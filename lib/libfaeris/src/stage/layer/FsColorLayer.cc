#include "stage/layer/FsColorLayer.h"
#include "graphics/FsRender.h"
#include "graphics/material/FsMat_V4F_C4F.h"

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

	
	Mat_V4F_C4F* material=Mat_V4F_C4F::shareMaterial();
	material->setOpacity(1.0);

	Matrix4 mat;
	mat.makeOrthographic(0,1,0,1,0,100);
	r->setProjectionMatrix(&mat);

	r->setMaterial(material);

	r->setActiveTexture(0);
	r->disableAllAttrArray();

	int pos_loc=material->getV4FLocation();
	int color_loc=material->getC4FLocation();

	Vector3 vv[4]=
	{
		Vector3(0,0,0),
		Vector3(1,0,0),
		Vector3(1,1,0),
		Vector3(0,1,0),
	};
	float vc[16]=
	{
		m_color.r/255.0f,m_color.g/255.0f,m_color.b/255.0f,m_color.a/255.0f,
		m_color.r/255.0f,m_color.g/255.0f,m_color.b/255.0f,m_color.a/255.0f,
		m_color.r/255.0f,m_color.g/255.0f,m_color.b/255.0f,m_color.a/255.0f,
		m_color.r/255.0f,m_color.g/255.0f,m_color.b/255.0f,m_color.a/255.0f,
	};

	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	r->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,4,0,vv);
	r->setAndEnableVertexAttrPointer(color_loc,4,FS_FLOAT,4,0,vc);

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


