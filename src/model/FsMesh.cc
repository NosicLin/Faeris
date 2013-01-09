#include "model/FsMesh.h"
#include "graphics/FsRender.h"
#include "math/FsFace3.h"
#include "math/FsVector3.h"

NS_FS_BEGIN 
static const FsChar* s_MeshName="MeshObject";
const FsChar* Mesh::getName()
{
	return s_MeshName;
}

Mesh::Mesh(FsUint submesh_nu,int type)
{
	m_submesh.resize(submesh_nu);
	m_type=type;
	for(FsUint i=0;i<submesh_nu;++i)
	{
		m_submesh[i]=new SubMesh;
	}
}

Mesh::~Mesh()
{
	/*TODO*/
}


SubMesh* Mesh::getSubMesh(FsUint index) const 
{
	if(index>=m_submesh.size())
	{
		return NULL;
	}
	return m_submesh[index];
}

/*
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
*/

void Mesh::draw(Render* r)
{
	std::vector<SubMesh*>::iterator iter;
	for(iter=m_submesh.begin();iter!=m_submesh.end();++iter)
	{
		Geometry* g=(*iter)->getGeometry();
		if(g==NULL)
		{
			continue;
		}

		Material* m=(*iter)->getMaterial();
		if(m==NULL)
		{
			g->decRef();
			continue;
		}

		r->setMaterial(m);
		r->disableAllAttrArray();

		FsUint face_nu=g->getFaceNu();

		Face3* face_pointer=g->fFacesPointer();
		Geometry::Attribute* attr=NULL;
		FsDict* attrs=NULL;
		if(face_pointer!=NULL)
		{
			attrs=g->getAttrs();
			if(attrs)
			{
				FsDict::Iterator  iter(attrs);
				while(!iter.done())
				{
					attr=(Geometry::Attribute*)iter.getValue();
					if(attr)
					{
						r->setAndEnableVertexAttrPointer(
								attr->name,
								attr->size,
								attr->type,
								attr->count,
								0,
								attr->value);
						attr->decRef(); 
					}
				}
				attrs->decRef();
			}
			r->drawFace3(face_pointer,face_nu);
		}
		if(g) g->decRef();
		if(m) m->decRef();
	}
}

NS_FS_END 

