#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"

NS_FS_BEGIN

FsVoid Math::srand(FsUlong s)
{
	::srand(s);
}

FsInt Math::random()
{
	return ::rand();
}
FsInt Math::random(FsInt begin,FsInt end)
{
	return begin+::rand()%(end-begin);
}

NS_FS_END
