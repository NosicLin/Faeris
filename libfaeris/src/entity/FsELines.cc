#include "entity/FsELines.h"


NS_FS_BEGIN 

const char* ELines::className()
{
	return FS_ELINES_CLASS_NAME;
}

ELines::setColor(Color c)
{
	int size=m_vertics.size();
	for(int i=0;i<size;i++)
	{
		m_vertics[i].Color=c;
	}
	m_defaultColor=c;
}

Color ELines::getColor()
{
	return m_defaultColor;
}

void ELines::setColor(int index,Color c)
{
	assert((uint)index<m_vertics.size());
	m_vertics[index].color=c;
}

Color ELines::getColor(int index) 
{
	assert((uint)index<m_vertics.size());
	return m_vertics[index].color
}


void ELines::setVertex(int index,Vertex3 v)
{
	assert((uint)index<m_vertics.size());
	m_vertics[index].vertex=v;
}

Vertex3 ELines::getVertex(int index)
{
	assert((uint)index<m_vertics.size());
	return m_vertics[index].vertex;
}


void ELines::append(Vertex3 v,Color c)
{
	m_vertics.push_back(ELinesVertex(v,c));
}

void ELines::append(Vertex3 v)
{
	m_vertics.push_back(ELinesVertex(v,m_defaultColor));
}

void ELines::resizeVertexNu(int nu)
{
	m_vertics.resize(nu);
}

void ELines::getVertexNu()
{
	return m_vertics.size();
}

void ELines::draw(Render* r,bool updateMatrix)
{
	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	r->pushMatrix();
	r->mulMatrix(&m_worldMatrix);

	m_material->setOpacity(m_opacity);
	m_material->setSize(m_size);

	r->setMaterial(m_material);
	r->setActiveTexture(0);
	r->disableAllAttrArray();

	int pos_loc=m_material->getPostionLocation();
	int col_loc=m_material->getColorLocation();
	int nu=m_vertics.size();
	int ELinesVertex* vertics=&m_vertics[0];
	r->setAndEnableVertexAttrPointer(pos_loc,3,FS_FLOAT,nu,sizeof(ELinesVertex),vertics);
	r->setAndEnableVertexAttrPointer(col_loc,4,FS_INT8,nu,sizeof(ELinesVertex),&vertics->color);
	switch(m_mode)
	{
		case MODE_LINES:
			render->drawPrimitives(Render::PRIMITIVE_LINES);
			break;
		case MODE_STRIP:
			render->drawPrimitives(Render::PRIMITIVE_LINE_STRIP);
			break;
		case MODE_LOOP:
			render->drawPrimitives(Render::PRIMITIVE_LINE_LOOP);
			break;
		default:
			FS_TRACE_ERROR("Unkown Mode");
			break;
	}

	r->popMatrix();
}

ELines::ELines()
{
	m_size=1.0f;
	m_opacity=1.0f;
	m_defaultColor=Color::WHITE;
	m_material=NULL;
	m_mode=MODE_LOOP;
}

ELines::~ELines()
{
	destory();

}
void ELines::destory()
{
	FS_SAFE_DEC_REF(m_material);
}

bool ELines::init(Vertex3 start,Vertex3 end)
{
	m_material=PositionColorLineMaterial::shareMaterial();
	if(!m_material)
	{
		return false;
	}

	append(start,m_defaultColor);
	append(end,m_defaultColor);
}

bool ELines::init()
{
	m_material=PositionColorLineMaterial::shareMaterial();
	if(!m_material)
	{
		return false;
	}
	return true;
}



















NS_FS_END 























