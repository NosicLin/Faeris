#ifndef _FS_ELINES_H_
#define _FS_ELINES_H_ 

#include <vector>
#include "FsMacros.h"
#include "entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "graphics/material/FsPositionColorLineMaterial.h"


NS_FS_BEGIN

class ELines:public Entity 
{
	private:
		class ELinesVertex
		{
			public:
				Vertex3 vertex;
				Color color;
		};

	public:
		enum
		{
			MODE_LINES,
			MODE_STRIP,
			MODE_LOOP,
		};

	public:
		static ELines* create(Vertex3 start,Vertex3 end);
		static Elines* create();
		static Elines* create(int vertex_nu);

	public:

		/* color */
		void setColor(Color c);
		Color getColor();
		void setColor(int index,Color c);
		Color getColor(int index);

		/* vertex */
		void setVertex(int index,Vertex3 v);
		Vertex3 getVertex(int index);

		void append(Vertex3 v,Color c);
		void append(Vertex3 v);

		/* vertex nu */
		void resizeVertexNu(int nu);
		int getVertexNu();

		

		/* line size */
		void setLineSize(float size){m_size=size;}
		float getLineSize(){return m_size;}

		/* opacity */
		void setOpacity(float opacity){m_opacity=opacity;}
		float getOpacity(){return m_opacity;}

		/* mode */
		void setMode(int mode){m_mode=mode;}
		int getMode(){return m_mode;}

	public:
		/* @override FsObject */
		virtual const char* className();

		/* @override Entity */
		virtual const void draw(Render* r,bool updateMatrix);

	protected:
		ELines();
		virtual ~ELines();
		bool init(Vertex3 start,Vertex3 end);
		bool init();
		void destory();


	private:
		float m_size;
		float m_opacity;
		Color m_defaultColor;
		int m_mode;
		std::vector<ELinesVertex> m_vertics;
		PositionColorLineMaterial* m_material;
};


NS_FS_END 



#endif /*_FS_ELINES_H_*/











