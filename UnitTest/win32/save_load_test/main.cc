#include "FsIoAux.h"


int main()
{
	const char buf[]="my name is chenlin";
	FsIoUtil::savefile("may sfsa/fsfs  sfs/aaa.txt",buf,sizeof(buf));
	return 0;
}


