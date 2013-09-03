#include "action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN
class ScaleToAciton:public Action 
{
	public:
		static ScaleToAciton* create(float sx,float sy,float sz,float time);
		static ScaleToAciton* create(float sx,float sy,float time)
		{
			return create(sx,sy,1,time);
		}
	public:
		virtual bool run(StageElement* target,float dt);
		virtual const char* className();

	protected:
		ScaleToAciton(float sx,float sy,float sz,float time);

	private:
		float m_elapse;
		float m_lifeTime;
		Vector3 m_targetScale;
};


NS_FS_END

