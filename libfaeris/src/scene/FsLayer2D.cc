#include <algorithm>
#include "scene/FsLayer2D.h"
#include "util/FsArray.h"
#include "util/FsDict.h"
#include "graphics/FsRender.h"
#include "entity/FsEntity.h"

NS_FS_BEGIN

static bool FsFuncEntity_SortZolder(Entity* left,Entity* right)
{
	return left->getZorder()<right->getZorder();
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


Matrix4 Layer2D::getProjectMatrix()const 
{
	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			0,
			10000);
	return mat;
}

Rect2D Layer2D::getViewArea()const 
{
	return m_viewArea;
}

void Layer2D::toLayerCoord(float* x,float* y)const
{
	*x=*x*m_viewArea.width+m_viewArea.x;
	*y=*y*m_viewArea.height+m_viewArea.y;
}

Vector2 Layer2D::toLayerCoord(const Vector2& v)const 
{
	float x=v.x;
	float y=v.y;
	toLayerCoord(&x,&y);
	return Vector2(x,y);
}

void Layer2D::setViewArea(float x,float y,float width,float height)
{
	m_viewArea.set(x,y,width,height);
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

	Matrix4 mat;
	mat.makeOrthographic(
			m_viewArea.x,
			m_viewArea.x+m_viewArea.width,
			m_viewArea.y,
			m_viewArea.y+m_viewArea.height,
			0,
			10000);
	r->setProjectionMatrix(&mat);

	r->pushMatrix();
	r->loadIdentity();
	r->translate(Vector3(0,0,-5000));

	/* update all child matrix4 */
	updateAllWorldMatrix();

	std::vector<Entity*> entitys;

	getEntityInView(&entitys);
	sortEntity(&entitys);

	int entity_nu=entitys.size();
	for(int i=0;i<entity_nu;i++)
	{
		Entity* ob=entitys[i];
		if(ob->visible())
		{
			ob->draw(r,false);
		}
	}

	r->popMatrix();
}



void Layer2D::getEntityInView(std::vector<Entity*>* entitys)
{
	/* TODO(add real eliminate here) */
	FsDict::Iterator iter(m_ownerEntity);
	while(!iter.done())
	{
		FsObject* ob=iter.getValue();
		entitys->push_back((Entity*)ob);
		ob->decRef();
		iter.next();
	}
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


