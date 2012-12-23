#ifndef _FS_MESH_H_
#define _FS_MESH_H_
#include "FsMacros.h"
#include "util/FsResource.h"
#include "model/FsSubMesh.h"

FAERIS_NAMESPACE_BEGIN 
class Mesh:public FsResource
{
	public:
		enum 
		{
			TYPE_STATIC,
			TYPE_SHAPE,
			TYPE_SKELETON,
		};
	public:
		FsUint subMeshNu()const{return m_submesh.size();}
		SubMesh* getSubMesh(FsUint index)const;
		FsInt  getType()const{return m_type;} 

		/* animation */
		void addAnimation(const FsChar* name,Animation* ani);
		void removeAnimation(const FsChar* name);
		void removeAnimation(Animation* ani);
		Animation* getAnimation(const FsChar* name);

		/* render */
		virtual void draw(Render* r);
	public:
		Mesh(FsUint submesh_nu,int type);
	private:
		std::vector<SubMesh*> m_submesh;
		std::map<std::string,Animation*> m_animations;
		FsInt m_type;
};

FAERIS_NAMESPACE_END 

#endif /*_FS_MESH_H_*/
