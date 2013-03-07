#ifndef _FS_ENTITY_H_
#define _FS_ENTITY_H_ 
#include "FsMacros.h"
#include "scene/FsSceneNode.h"
#include "model/FsMesh.h"

NS_FS_BEGIN
class Entity:public SceneNode
{
	public:
		Entity(Mesh* m);
		Entity();
		virtual ~Entity();
		virtual const char* getName();

	public:
		void setMesh(Mesh* m);
		virtual void drawSelf(Render* r);

	private:
		Mesh* m_mesh;
};


NS_FS_END
#endif /*_FS_ENTITY_H_*/


