#ifndef _FS_DIRECTOR_H_
#define _FS_DIRECTOR_H_
#include "FsMacros.h"
#include "scheduler/FsSchedulerTarget.h"

NS_FS_BEGIN
class Scene;
class DirectorTouchEventListener;
class FsArray;
class Vector2;
class Render;
class TouchEvent;
class Director :public SchedulerTarget
{
	public:
		static Director* create();

	public:
		/* inherit FsObject */
		virtual const char* className();

		/* inherit SchedulerTarget */
		virtual void update(int priority,float dt);

	public:
		void push();
		void pop();

		void run(Scene*  scene);

		Scene* current();

		void pause();
		void start();

		bool isRunning();
		void setAutoSwapBuffers(bool swap);

	protected:
		Director();
		~Director();
		void init();
		void destroy();
		void repace(Scene* scene);

		void draw();
		void update(float dt);

		void touchBegin(float x,float y);
		void touchMove(float x,float y);
		void touchEnd(float x,float y);
		void touchesBegin(TouchEvent* event);
		void touchesPointerDown(TouchEvent* event);
		void touchesMove(TouchEvent* event);
		void touchesPointerUp(TouchEvent* event);
		void touchesEnd(TouchEvent* event);

	private:
		Scene* m_current;

		Scene* m_next;
		bool m_sceneChange;

		FsArray* m_secenQueue;
		bool m_stop;
		bool m_autoSwapBuffers;
		DirectorTouchEventListener* m_touchEventListener;

		friend class DirectorTouchEventListener;

};


NS_FS_END 

#endif /*_FS_DIRECTOR_H_*/

