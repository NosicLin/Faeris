#ifndef _FS_MESH_ANIMATION_H_
#define _FS_MESH_ANIMATION_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
class MeshAnimation 
{
	public:
		virtual void updateMesh(Mesh* m,FsFloat time,bool loop)=0;
		FsUint getTotoalFrame(){return m_frameNu;}
		FsFloat getFps(){return m_fps;}
		FsFloat setFps(FsFloat fps){m_fps=fps;}
		FsFloat getFrameTime(){return 1.0f/(FsFloat)getFps();}
		FsFloat getTotalTime(){return getFrameTime()*getTotoalFrame();}
	protected:
		FsUint m_frameNu;
		FsFloat m_fps;
};
FAERIS_NAMESPACE_END 

#endif /*_FS_MESH_ANIMATION_H_*/
