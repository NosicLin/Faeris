#ifndef _FS_LOADER_UTIL_H_
#define _FS_LOADER_UITL_H_ 
#include "FsMacros.h"

NS_FS_BEGIN
class FsFile;
class LoaderUtil
{
	public:
		static int fileType(FsFile* file){return FS_FTYPE_SCRIPT;}
		static int parseFsType(const char* t);

		static int parseUniformType(const char* t);
		static const char* uniformTypeToStr(int type);


		static int parseBlendEquation(const char* t);
		static const char* blendEquationToStr(int type);

		static int parseShadeMode(const char* str);
		static const char* shadeModeToStr(int type);

		static int parseBlendFactor(const char* str);
		static const char* blendFactorToStr(int factor);

		static int parseFrontSide(const char* str);
		static const char* frontSideToStr(int type);

		static int parseTextureFilter(const char* str);
		static const char* textureFilterToStr(int type);


		static int parseTextureSwap(const char* str);
		static const char* textureSwapToStr(int type);

		static int parseTextureFormat(const char* str);
		static const char* textureFormatToStr(int type);
};
NS_FS_END

#endif /*_FS_LOADER_UTIL_H_*/

