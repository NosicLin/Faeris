#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include "FsMacros.h"
#include "fsys/FsFile.h"
#include "FsConfig.h"
#include "core/FsObject.h"
#include "graphics/FsShader.h"
#include "util/FsResource.h"
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
		public:
			Uniform(FsString* _name,FsInt _type,FsInt _count)
			{
				name=_name;
				name->addRef();
				type=_type;
				count=_count;
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
		public:
			Attribute(FsString* _name,FsInt _type)
			{
				name=_name;
				name->addRef();
				type=_type;
				location=-1;
			}

			virtual ~Attribute();
			virtual const FsChar* getName();

	};
	public:
		enum 
		{
			/* float vec2 vec3 vec4 */
			U_F_1=0,
			U_F_2,
			U_F_3,
			U_F_4,

			/* int ivec2 ivec3 ivec4 */
			U_I_1,
			U_I_2,
			U_I_3,
			U_I_4,

			/* bool bvec2 bvec3 bvec4 */
			U_B_1,
			U_B_2,
			U_B_3,
			U_B_4,

			/* mat2 mat3 mat4 */
			U_M_2,
			U_M_3,
			U_M_4,

			/* sampler */
			U_S_1D,         /* sampler1D,sampler2D,sampler3D */
			U_S_2D,
			U_S_3D,
			U_S_CUBE,       /* samplerCube */
			U_S_1D_SHADOW,  /* sampler1DShadow, sampler2DShadow */
			U_S_2D_SHADOW,

			U_MAX_NU,
		};
	public:
		static Program* create(
				const FsChar* vertex_src,FsUint v_size,
				const FsChar* fragment_src,FsUint f_size);
	public:
		void addAttribute(const FsChar* name,FsInt type);
		void addUniform(const FsChar* name,FsInt type,FsInt count);

		FsInt getAttributeLocation(const FsChar* name);
		FsInt getUniformLocation(const FsChar* name);

		void setUniform(FsInt loc,FsInt type,void* value);
		void setUniforms(FsInt loc,FsInt type,void* value,FsUint num);
		void setUniform(FsChar* name,void* value);
		void setUniforms(FsChar* name,void* value,FsUint num);

		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const FsChar* getName();
	protected:
		Program();
		~Program();
	private:
		FsBool m_active;
		FsDict* m_uniforms;
		FsDict* m_attrs;
		PlatformProgram m_program;
};
NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/

