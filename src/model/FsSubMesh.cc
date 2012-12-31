#include "model/FsSubMesh.h"

NS_FS_BEGIN
SubMesh::SubMesh()
{
	m_geometry=NULL;
	m_material=NULL;
}
SubMesh::SubMesh(Geometry* g,Material* m)
{
	if(g) g->addRef();
	if(m) m->addRef();

	m_geometry=g;
	m_material=m;
}

void SubMesh::setGeometry(Geometry* g)
{
	if(g) g->addRef();
	if(m_geometry) m_geometry->decRef();

	m_geometry=g;
}
void SubMesh::setMaterial(Material* m)
{
	if(m) m->addRef();
	if(m_material) m_material->decRef();
	m_material=m;
}

Geometry* SubMesh::getGeometry()const 
{
	Geometry* g=m_geometry;
	if(g) g->addRef();
	return g;
}
Material* SubMesh::getMaterial()const 
{
	Material* m=m_material;
	if(m) m->addRef();
	return m;
}



NS_FS_END 

