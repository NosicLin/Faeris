#include "scene/FsLayer2D.h"
#include "util/FsArray.h"
#include "util/FsDict.h"
#include "graphics/FsRender.h"
#include "entity/FsEntity.h"

NS_FS_BEGIN

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

void Layer2D::setOlderMode(int older)
{
	m_older=older;
}
int Layer2D::getOlderMode()
{
	return m_older;
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


	FsArray* entity=getEntityInView();
	sortEntity(entity);

	int entity_nu=entity->size();
	for(int i=0;i<entity_nu;i++)
	{
		Entity* ob=(Entity*) entity->get(i);
		if(ob->visible())
		{
			ob->draw(r,false);
		}
		ob->decRef();
	}
	entity->decRef();
	r->popMatrix();
}



FsArray* Layer2D::getEntityInView()
{
	/* TODO(add real eliminate here) */
	FsArray* ret=FsArray::create();
	FsDict::Iterator iter(m_ownerEntity);
	while(!iter.done())
	{
		FsObject* ob=iter.getValue();
		ret->push(ob);
		ob->decRef();
		iter.next();
	}
	return ret;
}


void Layer2D::sortEntity(FsArray* array)
{
	/* TODO(add real code here) */
	return ;
}

void Layer2D::init()
{
	m_viewArea.set(0,0,1,1);
	m_sortMode=SORT_NONE;
	m_older=UP_OLDER;
}


NS_FS_END

