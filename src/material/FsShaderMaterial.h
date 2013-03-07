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
				int m_type;
				int m_count;
				int m_location;
				void* m_value;
			public:
				Uniform(FsString* name,int type,int count);
				virtual ~Uniform();

				void setValue(void* value,int type,int count);
				virtual const char* getName();
		};
	public:
		void setShadeMode(int mode){m_shadeMode=mode;}
		void enableWireFrame(bool enable){m_wireFrame=enable;}
		void setWireFrameWidth(float width){m_wireFrameWidth=width;}
		void setProgram(Program* prog);

		void setProgramSourceName(FsString* name);
		FsString* getProgramSourceName();


		void setUniform1i(const char* name,int v)
		{
			setUniform(name,Render::U_I_1,&v,1);
		}
		void setUniform2i(const char* name,int v1,int v2)
		{
			int v[]={v1,v2};
			setUniform(name,Render::U_I_2,v,1);
		}
		void setUniform3i(const char* name,int v1,int v2,int v3)
		{
			int v[]={v1,v2,v3};
			setUniform(name,Render::U_I_3,v,1);
		}
		void setUniform4i(const char* name,int v1,int v2,int v3,int v4)
		{
			int v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_I_4,v,1);
		}

		void setUniform1f(const char* name,float v)
		{
			setUniform(name,Render::U_F_1,&v,1);
		}
		void setUniform2f(const char* name,float v1,float v2)
		{
			float v[]={v1,v2};
			setUniform(name,Render::U_F_2,v,1);
		}
		void setUniform3f(const char* name,float v1,float v2,float v3)
		{
			float v[]={v1,v2,v3};
			setUniform(name,Render::U_F_3,v,1);
		}
		void setUniform4f(const char* name,float v1,float v2,float v3,float v4)
		{
			float v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_F_4,v,1);
		}

		void setUniform1ui(const char* name,uint v)
		{
			setUniform(name,Render::U_UI_1,&v,1);
		}
		void setUniform2ui(const char* name,uint v1,uint v2)
		{
			uint v[]={v1,v2};
			setUniform(name,Render::U_UI_2,v,1);
		}
		void setUniform3ui(const char* name,uint v1,uint v2,uint v3)
		{
			uint v[]={v1,v2,v3};
			setUniform(name,Render::U_UI_3,v,1);
		}
		void setUniform4ui(const char* name,uint v1,uint v2,uint v3,uint v4)
		{
			uint v[]={v1,v2,v3,v4};
			setUniform(name,Render::U_UI_4,v,1);
		}

		void setUniform1iv(const char* name,int count,int* v)
		{
			setUniform(name,Render::U_I_1,v,count);
		}
		void setUniform2iv(const char* name,int count,int* v)
		{
			setUniform(name,Render::U_I_2,v,count);
		}
		void setUniform3iv(const char* name,int count,int* v)
		{
			setUniform(name,Render::U_I_3,v,count);
		}
		void setUniform4iv(const char* name,int count,int* v)
		{
			setUniform(name,Render::U_I_4,v,count);
		}

		void setUniform1fv(const char* name,int count,float* v)
		{
			setUniform(name,Render::U_F_1,v,count);
		}
		void setUniform2fv(const char* name,int count,float* v)
		{
			setUniform(name,Render::U_F_2,v,count);
		}
		void setUniform3fv(const char* name,int count,float* v)
		{
			setUniform(name,Render::U_F_3,v,count);
		}
		void setUniform4fv(const char* name,int count,float* v)
		{
			setUniform(name,Render::U_F_4,v,count);
		}

		void setUniform1uiv(const char* name,int count,uint* v)
		{
			setUniform(name,Render::U_UI_1,v,count);
		}
		void setUniform2uiv(const char* name,int count,uint* v)
		{
			setUniform(name,Render::U_UI_2,v,count);
		}
		void setUniform3uiv(const char* name,int count,uint* v)
		{
			setUniform(name,Render::U_UI_3,v,count);
		}
		void setUniform4uiv(const char* name,int count,uint* v)
		{
			setUniform(name,Render::U_UI_4,v,count);
		}

		void addUniform(const char* name,int type,int count);
		void addUniform(ShaderMaterial::Uniform* u);
		FsDict* getUniforms();
	public:
		ShaderMaterial();
		virtual ~ShaderMaterial();
		virtual const char* getName();
		virtual void load(Render* r);
		virtual void unload(Render* r);
	protected:
		void setUniform(const char* name,int type,void* value,int count);
		void refreshUniform();
		void configRender(Render* r);

	private:
		bool m_wireFrame;
		float m_wireFrameWidth;
		Program* m_program;
		FsString* m_programSourceName;
		FsDict* m_uniforms;
};
NS_FS_END
#endif /*_FS_SHADER_MATERIAL_H_*/

