#ifndef _FS_LOADER_UTIL_H_
#define _FS_LOADER_UITL_H_ 
#include "FsMacros.h"

NS_FS_BEGIN
class FsFile;
class LoaderUtil
{
	public:
		static FsInt fileType(FsFile* file){return FS_FTYPE_SCRIPT;}
		static FsInt parseFsType(const FsChar* t);

		static FsInt parseUniformType(const FsChar* t);
		static const FsChar* uniformTypeToStr(FsInt type);


		static FsInt parseBlendEquation(const FsChar* t);
		static const FsChar* blendEquationToStr(FsInt type);

		static FsInt parseShadeMode(const FsChar* str);
		static const FsChar* shadeModeToStr(FsInt type);

		static FsInt parseBlendFactor(const FsChar* str);
		static const FsChar* blendFactorToStr(FsInt factor);

		static FsInt parseFrontSide(const FsChar* str);
		static const FsChar* frontSideToStr(FsInt type);

		static FsInt parseTextureFilter(const FsChar* str);
		static const FsChar* textureFilterToStr(FsInt type);


		static FsInt parseTextureSwap(const FsChar* str);
		static const FsChar* textureSwapToStr(FsInt type);

		static FsInt parseTextureFormat(const FsChar* str);
		static const FsChar* textureFormatToStr(FsInt type);
};
NS_FS_END

#endif /*_FS_LOADER_UTIL_H_*/

