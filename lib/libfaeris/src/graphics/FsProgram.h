#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include "FsMacros.h"
#include "sys/io/FsFile.h"
#include "FsConfig.h"
#include "FsObject.h"
#include "mgr/FsResource.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"

#if FS_CONFIG(FS_GL_RENDER) ||FS_CONFIG(FS_GLES_RENDER)
	typedef uint PlatformProgram;
#else 
	#error "Unsupport PlatformProgram"
#endif 

NS_FS_BEGIN 

class Program:public Resource
{
	public:
		static Program* create(
				const char* vertex_src,uint v_size,
				const char* fragment_src,uint f_size);

	public:
		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */
		int getAttributeLocation(const char* name);
		int getUniformLocation(const char* name);

		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const char* className();
	protected:
		Program();
		~Program();
	private:
		PlatformProgram m_program;
};
NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/

