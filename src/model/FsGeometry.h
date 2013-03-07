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
	uint16_t index;
	uint16_t num;
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
				int type;
				int size; 
				void* value;
				int count;
			public:
				void resize(int nu);
				Attribute(const char* _name,int type,int _size);
				Attribute(const char* _name,int type,int _size,int count);
				Attribute(FsString* _name,int _type,int _size);
				Attribute(FsString* _name,int _type,int _size,int _count);
				virtual ~Attribute();
				virtual const char* className();
		};

	private:
		/*normal info */
		uint m_vertexNu;
		uint m_faceNu;
		uint m_weightNu;

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
		void setVertexNu(uint num);
		void setFaceNu(uint num);
		void setWeight(uint num);

		uint getVertexNu()const{return m_vertexNu;}
		uint getFaceNu()const{return m_faceNu;}
		uint getWeightNu()const{return m_weightNu;}

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
		Geometry(uint vertex,uint face,uint weight);
		Geometry(uint vertex,uint face);
		Geometry(uint vertex);
		~Geometry();
		virtual const char* className();
	protected:
		void init(uint vertex,uint face,uint weight);


};

NS_FS_END 
#endif /*_FS_GEOMETRY_H_*/

