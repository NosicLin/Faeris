#include "entity/FsColorQuad2D.h"
#include "material/FsColorQuad2DMaterial.h"

NS_FS_BEGIN
ColorQuad2D* ColorQuad2D::create(const Rect2D& rect,Color c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(rect,c);
}

void ColorQuad2D::update(float /*dt*/)
{
	/* do nothing */
}

void ColorQuad2D::draw(Render* render)
{
	updateWorldMatrix();
	render->pushMatrix();
	render->mulMatrix(m_worldMatrix);

	m_shareMaterial->setOpacity(m_opacity);
	render->setMaterial(m_shareMaterial);
	render->setActiveTexture(0);
	render->disableAllClientArray();
	render->enableClientArray(Render::VERTEX_ARRAY|Render::COLOR_ARRAY);

	Vector3 vv[4]=
	{
		Vector3(m_rect.x,m_rect.y,0),
		Vector3(m_rect.x+m_rect.width,m_rect.y,0),
		Vector3(m_rect.x+m_rect.width,m_rect.y+m_rect.height,0);
		Vector3(m_rect.x,m_rect.y+m_rect.height,0);
	};

	Color vc[4]
	{
		m_va,
		m_vb,
		m_vc,
		m_vd,
	};

	Face3 faces
	{
		Faces(0,1,2);
		Faces(2,3,0);
	};

	render->setVVertexPointer(&vv,4);
	render->setVColorPointer(&vc,4);
	render->drawFace3(&faces,2);

	render->popMatrix();
}



const char* ColorQuad2D::className()const 
{
	return FS_COLOR_QUAD2D_CLASS_NAME;
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

void ColorQuad2D::setRect(const Rect2D& rect)
{
	m_rect=rect;
}

ColorQuad2D::ColorQuad2D()
{
	useShareMaterial();
}

ColorQuad2D::~ColorQuad2D()
{
	destroy();
	unuseShareMaterail();
}


NS_FS_END









