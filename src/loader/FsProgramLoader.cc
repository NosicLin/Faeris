#include "loader/FsLoaderUtil.h"
#include "util/FsScriptUtil.h"
#include "loader/FsProgramLoader.h"
#include "io/FsVFS.h"

NS_FS_BEGIN

Program* ProgramLoader::create(const char* name)
{
	FsFile* file=VFS::open(name);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Load File(%s) For Program",name);
		return NULL;
	}
	Program* prog=create(file);
	file->decRef();
	return prog;
}
Program* ProgramLoader::create(FsFile* file)
{
	if(LoaderUtil::fileType(file)==FS_FTYPE_SCRIPT)
	{
		return createFromScript(file);
	}
	else 
	{
		return createFromBinary(file);
	}
}



Program* ProgramLoader::createFromScript(FsFile* file)
{
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
	{
		FS_TRACE_WARN("Error Script For Program");
		return NULL;
	}

	FsString* v_shader=ScriptUtil::getString(dict,"vertexShader");
	FsString* f_shader=ScriptUtil::getString(dict,"fragmentShader");

	char* v_source=NULL;
	int v_length=0;
	char* f_source=NULL;
	int f_length=0;
	Program* ret=NULL;

	if(v_shader==NULL&&f_shader==NULL)
	{
		dict->decRef();
		FS_TRACE_WARN("Not Shader Found In Program Script");
		return NULL;
	}

	if(v_shader)
	{
		FsFile* v_file=NULL;
		v_file=VFS::open(v_shader->cstr());
		if(v_file)
		{
			v_length=v_file->getLength();
			if(v_length>0)
			{
				v_source=new char[v_length];
				int readbyte=v_file->read(v_source,v_length);

				if(readbyte!=v_length)
				{
					delete[] v_source;
					v_source=NULL;
				}
			}
			v_file->decRef();
		}
		v_shader->decRef();

	}

	if(f_shader)
	{
		FsFile* f_file=NULL;
		f_file=VFS::open(f_shader->cstr());
		if(f_file)
		{
			f_length=f_file->getLength();
			if(f_length>0)
			{
				f_source=new char[f_length];
				int readbyte=f_file->read(f_source,f_length);

				if(readbyte!=f_length)
				{
					delete[] f_source;
					f_source=NULL;
				}
			}
			f_file->decRef();
		}
		f_shader->decRef();
	}

	if(f_source==NULL&&v_source==NULL)
	{
		FS_TRACE_WARN("Not Shader Found In Program Script");
		dict->decRef();
		return NULL;
	}

	ret=Program::create(v_source,v_length,f_source,f_length);
	if(v_source) delete[] v_source;
	if(f_source) delete[] f_source;

	if(ret==NULL)
	{
		FS_TRACE_WARN("Compile Shader Failed");
		dict->decRef();
		return NULL;
	}

	FsArray* uniforms=ScriptUtil::getArray(dict,"uniforms");
	if(uniforms)
	{
		int uniform_nu=uniforms->size();
		for(int i=0;i<uniform_nu;i++)
		{
			FsString* cur_uniform=ScriptUtil::getString(uniforms,i);
			if(!cur_uniform)
			{
				continue;
			}
			ret->addUniform(cur_uniform->cstr());
			cur_uniform->decRef();
		}
		uniforms->decRef();
	}

	FsArray* attrs=ScriptUtil::getArray(dict,"attributes");
	if(attrs)
	{
		int attrs_nu=attrs->size();
		for(int i=0;i<attrs_nu;i++)
		{
			FsString* cur_attr=ScriptUtil::getString(attrs,i);
			if(!cur_attr)
			{
				continue;
			}
			ret->addAttribute(cur_attr->cstr());
			cur_attr->decRef();
		}
		attrs->decRef();
	}
	dict->decRef();
	return ret;
}
Program* ProgramLoader::createFromBinary(FsFile* file)
{

	/*TODO(load from binary file)*/
	return NULL;
}

NS_FS_END 























