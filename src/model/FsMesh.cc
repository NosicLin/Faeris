#include "model/FsMesh.h"

FAERIS_NAMESPACE_BEGIN 
Mesh::Mesh(FsUint submesh_nu,int type)
{
	m_submesh.resize(submesh_nu);
	m_type=type;
}

SubMesh* Mesh::getSubMesh(FsUint index) const 
{
	if(index>=m_submesh.size())
	{
		return NULL;
	}
	return m_submesh[index];
}

void Mesh::addAnimation(const FsChar* name,Animation* ani)
{
	std::string key(name);
	if(std::map.find(key))
	{

	}
}
void Mesh::removeAnimation(const FsChar* name)
{
}
void Mesh::removeAnimation(Animation* ani)
{
}
Animation* getAnimation(const char* name)
{
}

void Mesh::draw(Render* r)
{
	std::vector<SubMesh>::iterator iter;
	for(iter=m_submesh.begin;iter!=m_submesh.end();++iter)
	{
		Geometry* g=iter->getGeometry();
		if(g==NULL)
		{
			continue;
		}
		Material* m=iter->getMaterial();
		if(m==NULL)
		{
			g->release();
		}
		r->setMaterial(m);

		FsUint vertex_nu=g->getVertexNu();
		FsUint face_nu=g->getFaceNu();
		Vector3* vertex_pointer=g->vVerticsPointer();
		Vector3* normal_pointer=g->vNormalsPointer();
		TexCoord2* texcoord_pointer=g->vTexCoordsPointer();

		Face* face_pointer=fFacesPointer();

		if(face_pointer!=NULL&&vertex_pointer!=NULL)
		{
			r->disableAllClientArray();
			r->enableClientArray(Render::VERTEX_ARRAY);
			r->setVertexPointer(vertex_pointer,vertex_nu);
			if(normal_pointer)
			{
				r->enableClientArray(Render::NORMAL_ARRAY);
				r->setNormalPointer(normal_pointer,vertex_nu);
			}
			if(texcoord_pointer)
			{
				r->enableClientArray(Render::NORMAL_ARRAY);
				r->setTexCoordPointer(texcoord_pointer,vertex_nu);
			}
			r->drawFace3(face_pointer,face_nu);
		}
	}
}

FAERIS_NAMESPACE_END 

