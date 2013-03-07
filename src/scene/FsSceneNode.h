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
		virtual const char* getName();

	public:
		virtual void update(long msec);
		virtual void updateSelf(long mesc);
		virtual void draw(Render* r);
		virtual void drawSelf(Render* r);


	public:

		Vector3 localToWorld(const Vector3& v);
		Vector3 worldToLocal(const Vector3& v);


		/* relation ship*/
		void addChild(SceneNode* n);
		void remove(SceneNode* n);

		SceneNode* getChildByName(FsString* name,bool recusive=0);
		SceneNode* getChildByName(const char* name,bool recusive=0);

		void updateLocalMatrix();
		void updateWorldMatrix();
		void updateAllWorldMatrix();


	public: /* get transform info */
		Vector3 getPosition(){return m_translate;}
		Vector3 getScale(){return m_scale;}
		Vector3 getRotate(){return m_rotate;}

	public: /* transform */
		void rotate(float rx,float ry,float rz);
		void rotateX(float r);
		void rotateY(float r);
		void rotateZ(float r);

		void scale(float sx,float sy,float sz);
		void scaleX(float s);
		void scaleY(float s);
		void scaleZ(float s);

		void move(float tx,float ty,float tz);
		void moveX(float t);
		void moveY(float t);
		void moveZ(float t);

	public:/* set transform */
		void setRotate(float rx,float ry,float rz);
		void setRotateX(float r);
		void setRotateY(float r);
		void setRotateZ(float r);

		void setScale(float sx,float sy,float sz);
		void setScaleX(float s);
		void setScaleY(float s);
		void setScaleZ(float s);

		void setPosition(float tx,float ty,float tz);
		void setPositionX(float t);
		void setPositionY(float t);
		void setPositionZ(float t);

		void setPositionInWorld(float tx,float ty,float tz);
		void setPositionXInWorld(float t);
		void setPositionYInWorld(float t);
		void setPositionZInWorld(float t);
	public:
		void hide(){m_visible=0;}
		void show(){m_visible=1;}
		bool getVisible(){return m_visible;}

	public:
	//	virtual bool hit(const Ray& r,int bound_type);
		

	private:
		void initData();
		void updateAllWorldMatrixInternal(bool force);
		void notifyChirdWorldMatrixDirty();

	protected:  
		/* flags */
		union 
		{
			struct{
				ulong m_localMatrixDirty:1;
				ulong m_worldMatrixDirty:1;
				ulong m_hasBoundSphere:1;
				ulong m_hasBoundBox:1;
				ulong m_visible:1;
			};
			ulong m_flags;
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



