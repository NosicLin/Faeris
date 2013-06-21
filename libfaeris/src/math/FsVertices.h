#ifndef _FS_VERTICES_H_
#define _FS_VERTICES_H_

#include "FsMacros.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsColor.h"
#include "math/FsTexCoord2.h"


NS_FS_BEGIN

struct Fs_V2F_T2F
{
	Vector2 v2;
	TexCoord t2;
};


struct Fs_V3F_T2F
{
	Vector3 v3;
	TexCoord t2;
};


NS_FS_END 

#endif /*_FS_VERTICES_H_*/


