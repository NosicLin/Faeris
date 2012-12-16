#ifndef _FS_SKELETON_MESH_ANIMATION_H_
#define _FS_SKELETON_MESH_ANIMATION_H_ 
#include "FsMacros.h"
#include "model/FsMeshAnimation.h"
FAERIS_NAMESPACE_BEGIN
class SkeletonMeshAnimation:public MeshAnimation
{
	public:
		enum
		{
			JOINT_DATA_RELATIVE,
			JOINT_DATA_ABSOLUTE
		};
		class JointData
		{
			public:
				Vector3 translate;
				Quaternion roatation;
		};

		class JointFrameData
		{
			public:
				FsUint jointsNu
				JointsData* jointsData;
			public:
				JointsFrameData():jointsData(NULL),jointsNu(0){}
				~JointsFrameData(){if(jointsData) delete[] jointsData;}
				void setJointsNu(FsUint _jointsNu)
				{
					if(jointsData)
					{
						delete jointsData;
					}
					jointsData=new JointData[_jointsNu];
					jointsNu=_jointsNu;
				}
		};

		class Joint
		{
			public:
				std::string name;
				FsInt father;
		};
	public:
		virtual void updateMesh(Mesh* m,FsFloat time,bool loop);
	public:
		SkeletonMeshAnimation(FsUint jointsNu,FsUint frameNu,FsInt type);
		~SkeletonMeshAnimation();
		void setJointDataType(FsInt type);
		JointFrameData* getJointFrameData(FsUint index);
		Joint* getJoints(FsUint index);
	protected:
		void jointDataToAbsolute();
		void jointDataToRelative();
	private:
		/* Inhrit From MeshAnimation:
		 * 	1) FsUint m_frameNu;
		 * 	2) FsFloat m_fps;
		 */
		FsInt m_jointsDataType;
		FsUint m_jointsNu;
		Joint* m_jointsHierachy;
		JointsFrameData* m_jointsFrameData;
};

FAERIS_NAMESPACE_END 

#endif /*_FS_SKELETON_MESH_H_*/

