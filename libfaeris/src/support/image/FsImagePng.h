#ifndef _FS_IMAGE_PNG_H_
#define _FS_IMAGE_PNG_H_

#include "FsMacros.h"
#include "graphics/FsImage2D.h"
#include "io/FsVFS.h"

NS_FS_BEGIN
Image2D* FsUtil_PngReader(const char* filename);
Image2D* FsUtil_PngReader(FsFile* file);
int FsUtil_PngWriter(FsFile* file,Image2D* img);

NS_FS_END
#endif /*_FS_IMAGE_PNG_H_*/


