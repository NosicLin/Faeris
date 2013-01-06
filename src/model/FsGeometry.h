#ifndef _FS_GEOMETRY_H_
#define _FS_GEOMETRY_H_
#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

class Weight
{
	float percent;
	Vector3 pos;
};

class VertexWeight
{
	FsUint16 index;
	FsUint16 num;
};

/* face info */

/* weight */
#define FS_GEOMETRY_FLAGS_W_WEIGHT_BIT (0x1<<8)

class Geometry:public FsObject
{
	public:
		class Attribute:public FsObject
		{
			public:
				FsString* name;
				FsInt type;
				FsInt size; 
				void* value;
				FsInt count;
			public:
				void resize(FsInt nu);
				Attribute(const FsChar* _name,FsInt _type,FsInt _size);
				Attribute(const FsChar* _name,FsInt _type,FsInt _size,FsInt _count);
				~Attribute();
		};

	private:
		/*normal info */
		FsUint m_vertexNu;
		FsUint m_faceNu;
		FsUint m_weightNu;

		/* vertex attribute */
		FsArray* m_attrs;

		/* gerneral vertex for quick access */
		Attribute* m_vVertics; 
		Attribute* m_vNormals;
		Attribute* m_vColors;
		Attribute* m_vFogs;
		Attribute* m_vTexCoords;

		/* Weight */
		VertexWeight* m_vWeights;

		/* face info */
		Face3* m_fFaces;

		/* skeleton animation */
		Weight* m_wWeights;

	public:

		VertexWeight* vWeightsPointer()const{return m_vWeights;}

		/* face info */
		Face3* fFacesPointer()const{return m_fFaces;}

		/* skeleton animation */
		Weight* wWeightsPointer()const{return m_wWeights;}

	public:
		void setVertexNu(FsUint num);
		void setFaceNu(FsUint num);
		void setWeight(FsUint num);

		FsUint getVertexNu()const{return m_vertexNu;}
		FsUint getFaceNu()const{return m_faceNu;}
		FsUint getWeightNu()const{return m_weightNu;}

		void setVVertics(Attribute* attr);
		void setVColors(Attribute* attr);
		void setVNormals(Attribute* attr);
		void setVTexCoords(Attribute* attr);
		void setVFogs(Attribute* attr);

		Attribute* getVVertics();
		Attribute* getVNormals();
		Attribute* getVColors();
		Attribute* getVTexCoords();
		Attribute* getVFog();

	public:
		Geometry(FsUint vertex,FsUint face,FsUint weight);
		Geometry(FsUint vertex,FsUint face);
		Geometry(FsUint vertex);
		~Geometry();
		virtual const FsChar* getName();
	protected:
		void init(FsUint vertex,FsUint face,FsUint weight,FsLong flags);


};

NS_FS_END 
#endif /*_FS_GEOMETRY_H_*/

