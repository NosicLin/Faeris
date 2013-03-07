#include "string.h"
#include "model/FsGeometry.h"

NS_FS_BEGIN

static const char* s_GeometryName="GeometryObject";
static const char* s_GeometryAttributeName="GeometryAttributeObject";

const char* Geometry::Attribute::getName()
{
	return s_GeometryAttributeName;
}
const char* Geometry::getName()
{
	return s_GeometryName;
}


static int s_typesize(int t)
{
	switch(t)
	{
		case FS_FLOAT:
			return sizeof(float);
		case FS_INT:
			return sizeof(int);
		case FS_INT8:
			return sizeof(int8_t);
		case FS_INT16:
			return sizeof(int16_t);
		case FS_INT32:
			return sizeof(int32_t);
		case FS_UINT8:
			return sizeof(uint8_t);
		case FS_UINT16:
			return sizeof(uint16_t);
		case FS_UINT32:
			return sizeof(uint32_t);
		default:
			FS_TRACE_ERROR("Unkown Type");
	}
	return 0;
}

Geometry::Attribute::Attribute(FsString*  _name,int _type,int _size)
{
	name=_name;
	name->addRef();
	type=_type;
	size=_size;
	count=0;
	value=0;
}

Geometry::Attribute::Attribute(FsString* _name,int _type,int _size,int _count)
{
	name=_name;
	name->addRef();
	type=_type;
	size=_size;
	count=0;
	value=0;
	resize(_count);
}

Geometry::Attribute::Attribute(const char* _name,int _type,int _size)
{
	FsString* fs_name=new FsString(_name);
	name=fs_name;
	type=_type;
	size=_size;
	count=0;
	value=0;
}

Geometry::Attribute::Attribute(const char* _name,int _type,int _size,int _count)
{
	FsString* fs_name=new FsString(_name);
	name=fs_name;
	type=_type;
	size=_size;
	count=0;
	value=0;
	resize(_count);
}


void Geometry::Attribute::resize(int num)
{
	if(count==num) 
	{
		return;
	}
	int min=count<num?count:num;

	if(num==0)
	{
		delete[] (char*)value;
		value=NULL;
	}
	else 
	{

		int new_length=s_typesize(type)*size*num;
		void* new_value=new char[new_length];

		if(value!=NULL)  /* if we has data before, just copy it */
		{
			memcpy(new_value,value,min*s_typesize(type)*size);
			delete[] (char*)value;
		}
		if(num>count) /* set the other value zero */
		{
			memset((char*)new_value+count*s_typesize(type)*size,0,(num-count)*s_typesize(type)*size);
		}
		value=new_value;
	}
	count=num;
}

Geometry::Attribute::~Attribute()
{
	name->decRef();
	if(value)
	{
		delete[] (char*)value;
	}
}


void Geometry::setVertexNu(uint num)
{
	if(m_vertexNu==num)
	{
		return;
	}

	FsDict::Iterator iter(m_attrs);
	while(!iter.done())
	{
		Geometry::Attribute* attr=(Geometry::Attribute*)iter.getValue();
		if(attr)
		{
			attr->resize(num);
			attr->decRef();
		}
		iter.next();
	}
	m_vertexNu=num;
}

void Geometry::setFaceNu(uint num)
{
	if(m_faceNu==num)
	{
		return ;
	}
	uint min=m_faceNu>num?num:m_faceNu;

	if(num==0)
	{
		delete[] m_fFaces;
		m_fFaces=NULL;
	}
	else 
	{
		Face3* face_new=new Face3[num];
		if(m_fFaces!=NULL)
		{
			memcpy(face_new,m_fFaces,sizeof(Face3)*min);
			delete[] m_fFaces;
		}
		if(num>m_faceNu)
		{
			memset(face_new+m_faceNu,0,(num-m_faceNu)*sizeof(Face3));
		}
		m_fFaces=face_new;
	}
	m_faceNu=num;
}

void Geometry::setWeight(uint num)
{
	if(m_weightNu==num)
	{
		return ;
	}

	uint min=m_weightNu<num?m_weightNu:num;
	if(num==0)
	{
		delete[] m_wWeights;
		m_wWeights=NULL;
	}
	else 
	{
		Weight* weight_new=new Weight[num];
		if(m_wWeights!=NULL)
		{
			memcpy(weight_new,m_wWeights,sizeof(Weight)*min);
			delete[] m_wWeights;
		}
		if(num>m_weightNu)
		{
			memset(weight_new+m_weightNu,0,sizeof(Weight)*(num-m_weightNu));
		}
		m_wWeights=weight_new;
	}
	m_weightNu=num;
}


void Geometry::init(uint vertex,uint face,uint weight)
{
	m_attrs=new FsDict();

	m_fFaces=NULL;
	m_wWeights=NULL;
	m_vertexNu=0;
	m_faceNu=0;
	m_weightNu=0;

	setVertexNu(vertex);
	setFaceNu(face);
	setWeight(weight);
}

Geometry::Geometry(uint vertex,uint face,uint weight)
{
	init(vertex,face,weight);
}
Geometry::Geometry(uint vertex,uint face)
{
	init(vertex,face,0);
}
Geometry::Geometry(uint vertex)
{
	init(vertex,0,0);
}

Geometry::~Geometry()
{
	m_attrs->decRef();
	if(m_fFaces) delete[] m_fFaces;
	if(m_wWeights) delete[] m_wWeights;
}

NS_FS_END










