#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include "FsMacros.h"
#include "io/FsFile.h"
#include "FsConfig.h"
#include "core/FsObject.h"
#include "mgr/FsResource.h"
#include "util/FsDict.h"
#include "util/FsString.h"

#if FS_CONFIG(FS_GL_RENDER)
	typedef uint PlatformProgram;
#else 
	#error "Unsupport PlatformProgram"
#endif 

NS_FS_BEGIN 

class Program:public Resource
{
	private:

		class Location:public FsObject
	{
		public:
			FsString* name;
			int location;
			int used;
		public:
			Location(FsString* _name)
			{
				name=_name;
				name->addRef();
				used=true;
				location=-1;
			}
			virtual ~Location();
		public:
			virtual const char* className();
	};
	public:
		static Program* create(
				const char* vertex_src,uint v_size,
				const char* fragment_src,uint f_size);
	public:

		void addAttribute(const char* name);
		void addUniform(const char* name);

		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */
		int getAttributeLocation(const char* name);
		int getAttributeLocation(FsString* name);
		int getUniformLocation(const char* name);
		int getUniformLocation(FsString* name);

		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const char* className();
	protected:
		Program();
		~Program();
	private:
		FsDict* m_uniforms;
		FsDict* m_attrs;
		PlatformProgram m_program;
};
NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/

