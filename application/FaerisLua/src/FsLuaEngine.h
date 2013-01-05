#ifndef _FS_LUA_ENGINE_H_
#define _FS_LUA_ENGINE_H_


struct lua_State;

typedef int (*CFunction)(struct lua_State*);
class LuaEngine
{
	public:
		static LuaEngine* shareEngine();
		static void purgeShareEngine();


	public:
		int executeFile(const char* file);
		int executeString(const char* str);

		/* push value */
		void pushInteger(int value);
		void pushNumber(double value);
		void pushString(const char* str);
		void pushUserType(void* value,const char* type);
		void pushCFunction(CFunction func);

		void setGlobalCFunction(const char* name,CFunction func);
		void setGlobalUserType(const char* name,void* data,const char* type);

		/* ref function */
		void removeRefFunction(int refid);
		void pushRefFunction(int refid);

		/* call function */
		void call(int argnu,int retnu);

		void cleanStack();

		struct lua_State* getLuaState(){return m_state;}

	public:
		LuaEngine();
		~LuaEngine();

	private:
		struct lua_State* m_state;

};


#endif /*_FS_LUA_ENGINE_H_*/
