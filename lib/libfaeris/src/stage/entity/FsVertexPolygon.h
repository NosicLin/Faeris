#ifndef _FS_VERTEX_POLYGON_H_
#define _FS_VERTEX_POLYGON_H_ 


#include <vector>
#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsRender.h"
#include "graphics/FsColor.h"
#include "graphics/material/FsMat_V4F.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"


NS_FS_BEGIN

class Mat_V4F;

class VertexPolygon :public Entity
{
	public:
		static VertexPolygon* create();

	public:
		enum 
		{
			POINTS=Render::POINTS,
			LINES=Render::LINES,
			LINE_STRIP=Render::LINE_STRIP,
			LINE_LOOP=Render::LINE_LOOP,
			TRIANGLES=Render::TRIANGLES,
			TRIANGLE_FAN=Render::TRIANGLE_FAN,
			TRIANGLE_STRIP=Render::TRIANGLE_STRIP,
		};

	public:


		void setOpacity(float opacity);
		float getOpacity();

		void setColor(Color color);
		Color getColor();

		void setVertex(uint index,Vector3 v);
		void setVertex(uint index,Vector2 v);
		void setVertex(uint index,float x,float y,float z=0);


		Vector3 getVertex(uint index);

		void append(Vector3 v);
		void append(Vector2 v);
		void append(float x,float y,float z=0);

		void removeVertex(uint index);

		void insertVertex(uint index,Vector3 v );
		void insertVertex(uint index,Vector2 v );
		void insertVertex(uint index,float x,float y,float z=0);



		void resize(int nu);
		int getVertexNu();

		void setMode(int mode);
		int getMode();

		void setPointSize(float size);
		float getPointSize();


	public:
		virtual const char* className();
		virtual void draw(Render* r,bool update_matrix);

	protected:
		VertexPolygon();
		virtual ~VertexPolygon();
		bool init();
		void destruct();

	private:
		float m_opacity;
		Color m_color;
		float m_pointSize;
		int m_mode;
		std::vector<Vector3> m_vertics;
		Mat_V4F* m_material;

};

NS_FS_END

#endif /*_FS_VERTEX_POLYGON_H_*/















