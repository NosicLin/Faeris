#ifndef _FAERIS_SCENE_NODE_H_
#define _FAERIS_SCENE_NODE_H_


#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsMatrix4.h"
//#include "math/FsBoundSphere.h"
//#include "math/FsBoundBox.h"
#include "util/FsString.h"
#include "util/FsArray.h"


NS_FS_BEGIN
class Render;
class SceneNode :public FsObject
{
	public:
		SceneNode(FsString* name);
		SceneNode();
		virtual ~SceneNode();
		virtual const FsChar* getName();

	public:
		virtual void update(FsLong msec);
		virtual void updateSelf(FsLong mesc);
		virtual void draw(Render* r);
		virtual void drawSelf(Render* r);


	public:

		Vector3 localToWorld(const Vector3& v);
		Vector3 worldToLocal(const Vector3& v);


		/* relation ship*/
		void addChild(SceneNode* n);
		void remove(SceneNode* n);

		SceneNode* getChildByName(FsString* name,FsBool recusive=0);
		SceneNode* getChildByName(const FsChar* name,FsBool recusive=0);

		void updateLocalMatrix();
		void updateWorldMatrix();
		void updateAllWorldMatrix();


	public: /* get transform info */
		Vector3 getPosition(){return m_translate;}
		Vector3 getScale(){return m_scale;}
		Vector3 getRotate(){return m_rotate;}

	public: /* transform */
		void rotate(FsFloat rx,FsFloat ry,FsFloat rz);
		void rotateX(FsFloat r);
		void rotateY(FsFloat r);
		void rotateZ(FsFloat r);

		void scale(FsFloat sx,FsFloat sy,FsFloat sz);
		void scaleX(FsFloat s);
		void scaleY(FsFloat s);
		void scaleZ(FsFloat s);

		void move(FsFloat tx,FsFloat ty,FsFloat tz);
		void moveX(FsFloat t);
		void moveY(FsFloat t);
		void moveZ(FsFloat t);

	public:/* set transform */
		void setRotate(FsFloat rx,FsFloat ry,FsFloat rz);
		void setRotateX(FsFloat r);
		void setRotateY(FsFloat r);
		void setRotateZ(FsFloat r);

		void setScale(FsFloat sx,FsFloat sy,FsFloat sz);
		void setScaleX(FsFloat s);
		void setScaleY(FsFloat s);
		void setScaleZ(FsFloat s);

		void setPosition(FsFloat tx,FsFloat ty,FsFloat tz);
		void setPositionX(FsFloat t);
		void setPositionY(FsFloat t);
		void setPositionZ(FsFloat t);

		void setPositionInWorld(FsFloat tx,FsFloat ty,FsFloat tz);
		void setPositionXInWorld(FsFloat t);
		void setPositionYInWorld(FsFloat t);
		void setPositionZInWorld(FsFloat t);
	public:
		void hide(){m_visible=0;}
		void show(){m_visible=1;}
		FsBool getVisible(){return m_visible;}

	public:
	//	virtual FsBool hit(const Ray& r,FsInt bound_type);
		

	private:
		void initData();
		void updateAllWorldMatrixInternal(FsBool force);
		void notifyChirdWorldMatrixDirty();

	protected:  
		/* flags */
		union 
		{
			struct{
				FsUlong m_localMatrixDirty:1;
				FsUlong m_worldMatrixDirty:1;
				FsUlong m_hasBoundSphere:1;
				FsUlong m_hasBoundBox:1;
				FsUlong m_visible:1;
			};
			FsUlong m_flags;
		};


		FsString* m_name;

		/* transform info */
		Vector3 m_translate;
		Vector3 m_rotate;
		Vector3 m_scale;

		/* matrix */
		Matrix4 m_localMatrix;
		Matrix4 m_worldMatrix;

		/* bool bounding  volume */
	//	BoundSphere m_boundSphere;
	//	BoundBox m_boundBox;


		/* relation ship*/
		SceneNode* m_parent;
		FsArray* m_chirdren;

};


#include "scene/FsSceneNode.inl"
NS_FS_END

#endif 



