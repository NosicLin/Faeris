#include "model/FsSubMesh.h"

NS_FS_BEGIN
static const FsChar* s_SubMeshName="SubMeshObject";
const FsChar* SubMesh::getName()
{
	return s_SubMeshName;
}
SubMesh::SubMesh()
{
	m_geometry=NULL;
	m_material=NULL;
}
SubMesh::SubMesh(Geometry* g,Material* m)
{
	FS_SAFE_ADD_REF(g);
	FS_SAFE_ADD_REF(m);

	m_geometry=g;
	m_material=m;
}
SubMesh::~SubMesh()
{
	FS_SAFE_DEC_REF(m_geometry);
	FS_SAFE_DEC_REF(m_material);

}

void SubMesh::setGeometry(Geometry* g)
{
	FS_SAFE_ADD_REF(g);
	FS_SAFE_DEC_REF(m_geometry);
	m_geometry=g;
}
void SubMesh::setMaterial(Material* m)
{
	FS_SAFE_ADD_REF(m);
	FS_SAFE_DEC_REF(m_material);
	m_material=m;
}

Geometry* SubMesh::getGeometry()
{
	FS_SAFE_ADD_REF(m_geometry);
	return m_geometry;
}
Material* SubMesh::getMaterial()
{
	FS_SAFE_ADD_REF(m_material);
	return m_material;
}



NS_FS_END 

