#include "model/FsSkeletonMeshAnimation.h"

FAERIS_NAMESPACE_BEGIN 
SkeletonMeshAnimation::SkeletonMeshAnimation(FsUint jointsNu,FsUint frameNu,FsInt type)
{
	m_jointsHierachy=new Joints[jointsNu];
	m_jointsNu=jointsNu;

	m_jointsFrameData=new JointsFrameData[frameNu];
	m_frameNu=frameNu;
	for(FsUint i=0;i<frameNu;i++)
	{
		m_jointsFrameData[i].setJointsNu(jointsNu);
	}
	m_jointsDataType=type;
}
SkeletonMeshAnimation::~SkeletonMeshAnimation()
{
	delete[] m_jointsHierachy;
	delete[] m_jointsFrameData;
}

JointFrameData* SkeletonMeshAnimation::getJointFrameData(FsUint index)
{
	if(index>=m_frameNu)
	{
		FS_TRACE_WARN("Index Out Of Range");
		return NULL;
	}

	return m_jointsFrameData+index;
}

Joint* SkeletonMeshAnimation::getJoint(FsUint index)
{
	if(index>=m_jointsNu)
	{
		FS_TRACE_WARN("Index Out Of Range");
		return NULL;
	}
	return m_jointsHierachy+index;
}



FAERIS_NAMESPACE_END 

