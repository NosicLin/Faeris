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

Mesh::Mesh(FsInt type)
{
	m_submesh=new FsArray();
	m_type=type;
}

Mesh::~Mesh()
{
	m_submesh->decRef();
}

void Mesh::pushSubMesh(SubMesh* sm)
{
	m_submesh->push(sm);
}

void Mesh::draw(Render* r)
{
	FsArray::Iterator iter(m_submesh);
	while(!iter.done())
	{
		SubMesh* sm=(SubMesh*)iter.getValue();
		Geometry* g=sm->getGeometry();
		Material* m=sm->getMaterial();
		if(m==NULL)
		{
			g->decRef();
			iter.next();
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
					iter.next();
				}
				attrs->decRef();
			}
			r->drawFace3(face_pointer,face_nu);
		}
		if(g) g->decRef();
		if(m) m->decRef();
		iter.next();
	}

}

NS_FS_END 

