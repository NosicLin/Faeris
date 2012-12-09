#ifndef _FS_SKELETON_MESH_H_
#define _FS_SKELETON_MESH_H_
#include <string>
#include <vector>
#include "FsMacros.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "graphics/FsMaterial.h"
#include "util/FsResource.h"
#include "util/FsResourceMgr.h"

FAERIS_NAMESPACE_BEGIN

class SkeletonVertex
{
	FsUint weightIndex;
	FsUint weightNu;
	TexCoord2 texCoord2; 
	Vector3 normal;
	Vector3 position;
};

class SkeletonWeight
{
	FsUint jointIndex;
	FsFloat weightValue;
	Vector3 position;
};

class SkeletonSubMesh
{
	public:
		FsUint materialIndex;
		std::vector<SkeletonVertex> vertics;
		std::vector<Face3> face3s;
		std::vector<SkeletonVertex> weights;
	public:
		FsUint getVectexNu()const{return vertics.size();}
		FsUint getFace3Nu()const{return face3s.size();}
		FsUint getWeghtNu()const{return weights.size();}
};

class SkeletonJoint
{
	public:
		std::string name;
		FsInt parentIndex;
		Vector3 position;
		Quaternion orientation;
};


class SkeletonMesh:public Resource
{
	public:
		void draw();
		void draw(SkeletonAnimation* anim,FsUint cur,FsUint next,FsFloat interp);
	public:
		bool addAnimation(const FsChar* name,SkeletonAnimation* anim);
		bool removeAnimation(const FsChar* name);
		SkeletonAnimation* getAnimation(const FsChar* name);
	private:
		std::vector<SkeletonJoint> m_joints;
		std::vector<SkeletonSubMesh*> m_subMeshes;
		std::vector<Material*> m_materials;
		std::hash<std::string,SkeletonAnimation*> m_animations;

		friend SkeletonMeshUtil;
};



FAERIS_NAMESPACE_END 

#endif /*_FS_SKELETON_MESH_H_*/



























