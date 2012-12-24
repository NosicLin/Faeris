#ifndef _FS_MESH_UTIL_H_
#define _FS_MESH_UTIL_H_
#include "FsMacros.h"
#include "util/FsResourceMgr.h"
#include "util/FsDict.h"
#include "util/FsArray.h"
#include "util/FsString.h"
#include "model/FsMesh.h"
#include "fsys/FsFile.h"

FAERIS_NAMESPACE_BEGIN
class  MeshUtil 
{
	private:
		static ResourceMgr* m_mgr;
	public:
		static ResourceMgr* getMgr();
		static Mesh* loadFromMgr(const FsChar* name);


	public:
		static Mesh* loadMesh(FsFile* file);
		static FsBool saveMesh(Mesh* mesh,FsFile* file,bool text=true);

	protected:
		/* load mesh from script file */
		static Mesh* loadMeshWithScriptFile(FsFile* file);
		static Mesh* parseStaticMeshWithScriptFile(FsDict* script);
		static Mesh* parseShapeMeshWithScriptFile(FsDict* script);
		static Mesh* parseSkeletonMeshWithScriptFile(FsDict* script);

		/* load mesh from binary file */
		static Mesh* loadMeshWithBinaryFile(FsFile* file);
		static Mesh* loadStaticMeshWithBinaryFile(FsFile* file);
		static Mesh* loadShapeMeshWithBinaryFile(FsFile* file);
		static Mesh* loadSkeletonMeshWithBinaryFile(FsFile* file);
};

FAERIS_NAMESPACE_END

#endif /*_FS_MESH_UTIL_H_*/

