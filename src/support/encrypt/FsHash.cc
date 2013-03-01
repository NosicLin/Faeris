#include "encrypt/FsHash.h"
FsUlong FsHash_JCode(const char* str)
{
	FsUlong hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}

