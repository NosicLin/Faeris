#include <stdio.h>
#include <assert.h>
#include "io/FsPackage.h"
#include "io/FsVFS.h"
#include "FsFaerisModule.h"

NS_FS_USE

int main(int argc,char** argv)
{
	if (argc!=2)
	{
		printf("usage:%s <package>\n",argv[0]);
		return 0;
	}

	VFS::moduleInit();


	Package* package=Package::create(argv[1],Package::PACKAGE_FGZ);
	assert(package);
	FsFile* file1=package->getBlock("simsun1.ttc");
	FsFile* file2=package->getBlock("textures/background.png");
	assert(file1);
	assert(file2);


	package->decRef();
	file1->decRef();
	file2->decRef();

	VFS::moduleExit();
	return 0;

}


