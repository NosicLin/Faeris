#ifndef _FS_GEOMETRY_H_
#define _FS_GEOMETRY_H_
#include "FsMacros.h"
#include "core/FsObject.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"
#include "graphics/FsColor.h"
#include "util/FsString.h"
#include "util/FsDict.h"

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
				FsVoid* value;
				FsInt count;
			public:
				void resize(FsInt nu);
				Attribute(FsString* _name,FsInt _type,FsInt _size);
				Attribute(FsString* _name,FsInt _type,FsInt _size,FsInt _count);
				virtual ~Attribute();
				virtual const FsChar* getName();
		};

	private:
		/*normal info */
		FsUint m_vertexNu;
		FsUint m_faceNu;
		FsUint m_weightNu;

		/* vertex attribute */
		FsDict* m_attrs;

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

		void addAttribute(Attribute* attr)
		{
			attr->resize(m_vertexNu);
			m_attrs->insert(attr->name,attr);
		}

		FsDict* getAttrs()
		{
			m_attrs->addRef();
			return m_attrs;
		}

	public:
		Geometry(FsUint vertex,FsUint face,FsUint weight);
		Geometry(FsUint vertex,FsUint face);
		Geometry(FsUint vertex);
		~Geometry();
		virtual const FsChar* getName();
	protected:
		void init(FsUint vertex,FsUint face,FsUint weight);


};

NS_FS_END 
#endif /*_FS_GEOMETRY_H_*/

