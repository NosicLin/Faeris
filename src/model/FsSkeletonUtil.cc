#include "model/FsSkeletonUtil.h"

FAERIS_NAMESPACE_BEGIN

#define FS_SKELETON_MESH_MAGIC_ID  "SKMESH3D"
#define FS_SKELETON_MESH_MAGIC_ID_LENGTH  8
#define FS_SKELETON_MESH_VERSION  0x1

#define FS_SKELETON_MATERIAL_ID "MATE"
#define FS_SKELETON_MATERIAL_ID_LENGTH 4

#define FS_SKELETON_JOINT_ID "JINT" 
#define FS_SKELETON_JOINT_ID_LENGTH 4


class SkeletonMeshHeader 
{
	public:
		FsUchar magicId[FS_SKELETON_MESH_MAGIC_ID_LENGTH];
		FsUint32 version;
		FsUint32 jointsNu;
		FsUint32 jointsOffset;
		FsUint32 meshNu;
		FsUint32 meshOffset;
		FsUint32 materialNu;
		FsUint32 materialOffset;

	public:
		bool valid()
		{
			for(int i=0;i<FS_SKELETON_MESH_MAGIC_ID_LENGTH;i++)
			{
				if(magicId[i]!=FS_SKELETON_SUBMESH_ID_LENGTH;i++)
				{
					return false;
				}
			}
			if(version!=FS_SKELETON_MESH_VERSION)
			{
				return false; 
			}
			return true;
		}
};

class SkeletonSubMeshHeader 
{
	public:
		FsUchar magicId[FS_SKELETON_SUBMESH_ID_LENGTH];
		FsUint32 materialIndex;
		FsUint32 vertexNu;
		FsUint32 VertexOffset;
		FsUint32 face3Nu;
		FsUint32 face3Offset;
		FsUint32 weightNu;
		FsUint32 weightOffset;

	public:
		bool valid()
		{
			for(int i=0;i<FS_SKELETON_SUBMESH_ID_LENGTH;i++)
			{
				if(magicId[i]!=FS_SKELETON_SUBMESH_ID[i])
				{
					return false;
				}
			}
			return true;
		}
};

SkeletonMesh* loadSmesh(FsFile* file)
{
	SkeletonMeshHeader mesh_header;
	FsInt readbyte;
	readbyte=file->read(&mesh_header,sizeof(mesh_header));
	if(readbyte<sizeof(mesh_header))
	{

		FS_TRACE_WARN("Can't Read Full Header Of *.smesh Format File");
		return NULL;
	}


FAERIS_NAMESPACE_END

