#ifndef _FS_MESH_H_
#define _FS_MESH_H_
#include "FsMacros.h"
#include "util/FsResource.h"
#include "util/FsArray.h"
#include "model/FsGeometry.h"
#include "material/FsMaterial.h"

NS_FS_BEGIN 
class Animation;
class Mesh:public Resource
{
	public:
		enum 
		{
			TYPE_STATIC,
			TYPE_SHAPE,
			TYPE_SKELETON,
		};
	public:
		void setGeometry(Geometry* g);
		void setMaterial(Material* m);
		Geometry* getGeometry();
		Material* getMaterial();

		/* animation */
		void addAnimation(const FsChar* name,Animation* ani);
		void removeAnimation(const FsChar* name);
		void removeAnimation(Animation* ani);
		Animation* getAnimation(const FsChar* name);

		/* render */
		virtual void draw(Render* r,FsInt frame=0,FsFloat subframe=0.0f);
	public:
		Mesh();
		Mesh(Geometry* g,Material* m);
		virtual const FsChar* getName();
		virtual ~Mesh();
	private:
		Geometry* m_geometry;
		Material* m_material;
};

NS_FS_END 

#endif /*_FS_MESH_H_*/
