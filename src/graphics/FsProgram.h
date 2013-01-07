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
	public:

		class Uniform:public FsObject
	{
		public:
			FsString* name;
			FsInt type;
			FsInt count;
			FsInt location;
			FsInt used;
		public:
			Uniform(FsString* _name,FsInt _type,FsInt _count)
			{
				name=_name;
				name->addRef();
				type=_type;
				count=_count;
				used=true;
				location=-1;
			}
			virtual ~Uniform();
		public:
			virtual const FsChar* getName();
	};
		class Attribute:public FsObject
	{
		public:
			FsString* name;
			FsInt location;
			FsInt used;
		public:
			Attribute(FsString* _name,FsInt _type)
			{
				name=_name;
				name->addRef();

				used=true;
				location=-1;
			}

			virtual ~Attribute();
			virtual const FsChar* getName();

	};
	public:
	public:
		static Program* create(
				const FsChar* vertex_src,FsUint v_size,
				const FsChar* fragment_src,FsUint f_size);
	public:

		void addAttribute(const FsChar* name,FsInt type);
		void addUniform(const FsChar* name,FsInt type,FsInt count);

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

