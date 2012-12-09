#ifndef _FS_SKELETON_MESH_UTIL_H_
#define _FS_SKELETON_MESH_UTIL_H_ 
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
class SkeletonMeshUtil 
{
	public:
		/* load SkeletonMesh from file with  postfix is *.skt */
		static SkeletonMesh* loadSkt(FsFile* file);

		/* load SkeletonAnimation from file with postfix is *.sanim */
		static SkeletonAnimation* loadSanim(FsFile* file);

		/* load SkeletonMesh from file with postfix is *.smesh */
		static SkeletonMesh* loadSmesh(FsFile* file);
};

FAERIS_NAMESPACE_END

#endif /*_FS_SKELETON_MESH_UTIL_H_*/

