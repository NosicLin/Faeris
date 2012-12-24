#include "stdio.h"
#include "stdlib.h"

#include "util/FsMeshUtil.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include "fsys/FsSysFile.h"


using namespace Faeris;
int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("usage:%s <filename>\n",argv[0]);
		exit(-1);
	}

	FsFile* file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("Can't Open File(%s)\n",argv[1]);
		exit(-1);
	}

	Mesh* mesh =MeshUtil::loadMesh(file);
	file->decRef();


	if(mesh==NULL)
	{
		printf("Load Mesh Failed\n");
	}
	else 
	{
		printf("Load Mesh Success\n");
		MeshUtil::saveMesh(mesh,SysFile::getStdout());
	}

	if(mesh) mesh->decRef();
	return 0;
}

