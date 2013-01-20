#ifndef _FAERIS_SCENE_NODE_H_
#define _FAERIS_SCENE_NODE_H_


#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsMatrix44.h"
#include "math/FsBoundSphere.h"
#include "math/FsBoundBox.h"
#include "util/FsString.h"
#include "util/FsList.h"

NS_FS_BEGIN
class SceneNode :public FsObject.h,public FsList;
{
	public:
		SceneNode(FsString* name);
		SceneNode();

	public:
		virtual void update(FsLong msec);
		virtual void draw(Render* r);

	public:

		Vector3 localToWorld(Vector3 l);
		Vector3 worldToLocal(Vector3 l);


		/* relation ship*/
		void addChirld(Node* n);
		void remove(node* n);
		void kill();

		SceneNode* getChildByName(FsString* name,FsBool recusive=0);
		SceneNode* getChildByName(const FsChar* name,FsBool recusive=0);

		void updateLocalMatrix();
		void updateWorldMatrix(FsBool force);

	public:
		virtual Node* clone(FsBool deep=0);
		virtual void draw(Render* );

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
		virtual FsBool hit(const Ray& r);
		

	private:
		void initData();



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
		FsFloat m_tx,m_ty,m_tz;
		FsFloat m_rx,m_ry,m_rz;
		FsFloat m_sx,m_sy,m_sz;

		/* matrix */
		Matrix4 m_localMatrix;
		Matrix4 m_worldMatrix;

		/* bool bounding  volume */
		BoundSphere m_boundSphere;
		BoundBox m_boundBox;


		/* relation ship*/
		Node* m_parent;

		FsListHead m_chirldHead;
		FsListHead m_slibing;
};
NS_FS_END

#endif 



