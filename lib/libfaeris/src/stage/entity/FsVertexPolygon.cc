#include "stage/entity/FsVertexPolygon.h"


NS_FS_BEGIN


const char* VertexPolygon::className()
{
	return FS_VERTEX_POLYGON_CLASS_NAME;
}


VertexPolygon* VertexPolygon::create()
{
	VertexPolygon* ret=new VertexPolygon();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}

	return ret;
}


void VertexPolygon::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float VertexPolygon::getOpacity()
{
	return m_opacity;
}

void VertexPolygon::setColor(Color color)
{
	m_color=color;
}

Color VertexPolygon::getColor()
{
	return m_color;
}


void VertexPolygon::setVertex(uint index,Vector3 v)
{
	if(index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}

	m_vertics[index]=v;

}
void VertexPolygon::setVertex(uint index,Vector2 v)
{
	setVertex(index,Vector3(v.x,v.y,0));
}

void VertexPolygon::setVertex(uint index,float x,float y,float z)
{
	setVertex(index,Vector3(x,y,z));
}



Vector3 VertexPolygon::getVertex(uint index)
{
	if (index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return Vector3(0,0,0);
	}
	return m_vertics[index];
}

void VertexPolygon::append(Vector3 v)
{
	m_vertics.push_back(v);
}

void VertexPolygon::append(Vector2 v)
{
	m_vertics.push_back(Vector3(v.x,v.y,0));
}

void VertexPolygon::append(float x,float y,float z)
{
	m_vertics.push_back(Vector3(x,y,z));
}


void VertexPolygon::removeVertex(uint index)
{
	if(index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}

	m_vertics.erase(m_vertics.begin()+index);
}

void VertexPolygon::insertVertex(uint index,Vector3 v)
{
	if(index>m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}
	m_vertics.insert(m_vertics.begin()+index,v);
}

void VertexPolygon::insertVertex(uint index,Vector2 v)
{
	insertVertex(index,Vector3(v.x,v.y,0));
}

void VertexPolygon::insertVertex(uint index,float x,float y,float z)
{
	insertVertex(index,Vector3(x,y,z));
}







void VertexPolygon::resize(int nu)
{
	m_vertics.resize(nu);
}

int VertexPolygon::getVertexNu()
{
	return m_vertics.size();
}
void VertexPolygon::setMode(int mode)
{
	m_mode=mode;
}


int VertexPolygon::getMode()
{
	return m_mode;
}


void VertexPolygon::setPointSize(float size)
{
	m_pointSize=size;
}

float VertexPolygon::getPointSize()
{
	return m_pointSize;
}

VertexPolygon::VertexPolygon()
{
	m_opacity=1.0f;
	m_color=Color::WHITE;
	m_pointSize=1.0f;
	m_mode=VertexPolygon::POINTS;
	m_material=NULL;
}

VertexPolygon::~VertexPolygon()
{
	destruct();
}

bool VertexPolygon::init()
{
	m_material=Mat_V4F::shareMaterial();
	return true;

}

void VertexPolygon::destruct()
{

	FS_SAFE_DEC_REF(m_material);
	m_vertics.clear();
}


void VertexPolygon::draw(Render* render,bool update_matrix)
{
	if(update_matrix)
	{
		updateWorldMatrix();
	}
	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);
	m_material->setPointSize(m_pointSize);


	render->setMaterial(m_material);
	render->setActiveTexture(0);
	render->disableAllAttrArray();

	int pos_loc=m_material->getV4FLocation();

	render->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,m_vertics.size(),0,&m_vertics[0]);
	render->drawArray(m_mode,0,m_vertics.size());
	render->popMatrix();

}

























NS_FS_END







