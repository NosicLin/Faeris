#ifndef _FS_SCENE_H_
#define _FS_SCENE_H_

#include "FsMacros.h"
#include "core/FsObject.h"



NS_FS_BEGIN
class Render;
class Layer;
class FsArray;
class Vector2;
class Scene:public FsObject
{
	public:
		static Scene* create();
	public:
		/* layer operation */
		void push(Layer* layer);
		void pop();
		void insert(int pos,Layer*  layer);
		void replace(int pos,Layer* layer);
		void remove(Layer* layer);

	public:
		/* event hook */
		virtual void enter();
		virtual void exit();
		virtual void update(float dt);
		virtual void draw(Render* render);
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);
		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);

		/*  inherit FsObject */
		virtual const char* className();
	protected:
		Scene();
		~Scene();
		void init();
		void destroy();

	private:
		FsArray* m_layers;
};
NS_FS_END
#endif /*_FS_SCENE_H_ */

