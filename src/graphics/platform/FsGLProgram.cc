#include "GL/glew.h"
#include "graphics/FsProgram.h"
#include "util/FsLog.h"

#define FS_MAX_GL_SHADER_LOG_LENGTH 1024
#define FS_MAX_GL_PROGRAM_LOG_LENGTH 1024

NS_FS_BEGIN

GLint s_create_shader_object(const FsChar* source,FsInt length,GLint type)
{
	FsChar log_info[FS_MAX_GL_SHADER_LOG_LENGTH];
	GLint compile_result,log_length;

	GLuint shader=0;
	shader=glCreateShader(type);

	const FsChar* all_source[]={source};
	const FsInt all_source_length[]={length};

	glShaderSource(shader,1,all_source,all_source_length);
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_result);

	if(compile_result==GL_FALSE)
	{
		glGetShaderInfoLog(shader,
				FS_MAX_GL_SHADER_LOG_LENGTH,
				&log_length,log_info);
		log_info[FS_MAX_GL_SHADER_LOG_LENGTH-1]='\0';
		FsUtil_Log("Compile Shader(%s)",log_info);
		glDeleteShader(shader);
		return 0;
	}
	return shader;
}


Program* Program::create(
		const FsChar* vertex_src,FsUint v_size,
		const FsChar* fragment_src,FsUint f_size
		)
{
	GLuint program=0;
	GLuint vertex_shader=0;
	GLuint fragment_shader=0;
	FsChar log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH];
	FsInt log_length;
	GLint link_result;
	Program* ret=NULL;

	if(vertex_src==NULL&&fragment_src==NULL)
	{
		FS_TRACE_WARN("No Information About Vertex Shader Or Fragment Shader");
		return NULL;
	}

	/* create vertex shader  object */
	if(vertex_src!=NULL)
	{
		vertex_shader=s_create_shader_object(vertex_src,v_size,GL_VERTEX_SHADER);
		if(vertex_shader==0)
		{
			goto error;
		}
	}


	/* create fragment shader object */
	if(fragment_src!=NULL)
	{
		fragment_shader=s_create_shader_object(fragment_src,f_size,GL_FRAGMENT_SHADER);
		if(fragment_shader==0)
		{
			goto error;
		}
	}

	/* create program object */
	program=glCreateProgram();

	/* attach vertex and fragment shader */
	if(vertex_shader!=0)
	{
		glAttachShader(program,vertex_shader);
	}

	if(fragment_shader!=0)
	{
		glAttachShader(program,fragment_shader);
	}

	/* link program */
	glLinkProgram(program);

	/* check error */
	glGetProgramiv(program,GL_LINK_STATUS,&link_result);
	if(link_result==GL_FALSE)
	{
		glGetProgramInfoLog(program,FS_MAX_GL_PROGRAM_LOG_LENGTH,&log_length,log_info);
		log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH-1]='\0';
		FsUtil_Log("Program Result(%s)",log_info);
		goto error;
	}

	ret=new Program();
	ret->m_program=program;

	/* delete  shader */
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return ret;
error:
	if(vertex_shader)
	{
		glDeleteShader(vertex_shader);
	}
	if(fragment_shader)
	{
		glDeleteShader(fragment_shader);
	}
	if(program)
	{
		glDeleteProgram(program);
	}
	return NULL;
}

FsInt Program::getAttributeLocation(const FsChar* name)
{

	FsString* fs_name=new FsString(name);
	FsInt loc=getAttributeLocation(fs_name);
	fs_name->decRef();
	return loc;
}
FsInt Program::getUniformLocation(const FsChar* name)
{
	FsString* fs_name=new FsString(name);
	FsInt loc=getUniformLocation(fs_name);
	fs_name->decRef();
	return loc;
}

FsInt Program::getAttributeLocation(FsString* name)
{
	FsInt loc=-1;
	if(!m_attrs)
	{
		return -1;
	}

	Location* attr=(Location*) m_attrs->lookup(name);
	if(!attr)
	{
		return -1;
	}
	if(!attr->used)
	{
		loc=-1;
	}
	else 
	{
		if(attr->location==-1)
		{
			attr->location=glGetAttribLocation(m_program,name->cstr());
			if(attr->location==-1)
			{
				attr->used=false;
			}
		}
		loc=attr->location;
	}
	attr->decRef();
	return loc;
}


FsInt Program::getUniformLocation(FsString* name)
{
	FsInt loc=-1;
	if(!m_uniforms)
	{
		return -1;
	}

	Location* u=(Location*) m_uniforms->lookup(name);
	if(!u)
	{
		return -1;
	}
	if(!u->used)
	{
		loc=-1;
	}
	else 
	{
		if(u->location==-1)
		{
			u->location=glGetUniformLocation(m_program,name->cstr());
			if(u->location==-1)
			{
				u->used=false;
			}
		}
		loc=u->location;
	}
	u->decRef();
	return loc;
}





Program::Program()
{
	m_program=0;
	m_uniforms=NULL;
	m_attrs=NULL;
}
Program::~Program()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
	}
	if(m_uniforms)
	{
		m_uniforms->decRef();
	}
	if(m_attrs)
	{
		m_attrs->decRef();
	}
}

const FsChar* s_programName="ProgramObject";
const FsChar* Program::getName()
{
	return s_programName;
}

NS_FS_END 

