#ifndef _FS_SUB_MESH_H_
#define _FS_SUB_MESH_H_

#include "FsMacros.h"

#include "graphics/FsMaterial.h"
#include "model/FsGeometry.h"

NS_FS_BEGIN
class SubMesh
{
	private:
		Geometry* m_geometry;
		Material* m_material;
	public:
		SubMesh();
		SubMesh(Geometry* g,Material* m);
		void setGeometry(Geometry* g);
		void setMaterial(Material* m);

		Geometry* getGeometry()const;
		Material* getMaterial()const;
};
NS_FS_END 
#endif /*_FS_SUB_MESH_H_*/


