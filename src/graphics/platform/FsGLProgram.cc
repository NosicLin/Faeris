#include "GL/glew.h"
#include "graphics/FsProgram.h"
#include "util/FsLog.h"

#define FS_MAX_GL_SHADER_LOG_LENGTH 1024
#define FS_MAX_GL_PROGRAM_LOG_LENGTH 1024

NS_FS_BEGIN
GLint s_create_shader_object(const FsChar* source,FsInt length,FsInt type)
{
	FsInt length,readbyte;
	FsChar* source=NULL;
	FsChar log_info[FS_MAX_GL_SHADER_LOG_LENGTH];
	Shader* ret=NULL;
	GLint compile_result,log_length;

	GLenum type_gl;
	switch(type)
	{
		case VERTEX_SHADER:
			type_gl=GL_VERTEX_SHADER;
			break;
		case FRAGMENT_SHADER:
			type_gl=GL_FRAGMENT_SHADER;
			break;
		default:
			FS_TRACE_WARN("Unkown Type");
			return 0;
	}

	GLuint shader=0;
	shader=glCreateShader(type_gl);

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
		const FsChar* vertex_src,FsUint v_size;
		const FsChar* fragmet_src,FsUint f_size;
		)
{
	GLuint program=0;
	GLuint vertex_shader=0;
	GLuint fragment_shader=0;
	FsChar log_info[FS_MAX_GL_PROGRAM_LOG_LENGTH];
	FsInt log_length;
	GLint link_result;
	Program* ret=NULL;

	/* create vertex shader  object */
	vertex_shader=s_create_shader_object(vertex_src,v_size);
	if(vertex_shader==0)
	{
		goto error;
	}

	/* create fragment shader object */
	fragment_shader=s_create_shader_object(fragmet_src,f_size);
	if(fragment_shader==0)
	{
		goto error;
	}

	/* create program object */
	program=glCreateProgram();

	/* attach vertex and fragment shader */
	glAttachShader(program,vertex_shader);
	glAttachShader(program,fragment_shader);

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

	Program* ret=new Program();
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

Program::Program()
{
	m_program=0;
}
Program::~Program()
{
	if(m_program!=0)
	{
		glDeleteProgram(m_program);
	}
}

const FsChar* s_programName="ProgramObject";
const FsChar* Program::getName()
{
	return s_programName;
}

NS_FS_END 

