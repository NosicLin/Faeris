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

		r->setMaterial(m);

		FsUint vertex_nu=g->getVertexNu();
		FsUint face_nu=g->getFaceNu();

		Vector3* vertex_pointer=g->vVerticsPointer();
		Vector3* normal_pointer=g->vNormalsPointer();
		TexCoord2* texcoord_pointer=g->vTexCoordsPointer();
		Color* color_pointer=g->vColorsPointer();

		Face3* face_pointer=g->fFacesPointer();

		if((face_pointer!=NULL)&&(vertex_pointer!=NULL))
		{
			r->disableAllClientArray();
			r->enableClientArray(Render::VERTEX_ARRAY);

			/* set vertex array */
			r->setVVertexPointer(vertex_pointer,vertex_nu);

			/* set normal array */
			if(normal_pointer)
			{
				r->enableClientArray(Render::NORMAL_ARRAY);
				r->setVNormalPointer(normal_pointer,vertex_nu);
			}

			/* set texture array */
			if(texcoord_pointer)
			{
				r->enableClientArray(Render::TEXTURE_COORD_ARRAY);
				r->setVTexCoordPointer(texcoord_pointer,vertex_nu);
			}
			if(color_pointer)
			{
				r->enableClientArray(Render::COLOR_ARRAY);
				r->setVColorPointer(color_pointer,vertex_nu);
			}

			/* draw faces */
			r->drawFace3(face_pointer,face_nu);
		}
		if(g) g->decRef();
		if(m) m->decRef();
	}
}

NS_FS_END 

