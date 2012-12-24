#include "string.h"
#include "model/FsGeometry.h"

FAERIS_NAMESPACE_BEGIN

static const FsChar* s_GeometryName="GeometryObject";

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


	FsUint min=m_vertexNu>num?num:m_vertexNu;
	m_vertexNu=num;
	if(m_flags&V_VERTICS_BIT)
	{
		if(num==0)
		{
			delete[] m_vVertics;
		}
		else 
		{
			Vector3* vertics_new=new Vector3[num];
			if(m_vVertics!=NULL)
			{
				memcpy(vertics_new,m_vVertics,sizeof(Vector3)*min);
				delete[] m_vVertics;
			}
			m_vVertics=vertics_new;
		}
	}
	if(m_flags&V_NORMALS_BIT)
	{
		if(num==0)
		{
			delete[] m_vNormals;
		}
		else 
		{
			Vector3* normal_new=new Vector3[num];
			if(m_vNormals!=NULL)
			{
				memcpy(normal_new,m_vNormals,sizeof(Vector3)*min);
				delete[] m_vNormals;
			}
			m_vNormals=normal_new;
		}
	}
	if(m_flags&V_TEXCOORDS_BIT)
	{
		if(num==0)
		{
			delete[] m_vTexcoords;
		}
		else 
		{
			TexCoord2* texcoord_new=new TexCoord2[num];
			if(m_vTexcoords!=NULL)
			{
				memcpy(texcoord_new,m_vTexcoords,sizeof(TexCoord2)*min);
				delete[] m_vTexcoords;
			}
			m_vTexcoords=texcoord_new;
		}
	}
	if(m_flags&V_COLORS_BIT)
	{
		if(num==0)
		{
			delete[] m_vColors;
		}
		else 
		{
			Color* color_new=new Color[num];
			if(m_vColors!=NULL)
			{
				memcpy(color_new,m_vColors,sizeof(Color)*min);
				delete[] m_vColors;
			}
			m_vColors=color_new;
		}
	}
	if(m_flags&V_WEIGHT_BIT)
	{
		if(num==0)
		{
			delete[] m_vWeights;
		}
		else 
		{
			VertexWeight* weight_new=new VertexWeight[num];
			if(m_vWeights!=NULL)
			{
				memcpy(weight_new,m_vWeights,sizeof(VertexWeight)*min);
				delete[] m_vWeights;
			}
			m_vWeights=weight_new;
		}
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

	if(m_flags&F_FACE_BIT)
	{
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
	if(m_flags&F_NORMAL_BIT)
	{
		if(num==0)
		{
			delete[] m_fNormals;
		}
		else 
		{
			Vector3* normal_new=new Vector3[num];
			if(m_fNormals!=NULL)
			{
				memcpy(normal_new,m_fNormals,sizeof(Vector3)*min);
				delete[] m_fNormals;
			}
			m_fNormals=normal_new;
		}
	}
	if(m_flags&F_COLOR_BIT)
	{
		if(num==0)
		{
			delete[] m_fColors;
		}
		else 
		{
			Color* color_new=new Color[num];
			if(m_fColors!=NULL)
			{
				memcpy(color_new,m_fColors,sizeof(Color)*min);
				delete[] m_fColors;
			}
			m_fColors=color_new;
		}
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

	if(m_flags&W_WEIGHT_BIT)
	{
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
}


void Geometry::init(FsUint vertex,FsUint face,FsUint weight,FsLong flags)
{
	m_flags=flags;
	m_vertexNu=0;
	m_faceNu=0;
	m_weightNu=0;

	m_vVertics=NULL;
	m_vNormals=NULL;
	m_vTexcoords=NULL;
	m_vColors=NULL;
	m_vWeights=NULL;

	m_fFaces=NULL;
	m_fNormals=NULL;
	m_fColors=NULL;

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
	if(m_vVertics)
	{
		delete m_vVertics;
	}
	if(m_vNormals)
	{
		delete m_vNormals;
	}
	if(m_vTexcoords)
	{
		delete m_vTexcoords;
	}
	if(m_vColors)
	{
		delete m_vColors;
	}
	if(m_vWeights)
	{
		delete m_vWeights;
	}
	if(m_fFaces)
	{
		delete m_fFaces;
	}
	if(m_fNormals)
	{
		delete m_fNormals;
	}
	if(m_fColors)
	{
		delete m_fColors;
	}

}

FAERIS_NAMESPACE_END










