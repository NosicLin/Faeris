#ifndef _FAERIS_ENTITY_H_
#define _FAERIS_ENTITY_H_


#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsMatrix4.h"
#include "math/FsRect2D.h"
#include "util/FsString.h"
#include "util/FsArray.h"

NS_FS_BEGIN
class Render;
class Layer;
class Entity :public FsObject
{
	public:
		Entity* create();

	public:
		virtual void update(float dt);
		virtual void draw(Render* r,bool updateMatrix=true);


		/* inherit FsObject */
		virtual const char* className();

	public:

		Vector3 localToWorld(const Vector3& v);
		Vector3 worldToLocal(const Vector3& v);

		/* relation ship*/
		void addChild(Entity* n);
		void remove(Entity* n);
		void detach();
		FsArray* allChild();
		int childNu();

		//Entity* getChildByName(FsString* name,bool recusive=0);
		//Entity* getChildByName(const char* name,bool recusive=0);

		bool updateLocalMatrix();
		bool updateWorldMatrix();
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
		void setVisible(bool visible){m_visible=visible;}
		bool visible(){return m_visible;}

		/* for hiting */
		virtual bool hit2D(float x,float y);

	protected:
		Entity();
		virtual ~Entity();

		void init();
		void init(FsString* name);
		void destroy();
		void updateChildWorldMatrix(bool force);
		void getAllChild(FsArray* array);
	
		Entity* parent(){return m_parent;}
		void setParent(Entity* parent){m_parent=parent;}
		void setLayer(Layer* layer){m_layer=layer;}
		Layer* layer(){return m_layer;}


	protected:  
		/* flags */
		union 
		{
			struct{
				ulong m_localMatrixDirty:1;
				ulong m_worldMatrixDirty:1;
				ulong m_hasBoundSphere:1;
				ulong m_hasBoundSphere2D:1;
				ulong m_hasBoundBox:1;
				ulong m_hasBoundBox2D:1;
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


		/* relation ship*/
		Layer* m_layer;
		Entity* m_parent;
		FsArray* m_chirdren;

		/* bound box */
		Rect2D m_boundBox2D;


		friend Layer;
};

#include "entity/FsEntity.inl"
NS_FS_END

#endif 




