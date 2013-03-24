#include "entity/FsEntity.h"
#include "graphics/FsRender.h"
#include "scene/FsLayer.h"

NS_FS_BEGIN

 const char* Entity::className()
{
	return FS_ENTITY_CLASS_NAME;
}

Entity* Entity::create()
{
	Entity* ret=new Entity;
	return ret;
}
Entity::Entity()
{
	init();
}

Entity::~Entity()
{
	destroy();
}

void Entity::update(float /*dt*/)
{
}

void Entity::draw(Render* r,bool updateMatrix)
{
	if(updateMatrix)
	{
		updateWorldMatrix();
	}
	r->pushMatrix();
	r->mulMatrix(m_worldMatrix);

//#define FS_SCENE_COORD_DEBUG
#ifdef FS_SCENE_COORD_DEBUG
	r->setMaterial(NULL);
	r->setProgram(NULL);
	r->drawLine(Vector3(-1.0,0,0),Vector3(1.0,0,0),2,Color(255,0,0));

	r->drawLine(Vector3(0.95f,0.05f,0),Vector3(1.0,0,0),1,Color(255,0,0));
	r->drawLine(Vector3(0.95f,-0.05f,0),Vector3(1.0,0,0),1,Color(255,0,0));

	r->drawLine(Vector3(0.95f,0,0.05f),Vector3(1.0,0,0),1,Color(255,0,0));
	r->drawLine(Vector3(0.95f,0,-0.05f),Vector3(1.0,0,0),1,Color(255,0,0));

//	--label X
	r->drawLine(Vector3(1.0,0.05f,0),Vector3(1.06f,-0.05f,0),1,Color(255,0,0));
	r->drawLine(Vector3(1.0,-0.05f,0),Vector3(1.06f,0.05f,0),1,Color(255,0,0));



//	--axis Y
	r->drawLine(Vector3(0,1,0),Vector3(0,-1.0,0),2,Color(0,255,0));

//	--arrow >
	r->drawLine(Vector3(-0.05f,0.95f,0),Vector3(0,1.0,0),1,Color(0,255,0));
	r->drawLine(Vector3(0.05f,0.95f,0),Vector3(0,1.0,0),1,Color(0,255,0));

	r->drawLine(Vector3(0,0.95f,-0.05f),Vector3(0,1.0,0),1,Color(0,255,0));
	r->drawLine(Vector3(0,0.95f,0.05f),Vector3(0,1.0,0),1,Color(0,255,0));

//	--label Y
	r->drawLine(Vector3(0,1.01f,0),Vector3(0,1.07f,0),1,Color(0,255,0));
	r->drawLine(Vector3(-0.03f,1.12f,0),Vector3(0,1.07f,0),1,Color(0,255,0));
	r->drawLine(Vector3(0.03f,1.12f,0),Vector3(0,1.07f,0),1,Color(0,255,0));


//	--axis Z
	r->drawLine(Vector3(0,0,-1.0),Vector3(0,0,1.0),2,Color(0,0,255));

//	--arrow >
	r->drawLine(Vector3(0.05f,0,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(-0.05f,0,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(0,0.05f,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(0,-0.05f,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
#endif 
	r->popMatrix();
}
void Entity::init()
{
	m_name=NULL;
	m_translate.set(0,0,0);
	m_rotate.set(0,0,0);
	m_scale.set(1,1,1);

	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
	m_hasBoundSphere=0;
	m_hasBoundBox=0;
	m_visible=1;

	m_parent=NULL;
	m_chirdren=new FsArray();
}

void Entity::destroy()
{
	assert(m_parent==NULL);
	assert(m_layer==NULL);
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* entity=(Entity*) m_chirdren->get(i);
		entity->setParent(NULL);
		entity->decRef();
	}
	m_chirdren->decRef();
}


bool Entity::updateLocalMatrix()
{
	if(m_localMatrixDirty)
	{
		m_localMatrix.makeCompose(m_translate,m_rotate,FS_EULER_XYZ,m_scale);
		m_localMatrixDirty=0;
		return true;
	}
	return false;
}

bool Entity::updateWorldMatrix()
{
	updateLocalMatrix();
	if(!m_parent)
	{
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_localMatrix;
			m_worldMatrixDirty=0;
			return true;
		}
	}
	else 
	{
		bool dirty=m_parent->updateWorldMatrix();
		if(m_worldMatrixDirty||dirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(m_localMatrix);
			m_worldMatrixDirty=0;
			return true;
		}
	}
	return false;
}

void Entity::updateAllWorldMatrix()
{
	bool dirty=updateWorldMatrix();

	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		Entity* node=(Entity*)iter.getValue();
		node->updateChildWorldMatrix(dirty);
		node->decRef();
		iter.next();
	}
}

void Entity::updateChildWorldMatrix(bool force)
{
	updateLocalMatrix();
	bool dirty=force||m_worldMatrixDirty;

	if(dirty)
	{
		m_worldMatrix=m_parent->m_worldMatrix;
		m_worldMatrix.mul(m_localMatrix);
		m_worldMatrixDirty=0;
	}

	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		Entity* node=(Entity*)iter.getValue();
		node->updateChildWorldMatrix(dirty);
		node->decRef();
		iter.next();
	}
}


Vector3 Entity::localToWorld(const Vector3& v)
{
	updateWorldMatrix();
	return m_worldMatrix.mulVector3(v);
}

Vector3 Entity::worldToLocal(const Vector3& v)
{
	updateWorldMatrix();

	Matrix4 inverse;
	m_worldMatrix.getInverse(&inverse);

	return inverse.mulVector3(v);
}

void Entity::addChild(Entity* n)
{
	if(n->m_parent==this)
	{
		return;
	}

	if(n->m_parent)
	{
		n->m_parent->remove(n);
	}
	else 
	{
		if(n->m_layer)
		{
			n->m_layer->remove(n);
		}
	}
	assert(n->m_parent==NULL);
	assert(n->m_layer==NULL);

	if(m_layer)
	{
		m_layer->takeOwnership(n);
	}
	m_chirdren->push(n);
	n->m_parent=this;
}


FsArray* Entity::allChild()
{
	FsArray* ret=FsArray::create();
	getAllChild(ret);
	return ret;
}
int Entity::childNu()
{
	return m_chirdren->size();
}

void Entity::getAllChild(FsArray* ret)
{
	int child_nu=m_chirdren->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* ob=(Entity*)m_chirdren->get(i);
		ret->push(ob);
		ob->getAllChild(ret);
		ob->decRef();
	}
}



void Entity::remove(Entity* n)
{
	int length=m_chirdren->size();
	for(int i=0;i<length;i++)
	{
		Entity* node=(Entity*)m_chirdren->get(i);
		if(n==node)
		{
			m_chirdren->remove(i);
			node->m_parent=NULL;

			/* if node is manger by a layer, then 
			 * drop the owner ship */
			if(node->m_layer)
			{
				node->m_layer->dropOwnership(node);
				assert(node->m_layer==NULL);
			}
			node->decRef();
			return;
		}
		node->decRef();
	}
	FS_TRACE_WARN("Entity Not Found");
}

void Entity::detach()
{
	if(m_parent)
	{
		m_parent->remove(this);
	}
}

NS_FS_END








