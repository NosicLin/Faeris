#ifndef _FS_MESH_H_
#define _FS_MESH_H_
#include "FsMacros.h"
#include "io/FsResource.h"
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
		void addAnimation(const char* name,Animation* ani);
		void removeAnimation(const char* name);
		void removeAnimation(Animation* ani);
		Animation* getAnimation(const char* name);

		/* render */
		virtual void draw(Render* r,int frame=0,float subframe=0.0f);
	public:
		Mesh();
		Mesh(Geometry* g,Material* m);
		virtual const char* getName();
		virtual ~Mesh();
	private:
		Geometry* m_geometry;
		Material* m_material;
};

NS_FS_END 

#endif /*_FS_MESH_H_*/
