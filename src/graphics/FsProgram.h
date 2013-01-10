#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include "FsMacros.h"
#include "fsys/FsFile.h"
#include "FsConfig.h"
#include "core/FsObject.h"
#include "util/FsResource.h"
#include "util/FsDict.h"
#include "util/FsString.h"

#if FS_CONFIG(FS_GL_RENDER)
	typedef FsUint PlatformProgram;
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
			FsInt location;
			FsInt used;
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
			virtual const FsChar* getName();
	};
	public:
		static Program* create(
				const FsChar* vertex_src,FsUint v_size,
				const FsChar* fragment_src,FsUint f_size);
	public:

		void addAttribute(const FsChar* name);
		void addUniform(const FsChar* name);

		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */
		FsInt getAttributeLocation(const FsChar* name);
		FsInt getAttributeLocation(FsString* name);
		FsInt getUniformLocation(const FsChar* name);
		FsInt getUniformLocation(FsString* name);

		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const FsChar* getName();
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

