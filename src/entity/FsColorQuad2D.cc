#include "entity/FsColorQuad2D.h"
#include "material/FsColorQuad2DMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN

static ColorQuad2DMaterial* m_shareMaterial=NULL;


static ColorQuad2DMaterial* useShareMaterial()
{
	if(m_shareMaterial==NULL)
	{
		m_shareMaterial=ColorQuad2DMaterial::create();
		return m_shareMaterial;
	}
	m_shareMaterial->addRef();
	return m_shareMaterial;
}
static void unuseShareMaterial()
{
	if(m_shareMaterial->refCnt()==1)
	{
		m_shareMaterial->decRef();
		m_shareMaterial=NULL;
	}
	else 
	{
		m_shareMaterial->decRef();
	}
}
ColorQuad2D* ColorQuad2D::create(const Rect2D& rect,Color c)
{
	ColorQuad2D* quad=new ColorQuad2D();
	quad->init(rect,c);
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
	render->mulMatrix(m_worldMatrix);

	m_shareMaterial->setOpacity(m_opacity);
	render->setMaterial(m_shareMaterial,true);
	render->setActiveTexture(0);
	render->disableAllClientArray();
	render->enableClientArray(Render::VERTEX_ARRAY|Render::COLOR_ARRAY);
	//render->enableClientArray(Render::VERTEX_ARRAY);


	Vector3 vv[4]=
	{
		Vector3(m_rect.x,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y,0.0f),
		Vector3(m_rect.x+m_rect.width,m_rect.y+m_rect.height,0.0f),
		Vector3(m_rect.x,m_rect.y+m_rect.height,0.0f),
	};

	
	Color vc[4]=
	{
		m_va,
		m_vb,
		m_vc,
		m_vd,
	};
	

	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	render->setVVertexPointer(vv,4);
	render->setVColorPointer(vc,4);
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
	Vector2 a=m_worldMatrix.mulVector2(Vector2(m_rect.x,m_rect.y));
	Vector2 b=m_worldMatrix.mulVector2(Vector2(m_rect.x+m_rect.width,m_rect.y));
	Vector2 c=m_worldMatrix.mulVector2(Vector2(m_rect.x+m_rect.width,m_rect.y+m_rect.height));
	Vector2 d=m_worldMatrix.mulVector2(Vector2(m_rect.x,m_rect.y+m_rect.height));

	if(Math::pointInTriangle2D(point,a,b,c))
	{
		return true;
	}
	if(Math::pointInTriangle2D(point,c,d,a))
	{
		return true;
	}
	return false;
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
	m_material=useShareMaterial();
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
void ColorQuad2D::destroy()
{
	unuseShareMaterial();
}


NS_FS_END









