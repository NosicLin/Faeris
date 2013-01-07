#ifndef _FS_MESH_UTIL_H_
#define _FS_MESH_UTIL_H_
#include "FsMacros.h"
#include "util/FsResourceMgr.h"
#include "util/FsDict.h"
#include "util/FsArray.h"
#include "util/FsString.h"
#include "model/FsMesh.h"
#include "fsys/FsFile.h"

NS_FS_BEGIN
class  MeshLoader
{
	private:
		static ResourceMgr* m_mgr;
	public:
		static ResourceMgr* getMgr();

		/* load from mgr, it mesh is not create before, it will create 
		 * it and cache it in mgr, if mesh create before, it will return 
		 * the cached.
		 */
		static Mesh* loadFromMgr(const FsChar* name);


	public:
		static Mesh* create(const char* filename);
		static Mesh* create(FsFile* file);
		static FsBool saveMesh(Mesh* mesh,FsFile* file,bool text=true);

		/* load mesh from script file, it will check the mesh type,
		 * but caller must make sure the file type is script file. 
		 */
		static Mesh* createFromScript(FsFile* file);

		/* call must make sure script is right type */
		static Mesh* createStaticMeshFromDict(FsDict* script);
		static Mesh* createShapeMeshFromDict(FsDict* script);
		static Mesh* createSkeletonMeshFromDict(FsDict* script);

		/* load mesh from binary file, it will check the mesh type,
		 * but caller must make sure the file type is binary file.
		 */
		static Mesh* createFromBinary(FsFile* file);

		/* caller must make sure the binary is the right type */
		static Mesh* createStaticMeshFromBinary(FsFile* file);
		static Mesh* createShapeMeshFromBinary(FsFile* file);
		static Mesh* createSkeletonMeshFromBinary(FsFile* file);
};

NS_FS_END

#endif /*_FS_MESH_UTIL_H_*/

