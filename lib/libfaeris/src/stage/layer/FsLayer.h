#ifndef _FS_LAYER_H_
#define _FS_LAYER_H_

#include "stage/FsStageElement.h"
#include "math/FsRect2D.h"

NS_FS_BEGIN
class Entity;
class Scene;
class Render;
class FsDict;
class FsSlowDict;
class Vector2;
class TouchEvent;
class Scene;

class Layer:public StageElement
{
	public:
		/* visible */
		bool visible(){return m_visible;}
		void setVisible(bool visible){m_visible=visible;}

		/* touch enable */
		bool touchEnabled(){return m_touchEnabled;}
		void setTouchEnabled(bool enable){m_touchEnabled=enable;}

		/* scissor */
		void setScissorArea(float x,float y,float width,float height);
		void getScissorArea(float* x,float* y,float* width,float* height);
		bool scissorEnabled(){return m_scissorEnabled;}
		void setScissorEnabled(bool enable){m_scissorEnabled=enable;}

		void clearEntity();
		Scene* getScene();

		/* entity */
		void add(Entity* entity);
		void remove(Entity* entity);

		/* used for Entity parent change,
		 * user can't direct call this interface */
		void takeOwnership(Entity* entity);
		void dropOwnership(Entity* entity);


	public:
		/* event hook */
		virtual void update(float dt);
		virtual void draw(Render* render);

		/* touch event */
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* touches event */
		virtual bool touchesBegin(TouchEvent* event);
		virtual bool touchesPointerDown(TouchEvent* event);
		virtual bool touchesMove(TouchEvent* event);
		virtual bool touchesPointerUp(TouchEvent* event);
		virtual bool touchesEnd(TouchEvent* event);

		/* drop data */
		virtual void drop(bool recursion=true);


		/* inherit FsObject */
		virtual const char* className();

	public:
		void updateEntity(float dt);

	protected:
		Layer();
		virtual ~Layer();
		void init();
		void destroy();
		void updateAllWorldMatrix();
	

	protected:
		FsDict* m_entity;  /* direct add to layer */
		FsSlowDict* m_ownerEntity; /* all sub chirld */
		bool m_visible;
		bool m_touchEnabled;

		Rect2D m_scissorArea;
		bool m_scissorEnabled;

		Scene* m_scene;

		friend class Scene;

};
NS_FS_END

#endif /*_FS_LAYER_H_*/

