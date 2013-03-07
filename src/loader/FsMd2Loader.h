#ifndef _FAERIS_FSMD2_LOADER_H_
#define _FAERIS_FSMD2_LOADER_H_

#include "FsMacros.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#define FS_MD2_MAGIC_NUM 844121161
#define FS_MD2_VERSION 8

NS_FS_BEGIN
class FsFile;
struct Md2Header
{
	int32_t m_iMaigcNum;
	int32_t m_iVersion;
	int32_t m_iSkinWidthPx;
	int32_t m_iSkinHeightPx;
	int32_t m_iFrameSize;
	int32_t m_iNumSkins;
	int32_t m_iNumVertices;
	int32_t m_iNumTexCoords;
	int32_t m_iNumTriangles;
	int32_t m_iNumGlCommands;
	int32_t m_iNumFrames;

	int32_t m_iOffsetSkins;
	int32_t m_iOffsetTexCoords;
	int32_t m_iOffsetTriangles;
	int32_t m_iOffsetFrames;
	int32_t m_iOffsetGlCommands;
	int32_t m_iFileSize;
};

struct Md2Frame
{
	char m_caName[16];
	Vector3* m_pVerts;
	Md2Frame():m_pVerts(NULL){}
	~Md2Frame()
	{
		if(m_pVerts)
		{
			delete[] m_pVerts;
		}
	}
};

struct Md2Triangle
{
	uint16_t m_iVertIndics[3];
	uint16_t m_iTexIndics[3];	
};

class Md2Model
{
	public:
		static Md2Model* create(const char* filename);
		static Md2Model* create(FsFile* file);
	private:
		Md2Model(struct Md2Header* h,FsFile* file);

		void loadFrames(struct Md2Header* h,FsFile* file);
		void loadTriangles(struct Md2Header* h,FsFile* file);
		void loadTexCoords(struct Md2Header* h,FsFile* file);
		void loadSkins(struct Md2Header* h,FsFile* file);
	public:
	//private:
		struct Md2Frame* m_pFrames;
		uint m_iFrameNu;
		uint m_iVertexNu;

		TexCoord2* m_pTexCoords;
		uint m_iTexCoordNu;

		struct Md2Triangle* m_pTriangles;
		uint m_iTriangleNu;

		uint m_iSkinNu;
		//FsTexture* m_pTexture;
};



NS_FS_END
#endif /*_FAERIS_FSMD2_LOADER_H_*/

