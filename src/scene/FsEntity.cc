#include "scene/FsEntity.h"
NS_FS_BEGIN


const char* s_EntityName="EntityObject";
const char* Entity::className()
{
	return s_EntityName;
}

Entity::Entity(Mesh* m)
{
	FS_SAFE_ADD_REF(m);
	m_mesh=m;
}

Entity::Entity()
{
	m_mesh=NULL;
}

Entity::~Entity()
{
	FS_SAFE_DEC_REF(m_mesh);
}

void Entity::setMesh(Mesh* m)
{
	FS_SAFE_ADD_REF(m);
	FS_SAFE_DEC_REF(m_mesh);
	m_mesh=m;
}
void Entity::drawSelf(Render* r)
{
	if(m_mesh)
	{
		m_mesh->draw(r);
	}
}


NS_FS_END

