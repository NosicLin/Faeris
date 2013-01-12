#ifndef _FS_SHADER_MATERIAL_H_
#define _FS_SHADER_MATERIAL_H_

#include "FsMacros.h"
#include "material/FsMaterial.h"
#include "core/FsObject.h"
#include "graphics/FsRender.h"


NS_FS_BEGIN
class Render;
class Program;
class FsDict;
class ShaderMaterial:public Material
{
	public:
		class Uniform:public FsObject
		{
			public:
				FsString* m_name;
				FsInt m_type;
				FsInt m_count;
				FsInt m_location;
				FsVoid* m_value;
			public:
				Uniform(FsString* name,FsInt type,FsInt count);
				virtual ~Uniform();

				void setValue(void* value,FsInt type,FsInt count);
				virtual const FsChar* getName();
		};
	public:
		void setShadeMode(FsInt mode){m_shadeMode=mode;}
		void enableWireFrame(FsBool enable){m_wireFrame=enable;}
		void setWireFrameWidth(FsFloat width){m_wireFrameWidth=width;}
		void setProgram(Program* prog);

		void setProgramSourceName(FsString* name);
		FsString* getProgramSourceName();


		void setUniform1i(const FsChar* name,FsInt v)
		{
			setUniform(name,Render::U_I_1,&v,1);
		}
		void setUniform2i(const FsChar* name,FsInt v1,FsInt v2)
		{
			FsInt v[]={v1,v2};
			setUniform(name,Render::U_I_2,v,1);
		}
		void setUniform3i(const FsChar* name,FsInt v1,FsInt v2,FsInt v3)
		{
			FsInt v[]={v1,v2,v3};
			setUniform(name,Render::U_I_3,v,1);
		}
		void setUniform4i(const FsChar* name,FsInt v1,FsInt v2,FsInt v3,FsInt v4)
		{
			FsInt v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_I_4,v,1);
		}

		void setUniform1f(const FsChar* name,FsFloat v)
		{
			setUniform(name,Render::U_F_1,&v,1);
		}
		void setUniform2f(const FsChar* name,FsFloat v1,FsFloat v2)
		{
			FsFloat v[]={v1,v2};
			setUniform(name,Render::U_F_2,v,1);
		}
		void setUniform3f(const FsChar* name,FsFloat v1,FsFloat v2,FsFloat v3)
		{
			FsFloat v[]={v1,v2,v3};
			setUniform(name,Render::U_F_3,v,1);
		}
		void setUniform4f(const FsChar* name,FsFloat v1,FsFloat v2,FsFloat v3,FsFloat v4)
		{
			FsFloat v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_F_4,v,1);
		}

		void setUniform1ui(const FsChar* name,FsUint v)
		{
			setUniform(name,Render::U_UI_1,&v,1);
		}
		void setUniform2ui(const FsChar* name,FsUint v1,FsUint v2)
		{
			FsUint v[]={v1,v2};
			setUniform(name,Render::U_UI_2,v,1);
		}
		void setUniform3ui(const FsChar* name,FsUint v1,FsUint v2,FsUint v3)
		{
			FsUint v[]={v1,v2,v3};
			setUniform(name,Render::U_UI_3,v,1);
		}
		void setUniform4ui(const FsChar* name,FsUint v1,FsUint v2,FsUint v3,FsUint v4)
		{
			FsUint v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_UI_4,v,1);
		}

		void setUniform1iv(const FsChar* name,FsInt count,FsInt* v)
		{
			setUniform(name,Render::U_I_1,v,count);
		}
		void setUniform2iv(const FsChar* name,FsInt count,FsInt* v)
		{
			setUniform(name,Render::U_I_2,v,count);
		}
		void setUniform3iv(const FsChar* name,FsInt count,FsInt* v)
		{
			setUniform(name,Render::U_I_3,v,count);
		}
		void setUniform4iv(const FsChar* name,FsInt count,FsInt* v)
		{
			setUniform(name,Render::U_I_4,v,count);
		}

		void setUniform1fv(const FsChar* name,FsInt count,FsFloat* v)
		{
			setUniform(name,Render::U_F_1,v,count);
		}
		void setUniform2fv(const FsChar* name,FsInt count,FsFloat* v)
		{
			setUniform(name,Render::U_F_2,v,count);
		}
		void setUniform3fv(const FsChar* name,FsInt count,FsFloat* v)
		{
			setUniform(name,Render::U_F_3,v,count);
		}
		void setUniform4fv(const FsChar* name,FsInt count,FsFloat* v)
		{
			setUniform(name,Render::U_F_4,v,count);
		}

		void setUniform1uiv(const FsChar* name,FsInt count,FsUint* v)
		{
			setUniform(name,Render::U_UI_1,v,count);
		}
		void setUniform2uiv(const FsChar* name,FsInt count,FsUint* v)
		{
			setUniform(name,Render::U_UI_2,v,count);
		}
		void setUniform3uiv(const FsChar* name,FsInt count,FsUint* v)
		{
			setUniform(name,Render::U_UI_3,v,count);
		}
		void setUniform4uiv(const FsChar* name,FsInt count,FsUint* v)
		{
			setUniform(name,Render::U_UI_4,v,count);
		}

		void addUniform(const FsChar* name,FsInt type,FsInt count);
		void addUniform(ShaderMaterial::Uniform* u);
		FsDict* getUniforms();
	public:
		ShaderMaterial();
		virtual ~ShaderMaterial();
		virtual const FsChar* getName();
		virtual void load(Render* r);
		virtual void unload(Render* r);
	protected:
		void setUniform(const FsChar* name,FsInt type,FsVoid* value,FsInt count);
		void refreshUniform();
		void configRender(Render* r);

	private:
		FsBool m_wireFrame;
		FsFloat m_wireFrameWidth;
		Program* m_program;
		FsString* m_programSourceName;
		FsDict* m_uniforms;
};
NS_FS_END
#endif /*_FS_SHADER_MATERIAL_H_*/

