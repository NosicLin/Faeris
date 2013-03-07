#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"

NS_FS_BEGIN

void Math::srand(ulong s)
{
	::srand(s);
}

int Math::random()
{
	return ::rand();
}
int Math::random(int begin,int end)
{
	return begin+::rand()%(end-begin);
}

NS_FS_END
