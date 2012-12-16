#ifndef _FS_GEOMETRY_H_
#define _FS_GEOMETRY_H_
#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "graphics/FsColor.h"

FAERIS_NAMESPACE_BEGIN

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


/* vertex info */
#define FS_GEOMETRY_FLAGS_V_VERTICS_BIT (0x1<<0)
#define FS_GEOMETRY_FLAGS_V_NORMALS_BIT (0x1<<1)
#define FS_GEOMETRY_FLAGS_V_TEXCOORDS_BIT (0x1<<2)
#define FS_GEOMETRY_FLAGS_V_COLORS_BIT (0x1<<3) 
#define FS_GEOMETRY_FLAGS_V_WEIGHT_BIT (0x1<<4)


/* face info */
#define FS_GEOMETRY_FLAGS_F_FACE_BIT (0x1<<5)
#define FS_GEOMETRY_FLAGS_F_NORMAL_BIT (0x1<<6) 
#define FS_GEOMETRY_FLAGS_F_COLOR_BIT (0x1<<7)

/* weight */
#define FS_GEOMETRY_FLAGS_W_WEIGHT_BIT (0x1<<8)

class Geometry:public FsObject
{
	private:
		/* flags bit */
		FsLong m_flags;

		/*normal info */
		FsUint m_vertexNu;
		FsUint m_faceNu;
		FsUint m_weightNu;

		/* vertex info */
		Vector3* m_vVertics;
		Vector3* m_vNormals;
		TexCoord2* m_vTexcoords;
		Color* m_vColors;
		VertexWeight* m_vWeights;

		/* face info */
		Face3* m_fFaces;
		Vector3* m_fNormals;
		Color* m_fColors;

		/* skeleton animation */
		Weight* m_wWeights;

		/* TODO(shader extend)*/
		/*Attribute attrs*/
	public:
		/* vertex info */
		Vector3* vVerticsPointer()const{return m_vVertics;}
		Vector3* vNormalsPointer()const{return m_vNormals;}
		TexCoord2* vTexCoordsPointer()const{return m_vTexcoords;}
		Color* vColorPointer()const {return m_vColors;}
		VertexWeight* vWeightPointer()const{return m_vWeights;}

		/* face info */
		Face3* fFacesPointer()const{return m_fFaces;}
		Vector3* fNormalsPointer()const {return m_fNormals;}
		Color* fColorPointer()const {return m_fColors;}

		/* skeleton animation */
		Weight* wWeightPointer()const{return m_wWeights;}

	public:
		void setVertexNu(FsUint num);
		void setFaceNu(FsUint num);
		void setWeight(FsUint num);

		FsUint getVertexNu()const{return m_vertexNu;}
		FsUint getFaceNu()const{return m_faceNu;}
		FsUint getWeightNu()const{return m_weightNu;}

	public:
		Geometry(FsUint vertex,FsUint face,FsUint weight,FsLong flags);
		Geometry(FsUint vertex,FsUint face,FsLong flags);
		Geometry(FsUint vertex,FsLong flags);
		~Geometry();
	protected:
		void init(FsUint vertex,FsUint face,FsUint weight,FsLong flags);


};

FAERIS_NAMESPACE_END 
#endif /*_FS_GEOMETRY_H_*/

