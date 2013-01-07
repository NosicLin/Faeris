#include "string.h"
#include "model/FsGeometry.h"

NS_FS_BEGIN

static const FsChar* s_GeometryName="GeometryObject";
static const FsChar* s_GeometryAttributeName="GeometryAttributeObject";

const FsChar* Geometry::Attribute::getName()
{
	return s_GeometryAttributeName;
}
const FsChar* Geometry::getName()
{
	return s_GeometryName;
}


void Geometry::setVertexNu(FsUint num)
{

	if(m_vertexNu==num)
	{
		return;
	}
}
void Geometry::setFaceNu(FsUint num)
{
	if(m_faceNu==num)
	{
		return ;
	}
	FsUint min=m_faceNu>num?num:m_faceNu;
	m_faceNu=num;

	if(num==0)
	{
		delete[] m_fFaces;
	}
	else 
	{
		Face3* face_new=new Face3[num];
		if(m_fFaces!=NULL)
		{
			memcpy(face_new,m_fFaces,sizeof(Face3)*min);
			delete[] m_fFaces;
		}
		m_fFaces=face_new;
	}
}

void Geometry::setWeight(FsUint num)
{
	if(m_weightNu==num)
	{
		return ;
	}

	FsUint min=m_weightNu<num?m_weightNu:num;
	m_weightNu=num;
	if(num==0)
	{
		delete[] m_wWeights;
	}
	else 
	{
		Weight* weight_new=new Weight[num];
		if(m_wWeights!=NULL)
		{
			memcpy(weight_new,m_wWeights,sizeof(Weight)*min);
			delete[] m_wWeights;
		}
		m_wWeights=weight_new;
	}
}


void Geometry::init(FsUint vertex,FsUint face,FsUint weight,FsLong flags)
{
	m_attrs=new FsArray();

	m_vVertics=NULL;
	m_vNormals=NULL;
	m_vColors=NULL;
	m_vFog=NULL;
	m_vTexcoords=NULL;
	m_vTexcoords1D=NULL;
	m_vTexcoords2D=NULL;
	m_vTexcoords3D=NULL;
	m_fFaces=NULL;
	m_wWeights=NULL;
	setVertexNu(vertex);
	setFaceNu(face);
	setWeight(weight);
}

Geometry::Geometry(FsUint vertex,FsUint face,FsUint weight,FsLong flags)
{
	init(vertex,face,weight,flags);
}
Geometry::Geometry(FsUint vertex,FsUint face,FsLong flags)
{
	init(vertex,face,0,flags);
}
Geometry::Geometry(FsUint vertex,FsLong flags)
{
	init(vertex,0,0,flags);
}

Geometry::~Geometry()
{
	m_attrs->decRef();
	if(m_vVertics) m_vVertics->decRef();
	if(m_vNormals) m_vNormals->decRef();
	if(m_vColors) m_vColors->decRef();
	if(m_vFog) m_vFog->decRef();
	if(m_vTexcoords1D) m_vTexcoords1D->decRef();
	if(m_vTexcoords2D) m_vTexcoords2D->decRef();
	if(m_vTexcoords3D) m_vTexcoords3D->decRef();

	if(m_fFaces) delete[] m_fFaces;

	if(m_wWeights) delete[] m_wWeights;
}

void Geometry::addAttribute(Geometry::Attribute* attr)
{
	m_attrs->push(attr);
}


NS_FS_END










