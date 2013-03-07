#include "model/FsMesh.h"
#include "graphics/FsRender.h"
#include "math/FsFace3.h"
#include "math/FsVector3.h"

NS_FS_BEGIN 
static const char* s_MeshName="MeshObject";
const char* Mesh::getName()
{
	return s_MeshName;
}

Mesh::Mesh(Geometry* g,Material* m)
{
	FS_SAFE_ADD_REF(g);
	FS_SAFE_ADD_REF(m);
	m_geometry=g;
	m_material=m;
}

Mesh::Mesh()
{
	m_geometry=NULL;
	m_material=NULL;
}

Mesh::~Mesh()
{
	FS_SAFE_DEC_REF(m_geometry);
	FS_SAFE_DEC_REF(m_material);
}


void Mesh::draw(Render* r,int frame,float subFrame)
{
	if(m_material==NULL||m_geometry==NULL)
	{
		return;
	}

	r->setMaterial(m_material);
	r->disableAllAttrArray();

	uint face_nu=m_geometry->getFaceNu();

	Face3* face_pointer=m_geometry->fFacesPointer();
	Geometry::Attribute* attr=NULL;
	FsDict* attrs=NULL;
	if(face_pointer!=NULL)
	{
		attrs=m_geometry->getAttrs();
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

}

NS_FS_END 

