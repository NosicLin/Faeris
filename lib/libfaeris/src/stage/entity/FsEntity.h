#ifndef _FAERIS_ENTITY_H_
#define _FAERIS_ENTITY_H_


#include "FsMacros.h"
#include "stage/FsStageElement.h"
#include "math/FsVector3.h"
#include "math/FsMatrix4.h"
#include "math/FsRect2D.h"
#include "support/util/FsString.h"
#include "support/util/FsArray.h"

NS_FS_BEGIN
class Render;
class Layer;
class Entity :public StageElement
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
		Entity* getParent();

		void remove(Entity* n);
		void clearChild();
		Layer* getLayer();

		void detach();
		FsArray* allChild();
		int childNu();


		void drop(bool recusive=true);

		//Entity* getChildByName(FsString* name,bool recusive=0);
		//Entity* getChildByName(const char* name,bool recusive=0);

		bool updateLocalMatrix();
		bool updateWorldMatrix();
		void updateAllWorldMatrix();

	public: /* zorlder */
		float getZorder(){return m_zorlder;}
		void setZorder(float z){m_zorlder=z;}

		/* used for layer to sort */
		uint32_t getAddOlder(){return m_addOlder;}
		void  setAddOlder(uint32_t older){ m_addOlder=older;}


	public: /* get transform info */
		Vector3 getPosition(){return m_translate;}
		void getPosition(float* x,float* y,float* z)
		{
			*x=m_translate.x;
			*y=m_translate.y;
			*z=m_translate.z;
		}
		float getPositionX(){return m_translate.x;}
		float getPositionY(){return m_translate.y;}
		float getPositionZ(){return m_translate.z;}

		/* scale information */
		Vector3 getScale(){return m_scale;}
		float getScaleX(){return m_scale.x;}
		float getScaleY(){return m_scale.y;}
		float getScaleZ(){return m_scale.z;}


		/* rotate information */
		Vector3 getRotate(){return m_rotate;}
		float getRotateX(){return m_rotate.x;}
		float getRotateY(){return m_rotate.y;}
		float getRotateZ(){return m_rotate.z;}

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

		void setScale(const Vector3& s);
		void setScale(float sx,float sy,float sz);
		void setScaleX(float s);
		void setScaleY(float s);
		void setScaleZ(float s);

		void setPosition(float tx,float ty,float tz);
		void setPosition(const Vector3& pos);
		void setPositionX(float t);
		void setPositionY(float t);
		void setPositionZ(float t);

	public: /* world transform */
		void setPositionInWorld(float tx,float ty,float tz);
		void setPositionInWorld(const Vector3& v);

		Vector3 getPositionInWorld();
		void getPositionInWorld(float* x,float* y,float* z);

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

		/* zorlder */
		float m_zorlder;
		uint32_t m_addOlder;

		/* matrix */
		Matrix4 m_localMatrix;
		Matrix4 m_worldMatrix;


		/* relation ship*/
		Layer* m_layer;
		Entity* m_parent;
		FsArray* m_chirdren;

		/* bound box */
		Rect2D m_boundBox2D;




		friend class Layer;
};

#include "stage/entity/FsEntity.inl"
NS_FS_END

#endif 




