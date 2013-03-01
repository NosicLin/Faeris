#include "zlib.h"
#include "support/FsDeflate.h"

FsUint FsDeflate_CompressBound(FsUint value)
{
	return compressBound(value);
}

FsInt FsDeflate_Compress(FsUint8* src_buf,FsUint src_length,
		FsUint* dst_buf,FsUint* dst_length)
{

}

