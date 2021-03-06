#include <algorithm>
#include "stage/layer/FsLayer2D.h"
#include "support/util/FsArray.h"
#include "support/util/FsSlowDict.h"
#include "support/util/FsDict.h"
#include "graphics/FsRender.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

static bool FsFuncEntity_SortZolder(Entity* left,Entity* right)
{
	if( left->getZorder()<right->getZorder())
	{
		return true;
	}
	else if(left->getZorder()>right->getZorder())
	{
		return false;
	}
	else 
	{
		return left->getAddOlder()<right->getAddOlder();
	}
}

static bool FsFuncEntity_SortY(Entity* left,Entity* right)
{
	return left->getPositionInWorld().y>right->getPositionInWorld().y;
}

const char* Layer2D::className()
{
	return FS_LAYER_2D_CLASS_NAME;
}
Layer2D* Layer2D::create()
{
	Layer2D* ret=new Layer2D;
	return ret;
}


Matrix4 Layer2D::getProjectMatrix() 
{
	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			-1024,
			1024);
	return mat;
}

Rect2D Layer2D::getViewArea()const 
{
	return m_viewArea;
}

void Layer2D::toLayerCoord(float* x,float* y)
{
	*x=*x*m_viewArea.width+m_viewArea.x;
	*y=*y*m_viewArea.height+m_viewArea.y;
}

Vector3 Layer2D::toLayerCoord(const Vector3& v)
{
	float x=v.x;
	float y=v.y;
	toLayerCoord(&x,&y);
	return Vector3(x,y,0);
}

void Layer2D::setViewArea(float x,float y,float width,float height)
{
	m_viewArea.set(x,y,width,height);
}


void Layer2D::getViewArea(float* x,float* y,float* width,float* height)
{
	*x=m_viewArea.x;
	*y=m_viewArea.y;
	*width=m_viewArea.width;
	*height=m_viewArea.height;
}




void Layer2D::setViewArea(const Rect2D& area)
{
	m_viewArea=area;
}

void Layer2D::setSortMode(int mode)
{
	m_sortMode=mode;
}
int Layer2D::getSortMode()
{
	return m_sortMode;
}



/* eliminate */
void Layer2D::setEliminate(bool eliminate)
{
	m_eliminate=eliminate;
}

bool Layer2D::getEliminate()
{
	return m_eliminate;
}

void Layer2D::draw(Render* r)
{

	if(m_scissorEnabled)
	{
		r->setScissorEnabled(true);
		r->setScissorArea(m_scissorArea.x,m_scissorArea.y,m_scissorArea.width,m_scissorArea.height);
	}
	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			-1024,
			1024);
	r->setProjectionMatrix(&mat);

	r->pushMatrix();
	r->loadIdentity();

	/* update all child matrix4 */
	updateAllWorldMatrix();

	std::vector<Entity*> entitys;

	getEntityInView(&entitys);
	sortEntity(&entitys);

	int entity_nu=entitys.size();
	for(int i=0;i<entity_nu;i++)
	{
		Entity* ob=entitys[i];
		if(ob->getVisibles()) ob->draws(r,false);
	}

	r->popMatrix();
	if(m_scissorEnabled)
	{
		r->setScissorEnabled(false);
	}
}



void Layer2D::getEntityInView(std::vector<Entity*>* entitys)
{
	/* TODO(add real eliminate here) */
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		FsObject* ob=iter->getValue();
		entitys->push_back((Entity*)ob);
		iter->next();
	}
	delete iter;
}


void Layer2D::sortEntity(std::vector<Entity*>* entitys)
{
	switch(m_sortMode)
	{
		case SORT_NONE:
			break;
		case SORT_ORDER_Z:
			std::sort(entitys->begin(),entitys->end(),FsFuncEntity_SortZolder);
			break;
		case SORT_Y:
			std::sort(entitys->begin(),entitys->end(),FsFuncEntity_SortY);
			break;
		default:
			FS_TRACE_WARN("Unkown Sort Type");
	}
}


Layer2D::Layer2D()
{
	m_viewArea.set(0,0,1,1);
	m_sortMode=SORT_NONE;
	m_eliminate=false;
}
Layer2D::~Layer2D()
{
}


NS_FS_END


