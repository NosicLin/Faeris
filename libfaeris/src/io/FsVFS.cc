#include <string.h>

#include "FsVFS.h"
#include "io/FsSysFile.h"
#include "io/FsPackage.h"
#include "sys/FsSys.h"
#include "util/FsArray.h"
#include "util/FsPathUtil.h"

NS_FS_BEGIN

FS_BEGIN_NAMESPACE(VFS)

/* NameFilter */
NameFilter::~NameFilter()
{

}

const char* NameFilter::className()
{
	return FS_VFS_NAME_FILTER_CLASS_NAME;
}


/* PrefixNameFilter */

PrefixNameFilter* PrefixNameFilter::create(const char* prefix)
{
	return new PrefixNameFilter(prefix);
}

std::string PrefixNameFilter::apply(const char* name)
{
	return m_prefix+name;
}
const char* PrefixNameFilter::className()
{
	return FS_VFS_PREFIX_NAME_FILTER_CLASS_NAME;
}

PrefixNameFilter::PrefixNameFilter(const char* prefix)
{
	m_prefix=prefix;
}
PrefixNameFilter::~PrefixNameFilter()
{
}






/* MapPackage */

MapPackage* MapPackage::create(const char* path,Package* package)
{
	MapPackage* ret=new MapPackage();
	if(!ret->init(path,package))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* MapPackage::getFile(const char* file_name)
{
	int file_name_size=strlen(file_name);
	int path_size=m_path.size();

	if(file_name_size<path_size) 
	{
		return  NULL;
	}


	bool start_with=true;

	for(int i=0;i<path_size;i++)
	{
		if(m_path[i]!=file_name[i])
		{
			start_with=false;
			break;
		}
	}
	if(start_with)
	{
		return m_package->getBlock(file_name+path_size);
	}
	return NULL;
}

const char* MapPackage::className()
{
	return FS_VFS_MAP_PACKAGE_CLASS_NAME;
}

MapPackage::MapPackage()
{
	m_package=NULL;
}
MapPackage::~MapPackage()
{
	FS_SAFE_DEC_REF(m_package);
}

bool MapPackage::init(const char* path,Package* package)
{
	if(package==NULL) return false;
	m_path=path;
	package->addRef();
	m_package=package;
	return true;
}




/* VFS  Module Data */

static FsArray* s_mapPackage=NULL;
static FsArray* s_nameFilter=NULL;
static std::string* s_root=NULL;


bool moduleInit()
{
	s_mapPackage=FsArray::create();
	s_nameFilter=FsArray::create();
	s_root=new std::string(Sys::currentDir()+"/");

	FS_TRACE_WARN("pwd=%s",s_root->c_str());


	return true;
}

bool moduleExit()
{
	FS_SAFE_DEC_REF(s_mapPackage);
	s_mapPackage=NULL;

	FS_SAFE_DEC_REF(s_nameFilter);
	s_nameFilter=NULL;

	if(s_root) delete s_root;
	s_root=NULL;
	return true;
}







void setRoot(const char* path)
{
	*s_root=path;
}






FsFile* rawOpen(const char* name,uint mode)
{
	FsFile* ret=NULL;

	/* file is absolutePath */
	if(PathUtil::absolutePath(name))
	{
		ret=SysFile::open(name,mode);
		return ret;
	}

	std::string rel_path=*s_root+std::string(name);

	/* look with root dir */
	ret=SysFile::open(rel_path.c_str(),mode);
	if(ret!=NULL)
	{
		return ret;
	}


	if(mode!=FS_IO_RDONLY)
	{
		return NULL;
	}

	/* if file is readonly will check it in package */
	int package_nu=s_mapPackage->size();
	for(int i=0;i<package_nu;i++)
	{
		MapPackage* package=(MapPackage*) s_mapPackage->get(i);
		ret=package->getFile(name);
		package->decRef();

		if(ret!=NULL)
		{
			return ret;
		}

	}
	return NULL;
}

FsFile* open(const char* name,uint mode)
{
	FsFile* ret=NULL;


	/* file is relative path */
	ret=rawOpen(name,mode);
	if(ret!=NULL) return ret;


	/* file not find ,so we apply name fileter to it */

	int fileter_nu=s_nameFilter->size();

	for(int i=0;i<fileter_nu;i++)
	{
		NameFilter* f=(NameFilter*)s_nameFilter->get(i);
		std::string filter_name=f->apply(name);
		f->decRef();


		ret=rawOpen(filter_name.c_str(),mode);
		if(ret!=NULL)
		{
			return ret;
		}
	}

	/* file not find */
	return NULL;
}

bool addFilter(NameFilter* filter)
{
	s_nameFilter->push(filter);
	return true;
}
bool removeFilter(NameFilter* filter)
{
	s_nameFilter->remove(filter);
	return true;
}

bool mapPackage(const char* path,Package* package)
{
	MapPackage* map=MapPackage::create(path,package);

	if(!map) return false;

	s_mapPackage->push(map);
	map->decRef();
	return true;

}
bool unmapPackage(const char* path)
{
	/*TODO */
	FS_TRACE_WARN("Not Write Yet");
	return true;
}

FsFile* getStdout()
{
	return SysFile::getStdout();
}
FsFile* getStdin()
{
	return SysFile::getStdin();
}
FsFile* getStderr()
{
	return SysFile::getStderr();
}





FS_END_NAMESPACE(VFS)
NS_FS_END

























