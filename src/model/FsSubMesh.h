#ifndef _FS_SUB_MESH_H_
#define _FS_SUB_MESH_H_

#include "FsMacros.h"

#include "material/FsMaterial.h"
#include "model/FsGeometry.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class SubMesh:public FsObject
{
	private:
		Geometry* m_geometry;
		Material* m_material;
	public:
		SubMesh();
		SubMesh(Geometry* g,Material* m);
		void setGeometry(Geometry* g);
		void setMaterial(Material* m);
		Geometry* getGeometry();
		Material* getMaterial();

	public:
		virtual ~SubMesh();
		virtual const FsChar* getName();
};
NS_FS_END 
#endif /*_FS_SUB_MESH_H_*/


