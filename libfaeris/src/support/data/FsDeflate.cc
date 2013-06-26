#include "zlib/zlib.h"
#include "support/data/FsDeflate.h"

uint FsDeflate_CompressBound(uint value)
{
	return compressBound(value);
}

int FsDeflate_Compress(uint8_t* src_buf,uint src_length,
		uint8_t* dst_buf,uint* dst_length)
{
	return 0;
}

