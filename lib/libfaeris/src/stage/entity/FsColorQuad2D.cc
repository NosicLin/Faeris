#include "stage/entity/FsColorQuad2D.h"
#include "graphics/material/FsMat_V4F_C4F.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN


ColorQuad2D* ColorQuad2D::create(const Rect2D& rect,Color c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(rect,c);
	return quad;
}
ColorQuad2D* ColorQuad2D::create(float width,float height,Color c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(width,height,c);
	return quad;
}

void ColorQuad2D::update(float /*dt*/)
{
	/* do nothing */
}

void ColorQuad2D::draw(Render* render,bool updateMatrix)
{
	if(updateMatrix)
	{
		updateWorldMatrix();
	}
	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);


	m_material->setOpacity(m_opacity);
	render->setMaterial(m_material);

	render->setActiveTexture(0);
	render->disableAllAttrArray();

	
	int pos_loc=m_material->getV4FLocation();
	int color_loc=m_material->getC4FLocation();

	Vector3 vv[4]=
	{
		Vector3(m_rect.x,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y+m_rect.height,0.0f),
		Vector3(m_rect.x,m_rect.y+m_rect.height,0.0f),
	};

	
	
	float vc[16]=
	{
		m_va.r/255.0f,m_va.g/255.0f,m_va.b/255.0f,m_va.a/255.0f,
		m_vb.r/255.0f,m_vb.g/255.0f,m_vb.b/255.0f,m_vb.a/255.0f,
		m_vc.r/255.0f,m_vc.g/255.0f,m_vc.b/255.0f,m_vc.a/255.0f,
		m_vd.r/255.0f,m_vd.g/255.0f,m_vd.b/255.0f,m_vd.a/255.0f,
	};
	

	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	render->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,4,0,vv);
	render->setAndEnableVertexAttrPointer(color_loc,4,FS_FLOAT,4,0,vc);


	render->drawFace3(faces,2);

	render->popMatrix();
}



const char* ColorQuad2D::className()const 
{
	return FS_COLOR_QUAD2D_CLASS_NAME;
}

bool ColorQuad2D::hit2D(float x,float y)
{
	Vector2 point(x,y);
	updateWorldMatrix();

	return Math::pointInRect2D(point,m_worldMatrix,m_rect);
}


void ColorQuad2D::setColor(Color c,int vertex)
{
	if(vertex&VERTEX_A)
	{
		m_va=c;
	}
	if(vertex&VERTEX_B)
	{
		m_vb=c;
	}
	if(vertex&VERTEX_C)
	{
		m_vc=c;
	}
	if(vertex&VERTEX_D)
	{
		m_vd=c;
	}
}

void ColorQuad2D::setRect2D(const Rect2D& rect)
{
	m_rect=rect;
}

Rect2D ColorQuad2D::getRect2D()
{
	return m_rect;
}
void ColorQuad2D::setOpacity(float opacity)
{
	m_opacity=opacity;
}
float ColorQuad2D::getOpacity()
{
	return m_opacity;
}

ColorQuad2D::ColorQuad2D()
{
	m_opacity=1.0f;
	m_rect.set(0,0,0,0);
	setColor(Color::WHITE);
	m_material=Mat_V4F_C4F::shareMaterial();
}

ColorQuad2D::~ColorQuad2D()
{
	destroy();
}

void ColorQuad2D::init(const Rect2D& rect,Color c)
{
	m_va=c;
	m_vb=c;
	m_vc=c;
	m_vd=c;
	m_rect=rect;
	m_opacity=1.0f;

}

void ColorQuad2D::init(float width,float height,Color c)
{
	m_va=c;
	m_vb=c;
	m_vc=c;
	m_vd=c;
	m_rect=Rect2D(-width/2,-height/2,width,height);
	m_opacity=1.0f;
}

void ColorQuad2D::destroy()
{
	FS_SAFE_DEC_REF(m_material);
}


NS_FS_END









