#ifndef _FS_MESH_ANIMATION_H_
#define _FS_MESH_ANIMATION_H_
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
class MeshAnimation 
{
	public:
		virtual void updateMesh(Mesh* m,float time,bool loop)=0;
		uint getTotoalFrame(){return m_frameNu;}
		float getFps(){return m_fps;}
		float setFps(float fps){m_fps=fps;}
		float getFrameTime(){return 1.0f/(float)getFps();}
		float getTotalTime(){return getFrameTime()*getTotoalFrame();}
	protected:
		uint m_frameNu;
		float m_fps;
};
FAERIS_NAMESPACE_END 

#endif /*_FS_MESH_ANIMATION_H_*/
