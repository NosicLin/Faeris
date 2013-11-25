#include "box2d/fb2Draw.h"
#include "FsGlobal.h"
#include "graphics/FsRender.h"

#include "math/FsVector2.h"
#include "math/FsMathUtil.h"
#include "graphics/material/FsMat_V4F.h"


NS_FS_BEGIN

fb2Draw::fb2Draw(float ratio)
{
	m_ratio=ratio;
	m_material=Mat_V4F::shareMaterial();
}


fb2Draw::~fb2Draw()
{
	FS_SAFE_DEC_REF(m_material);
}




void fb2Draw::DrawPolygon(const b2Vec2* old_vertices, int vertexCount,const b2Color& color)
{
	Vector2* vertices=new Vector2[vertexCount];

	for(int i=0;i<vertexCount;i++)
	{
		b2Vec2 tmp=old_vertices[i];
		tmp*=m_ratio;
		vertices[i].x=tmp.x;
		vertices[i].y=tmp.y;
	}


	Render* r=Global::render();
	r->pushMatrix();
	m_material->setColor(Color(uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255),255));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);


	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();

	int pos_loc=m_material->getV4FLocation();
	int vertex_nu=vertexCount;

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertices);
	r->drawArray(Render::LINE_LOOP,0,vertex_nu);
	r->popMatrix();

	delete[] vertices;


}


void fb2Draw::DrawSolidPolygon(const b2Vec2* old_vertices,int32 vertexCount,const b2Color& color)
{
	Vector2* vertices=new Vector2[vertexCount];

	for(int i=0;i<vertexCount;i++)
	{
		b2Vec2 tmp=old_vertices[i];
		tmp*=m_ratio;
		vertices[i].x=tmp.x;
		vertices[i].y=tmp.y;
	}


	Render* r=Global::render();
	r->pushMatrix();
	m_material->setColor(Color(uint8_t(color.r*127),uint8_t(color.g*127),uint8_t(color.b*127),127));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();




	int pos_loc=m_material->getV4FLocation();
	int vertex_nu=vertexCount;

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertices);
	r->drawArray(Render::TRIANGLE_FAN,0,vertexCount);

	m_material->setColor(Color(uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255),255));
	r->setMaterial(m_material);
	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertices);
	r->drawArray(Render::LINE_LOOP,0,vertex_nu);
	r->popMatrix();

	delete[] vertices;

}

void fb2Draw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) 
{

	float32 k_segments=16.0f;
	int vertexCount=16;
	float32 k_increment=360.0f/k_segments;
	float32 theta=0.0f;

	Vector2 vertex[16];

	for(int32 i=0;i<k_segments;++i)
	{
		b2Vec2 v=center+radius*b2Vec2(Math::sina(theta),Math::cosa(theta));
		vertex[i].x=v.x*m_ratio;
		vertex[i].y=v.y*m_ratio;
		theta+= k_increment;
	}

	Render* r=Global::render();
	r->pushMatrix();

	int pos_loc=m_material->getV4FLocation();

	m_material->setColor(Color(uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255),255));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertexCount,0,vertex);
	r->drawArray(Render::LINE_LOOP,0,vertexCount);
	r->popMatrix();

}


void fb2Draw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) 
{
	float32 k_segments=16.0f;
	int vertexCount=16;
	float32 k_increment=360.0f/k_segments;
	float32 theta=0.0f;

	int vertex_nu=vertexCount;

	Vector2 vertex[16];

	for(int32 i=0;i<k_segments;++i)
	{
		b2Vec2 v=center+radius*b2Vec2(Math::sina(theta),Math::cosa(theta));
		vertex[i].x=v.x*m_ratio;
		vertex[i].y=v.y*m_ratio;
		theta+= k_increment;
	}

	Render* r=Global::render();
	r->pushMatrix();

	int pos_loc=m_material->getV4FLocation();

	m_material->setColor(Color(uint8_t(color.r*127),uint8_t(color.g*127),uint8_t(color.b*127),127));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);

	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(Render::TRIANGLE_FAN,0,vertexCount);


	m_material->setColor(Color(uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255),255));
	r->setMaterial(m_material);
	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(Render::LINE_LOOP,0,vertex_nu);
	r->popMatrix();

}

void fb2Draw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) 
{
	Vector2 vertex[2]={
		Vector2(p1.x*m_ratio,p1.y*m_ratio),
		Vector2(p2.x*m_ratio,p2.y*m_ratio),
	};

	int vertex_nu=2;

	Render* r=Global::render();
	r->pushMatrix();

	int pos_loc=m_material->getV4FLocation();

	m_material->setColor(Color(uint8_t(color.r*255),uint8_t(color.g*255),uint8_t(color.b*255),255));
	m_material->setPointSize(1.0f);
	m_material->setOpacity(1.0f);


	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();

	r->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,vertex_nu,0,vertex);
	r->drawArray(Render::LINE_LOOP,0,2);

	r->popMatrix();

}

void fb2Draw::DrawTransform(const b2Transform& xf) 
{
	b2Vec2 p1=xf.p; 
	b2Vec2 p2;

	const float32 k_axisScale = 0.4f; 
	p2 = p1 + k_axisScale* xf.q.GetXAxis();
	DrawSegment(p1,p2,b2Color(1,0,0));

	p2=p1+k_axisScale* xf.q.GetYAxis();
	DrawSegment(p1,p2,b2Color(0,1,0));
}





NS_FS_END

