

--[[

$#include "common/FsGlobal.h"

class Global@share
{
	public:
		static Scheduler* scheduler();
		static TouchDispatcher* touchDispatcher();
		static Director* director();
		static SysDispatcher* sysDispatcher();

		static Window* window();
		static Render* render();
		static TextureMgr* textureMgr();
};

$#include "FsLuaEngine.h"
bool FsLuaEngine_LoadFile@import(const char* name);

class FsObject 
{
	public:
		const char* className();
	public:
		LUA_TABLE m_scriptData@data;
};

$#include "luaext/FsLuaEntity.h"

class ColorQuad2D@__ColorQuad2D:public Entity
{
	public:
		enum 
		{
			VERTEX_A,
			VERTEX_B,
			VERTEX_C,
			VERTEX_D,
			VERTEX_ALL,
		};
	public:
		void setColor(Color c,int vertex=VERTEX_ALL);
		void setRect(const Rect2D& rect);
		void setOpacity(float opacity);
		float getOpacity();
};

class LuaColorQuad2D@ColorQuad2D:public ColorQuad2D 
{
	public:
		enum 
		{
			VERTEX_A,
			VERTEX_B,
			VERTEX_C,
			VERTEX_D,
			VERTEX_ALL,
		};
	public:
		static LuaColorQuad2D* create(const Rect2D& rect,Color c);
	public:
		void onDraw@draw(Render* r);
		void onUpdate@update(float dt);
}

$#include "entity/FsEntity.h"
$#include "luaext/FsLuaEntity.h"

class Entity@__Entity:public FsObject
{
	public:
		Vector3 localToWorld(const Vector3& v);
		Vector3 worldToLocal(const Vector3& v);

		/* relation ship*/
		void addChild(Entity* n);
		void remove(Entity* n);
		void detach();
		FsArray* allChild();
		int childNu();

	public: /* get transform info */
		Vector3 getPosition();
		void getPosition(float* x=NULL, float* y=NULL,float* z=NULL);
		float getPositionX();
		float getPositionY();
		float getPositionZ();

		/* scale information */
		Vector3 getScale();
		float getScaleX();
		float getScaleY();
		float getScaleZ();

		/* rotate information */
		Vector3 getRotate();
		float getRotateX();
		float getRotateY();
		float getRotateZ();


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

		void setPosition(float tx,float ty,float z=0);
		void setPositionX(float t);
		void setPositionY(float t);
		void setPositionZ(float t);

		/*
		void setPositionInWorld(float tx,float ty,float tz);
		void setPositionXInWorld(float t);
		void setPositionYInWorld(float t);
		void setPositionZInWorld(float t);
		*/

	public:
		void setVisible(bool visible);
		bool visible();
		bool hit2D(float x,float y);
		void draw(Render* render,bool update_matrix=true);
};

class LuaEntity@Entity:public Entity 
{
	public:
		static LuaEntity* create();
	public:
		void onUpdate@update(float dt);
		void onDraw@draw(Render* r);
};

$#include "entity/FsLabelTTF.h"
$#include "luaext/FsLuaEntity.h"
class LabelTTF@__LabelTTF:public Entity
{
	public:
		void setString(const char* str);
		const char* getString();

		void setFont(FontTTF* font);
		FontTTF* getFont();

		void setAlign(int h,int v);
		void getAlign(int* h=NULL,int* v=NULL);

		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();

};

class LuaLabelTTF@LabelTTF:public LabelTTF
{
	public:
		enum 
		{
			ALIGN_V_CENTER,
			ALIGN_V_TOP,
			ALIGN_V_BOTTOM,

			ALIGN_H_LEFT,
			ALIGN_H_RIGHT,
			ALIGN_H_CENTER,

		};
	public:
		static LuaLabelTTF* create(const char* text,FontTTF* font);
	public:
		void onDraw@draw(Render* r);
		void onUpdate@update(float dt);
};

$#include "entity/FsQuad2D.h"
$#include "luaext/FsLuaEntity.h"
class Quad2D@__Quad2D:public Entity 
{
	public:

		/* color */
		void setColor(Color c);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* texture */
		void setTexture(Texture2D* tex);
		Texture2D* getTexture();

		/* texture coord */
		void setTextureCoord(const Rect2D& coord);
		Rect2D getTextureCoord();


		/* Rect2D */
		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();
};

class LuaQuad2D@Quad2D:public Quad2D
{
	public:
		static LuaQuad2D* create(const char* tex);
		static LuaQuad2D* create(const char* tex,Rect2D);
		static LuaQuad2D* create(const char* text,float width,float height);

	public:
		void onDraw@draw(Render* r);
		void onUpdate@update(float dt);
};

$#include "entity/FsSprite2D.h"
$#include "luaext/FsLuaEntity.h"

class Sprite2D@__Sprite2D:public Entity 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:

		/* color */
		void setColor(Color color);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* animation */
		void setAnimation(const char* name);
		void updateAnimation(float dt);

		void playAnimation(int mode=Sprite2D::ANIM_LOOP);
		void startAnimation(int mode=Sprite2D::ANIM_LOOP);
		void stopAnimation();

		bool isAnimationPlaying();


		/* frame */
		void setCurFrame(int frame);
		int getCurFrame();
		int getTotalFrame();

		/* fps */
		int getFps();
};

class LuaSprite2D@Sprite2D:public  Sprite2D 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:
		static LuaSprite2D* create(const char* name);
	public:
		void onDraw@draw(Render* r);
		void onUpdate@update(float dt);
};

$#include "event/FsSysDispatcher.h"

class TouchDispatcher:public FsObject 
{
	public:
		void addEventListener(TouchEventListener* l);
		void removeEventListener(TouchEventListener* l);
};

$#include "luaext/FsLuaSysEventListener.h"

class SysEventListener@__SysEventListener:public FsObject
{
};

class LuaSysEventListener@SysEventListener:public SysEventListener
{
	public:
		static LuaSysEventListener* create();
};

$#include "event/FsTouchDispatcher.h"

class SysDispatcher:public FsObject 
{
	public:
		void addEventListener(SysEventListener* l);
		void removeEventListener(SysEventListener* l);
};

$#include "luaext/FsLuaTouchEventListener.h"

class TouchEventListener@__TouchEventListener:public FsObject 
{
}

class LuaTouchEventListener@TouchEventListener:public TouchEventListener 
{
	public:
		static LuaTouchEventListener* create();
}

$#include "graphics/FsColor.h"
class Color 
{
	public:
		static Color DEFAULT_COLOR;
		static Color RED;
		static Color BLUE;
		static Color GREEN;
		static Color WHITE;
		static Color BLACK;
	public:
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	public:
		Color(unsigned char red,unsigned char green,unsigned char blue,unsigned char alpha);
		Color();
		Color(unsigned char red,unsigned char green,unsigned char blue);

		Color operator+(Color right);
		Color operator-(Color right);
		Color operator*(float s);
		bool operator==(Color right);
};

$#include "graphics/FsFontTTF.h"
class FontTTF:public FsObject
{
	public:
		static FontTTF* create(const char* name,int size);

	public:
		int getHeight();
		int getAscend();
		int getDescend();
};

$#include "graphics/FsRender.h"

class Render:public FsObject 
{
	void setViewport(int x,int y,int width,int height);
	void setClearColor(Color c);
	void setProjectionMatrix(const Matrix4* mat);
	void pushMatrix();
	void popMatrix();
	void loadIdentity();
	void mulMatrix(const Matrix4* m);
	void setMatrix(const Matrix4* m);
	void translate(const Vector3& t);
	void scale(const Vector3& s);
	void rotate(const Vector3& v,float angle);
}

#include "math/MathUtil.h"
namespace Math
{
	float radianToAngle(float radian);
	float angleToRadian(float  angle);

	float cosr(float radian);
	float sinr(float radian);
	float tanr(float radian);
	float acosr(float radian);

	float cosa(float angle);
	float sina(float angle);
	float tana(float angle);
	float acosa(float angle);

	float sqrt(float v);
	float abs(float v);

	FsVoid srand(FsUlong s);
	FsInt random();
	FsInt random(FsInt begin,FsInt end);
};

$#include "math/FsMatrix4.h"

class  Matrix4
{

		Matrix4();
		Matrix4(const float v[16]);

		Matrix4(float v00,float v01,float v02,float v03,
				float v10,float v11,float v12,float v13,
				float v20,float v21,float v22,float v23,
				float v30,float v31,float v32,float v33);


		void add(const Matrix4& n); 
		void mul(const Matrix4& n);

		void mulScaler(float s);
		Vector3 mulVector3(const Vector3& v);
		Vector4 mulVector4(const Vector4& v);



		void transpose();
		void getTranspose(Matrix4* m);
		void inverse();
		void getInverse(Matrix4* m);
		float getDetermiant();


		/* aux function to quick change Matrix4  */
		void makeTranslate(float x,float y,float z);
		void makeTranslate(const Vector3& v);
		void makeRotateX(float theta);
		void makeRotateY(float theta);
		void makeRotateZ(float theta);
		void makeRotateAxis(const Vector3& v,float angle);
		void makeRotateAxis(float x,float y,float z,float angle);

		void makeRotateFromEuler(float x,float y,float z,int type);
		void makeRotateFromEuler(const Vector3& v,int type);

		void makeScale(float x,float y,float z);
		void makeScale(const Vector3& v);
		void makeIdentity();

		void makeCompose(const Vector3& t,const Vector3& r,int r_type,const Vector3& s);

		void makeLookAt(const Vector3& eye,const Vector3& target,const Vector3& up);
		void makeFrustum(float left,float right,float bottom,float top,float n,float f);
		void makePerspective(float fov,float aspect,float n,float f);
		void makeOrthographic(float left,float right,float top,float bottom,float n,float f);


		/* set rotate,scale and translate part in Matrix4 */
		void setTranslate(float x,float y,float z);
		void setTranslate(const Vector3& v);
		void setRotationFromEuler(float rx,float ry,float rz,int type);
		//void setRotationFromQuaternion(const Quaternion& q); 
		void setScale(float sx,float sy,float sz);
		void setScale(const Vector3& v);

		/* transform rotate,scale,translate part in Matrix4 */
		void translate(float vx,float vy,float vz);
		void translate(const Vector3& v);

		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		void rotateByAxis(float x,float y,float z,float angle);
		void rotateByAxis(const Vector3& v,float angle);
	
		void scale(float x,float y,float z);
		void scale(const Vector3& v);

		/* decompose and compose matrix */

	//	void compose(const Vector3& t,const Quaternion& q,const Vector3& s);
	//	void decompose(Vector3* t,Quaternion* q,Vector3* s);
		
		/* get rotate,scale,and translate information from Matrix4 */
		Vector3 getColumnX();
		Vector3 getColumnY();
		Vector3 getColumnZ();


		Vector3 getTranslate();
		Vector3 getScale();
		//Quaternion getRotate();
};

$#include "math/FsRect2D.h"

class Rect2D
{
	public:
		Rect2D(float _x,float _y,float _width,float _height);
		Rect2D(const Vector2& _start,float _width,float _height);
		Rect2D();
	public:
		void set(float _x,float _y,float _width,float _height);

	public:
		float x;
		float y;
		float width;
		float height;
};

$#include "math/FsVector2.h"
class Vector2
{
	public:
		float x;
		float y;
	public:
		Vector2(float fx,float fy);
		Vector2();
		Vector2 add(const Vector2& v)const;
		Vector2 sub(const Vector2& v)const;
		Vector2 scale(float k) const ;
		float dot(const Vector2& v)const;
		Vector2 normal()const;
		void normalize();
		Vector2 proj(const Vector2& v)const;
		float angle(const Vector2& v)const;
		float length() const;
		float length2() const;
		bool equal(const Vector2& v)const ;
};

$#include "math/FsVector3.h"
class Vector3
{
	public:
		float x;
		float y;
		float z;
	public:
		Vector3(float x,float y,float z);
		Vector3();
		Vector3 add(const Vector3& v) const ;
		Vector3 sub(const Vector3& v) const ;
		Vector3 scale(float k) const ;
		float dot(const Vector3& v) const ;
		Vector3 cross(const Vector3& v)const;
		Vector3 normal() const ;
		void normalize() ;
		Vector3 proj(const Vector3& v) const;
		float angle(const Vector3& v) const;
		float length() const;
		float length2() const;
		bool equal(const Vector3& v) const;
		void set(float x,float y,float z);
};

$#include "math/FsVector4.h"
class Vector4
{
	public:
		float x;
		float y;
		float z;
		float w;
	public:
		Vector4(float fx,float fy,float fz,float fw);
		Vector4(float fx,float fy,float fz);
		Vector4();
		Vector4 add(const Vector4& v)const ;
		Vector4 sub(const Vector4& v)const;
		Vector4 scale(float k)const ;
		float dot(const Vector4& v)const;

		Vector4 normal() const ;
		void normalize() ;
		float length() const;
		float length2() const;

		bool equal(const Vector4& v) const;
};

$#include "mgr/FsResourceMgr.h"
class ResourceMgr:public FsObject
{
	public:
		void addSearchPath(const char* path);
		bool existSearchPath(const char* path);
		void removeSearchPath(const char* path);

		Resource* load(const char* path);
		void remove(Resource* res);
		void add(const char* name,Resource* res);
};

$#include "mgr/FsTextureMgr.h"

class TextureMgr:public ResourceMgr 
{

}

$#include "luaext/FsLuaLayer.h"

class ColorLayer@__ColorLayer:public Layer
{
	public:
		void setColor(Color c);
		Color getColor();

};


class LuaColorLayer@ColorLayer:public ColorLayer 
{
	public:
		static LuaColorLayer* create();
		static LuaColorLayer* create(Color c);

	public:
		void onUpdate@update(float dt);
		void onDraw@draw(Render* render);

		bool onTouchBegin@touchBegin(float x,float y);
		bool onTouchEnd@touchEnd(float x,float y);
		bool onTouchMove@touchMove(float x,float y);
}

$#include "scene/FsDirector.h"

class Director:public FsObject
{
	public:
		void push();
		void pop();

		void run(Scene*  scene);

		Scene* current();

		void pause();
		void start();
		bool isRunning();
		void setAutoSwapBuffers(bool swap);
};

$#include "scene/FsLayer2D.h"

class Layer2D@__Layer2D:public Layer
{
	public:
		enum 
		{
			SORT_NONE,
			SORT_Z,
			SORT_Y,
			SORT_X,
		};
		enum 
		{
			DOWN_OLDER,
			UP_OLDER,
		};

	public:
		Matrix4 getProjectMatrix()const ;
		Rect2D getViewArea()const;

		void toLayerCoord(float* x,float* y)const ;
		Vector2 toLayerCoord(const Vector2& v)const ;

		void setViewArea(float x,float y,float width,float height);
		void setViewArea(const Rect2D& area);

		void setSortMode(int mode);
		int getSortMode();

		void setOlderMode(int older);
		int getOlderMode();

		/* eliminate */
		void setEliminate(bool eliminate);
		bool getEliminate();
};

class LuaLayer2D@Layer2D:public Layer2D
{
	public:
		static LuaLayer2D* create();

	public:
		void onUpdate@update(float dt);
		void onDraw@draw(Render* render);

		bool onTouchBegin@touchBegin(float x,float y);
		bool onTouchEnd@touchEnd(float x,float y);
		bool onTouchMove@touchMove(float x,float y);
};

$#include "scene/FsLayer.h"

class Layer@__layer:public FsObject
{
	public:
		/* visible */
		bool visible();
		void setVisible(bool visible);

		/* touch enable */
		bool touchEnabled();
		void setTouchEnabled(bool enable);

		/* entity */
		void add(Entity* entity);
		void remove(Entity* entity);
};

$#include "luaext/FsLuaScene.h"
class Scene@__Scene:public FsObject 
{
	public:
		void push(Layer* layer);
		void pop();
		void insert(int pos,Layer*  layer);
		void replace(int pos,Layer* layer);
		void remove(Layer* layer);

		int layerNu();
		Layer* top();
		Layer* getLayer(int index);
};

class LuaScene@Scene:public Scene
{
	public:
		static LuaScene* create();

	public:
		void onEnter@enter();
		void onExit@exit();
		void onUpdate@update(float dt);
		void onDraw@draw(Render* render);
		void onTouchBegin@touchBegin(float x,float y);
		void onTouchEnd@touchEnd(float x,float y);
		void onTouchMove@touchMove(float x,float y);
};

$#include "scheduler/FsScheduler.h"

class Scheduler :public FsObject
{
	public:
		enum
		{
			HIGHEST,
			HIGH,
			MIDDLE,
			LOW,
			LOWEST,
			PRIORITY_NU,
		};

	public:
		static Scheduler* create();

	public:
		/* inherit FsObject */
		const char* className() ;

	public:
		void start();
		void stop();
		void setFps(int fps);
		void mainLoop();

	public:
		void add(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s,int priority);
};

$#include "sys/FsWindow.h"

class Window:public FsObject
{
		void setCaption(const char* name);
		std::string getCaption(){return m_caption;}
		void setPosition(int x,int y);
		void setSize(uint width,uint height);
		void show();
		void hide();
		void setStyle(long flags);

		void setFullScreen(bool full);

		int getWidth();
		int getHeight();
		int getPosX();
		int getPosY();
} ;

--]]