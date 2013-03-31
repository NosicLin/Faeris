#include "data/FsHash.h"
ulong FsHash_JCode(const char* str)
{
	ulong hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}

