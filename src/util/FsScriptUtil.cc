#include "util/FsScriptUtil.h"
#include "util/FsArray.h"
#include "util/FsDict.h"
#include "util/FsString.h"
#include "script/xir_parser.h"

FAERIS_NAMESPACE_BEGIN
static bool s_ObjectWrite(FsObject* ob,FsFile* file,FsInt indent);
static void s_IndentWrite(FsFile* file,FsInt indent);
static bool s_ArrayWrite(FsArray* ay,FsFile* file);
static bool s_DictWrite(FsDict* dt,FsFile* file,FsInt indent);
static bool s_StringWrite(FsString* str,FsFile* file);


static bool s_ObjectWrite(FsObject* ob,FsFile* file,FsInt indent)
{
	if(FsString::checkType(ob))
	{
		s_StringWrite((FsString*)ob,file);
	}
	else if(FsDict::checkType(ob))
	{
		s_DictWrite((FsDict*)ob,file,indent);
	}
	else if(FsArray::checkType(ob))
	{
		s_ArrayWrite((FsArray*)ob,file);
	}
	else 
	{
		file->writeStr("%s(%ld)",ob->getName(),(FsLong)ob);
	}
	return true;
}
static void s_IndentWrite(FsFile* file,FsInt indent)
{
	for(FsInt i=0;i<indent;++i)
	{
		file->writeStr("\t");
	}
}
static bool s_ArrayWrite(FsArray* ay,FsFile* file)
{
	FsArray::Iterator iter(ay);
	file->writeStr("[");
	while(!iter.done())
	{
		FsObject* ob=iter.getValue();
		if(ob!=NULL)
		{
			s_ObjectWrite(ob,file,-1);
			ob->decRef();
		}
		file->writeStr(",");
		iter.next();
	}
	file->writeStr("]");
	return true;
}
static bool s_DictWrite(FsDict* dt,FsFile* file,FsInt indent)
{
	FsDict::Iterator iter(dt);
	file->writeStr("{");
	if(indent!=-1)
	{
		file->writeStr("\n");
	}
	while(!iter.done())
	{
		FsObject* key=iter.getKey();
		FsObject* value=iter.getValue();
		if(indent!=-1)
		{
			s_IndentWrite(file,indent+1);
			s_ObjectWrite(key,file,-1);
			file->writeStr(":");
			s_ObjectWrite(value,file,indent+1);
			file->writeStr("\n");
		}
		else 
		{
			s_ObjectWrite(key,file,-1);
			file->writeStr(":");
			s_ObjectWrite(value,file,-1);
			file->writeStr(",");
		}
		key->decRef();
		value->decRef();
		iter.next();
	}
	if(indent!=-1)
	{
		s_IndentWrite(file,indent);
	}
	file->writeStr("}");
	return true;
}

static inline bool s_SpecialChar(char ch)
{
	switch(ch)
	{
		case '{':
		case '}':
		case '[':
		case ']':
		case ':':
		case ',':
		case '\'':
		case '\"':
		case '#':
			return true;
	}
	return false;
}
static inline bool s_EscapeChar(char ch)
{
	switch(ch)
	{
		case '\t':
		case '\n':
		case '\\':
		case '\"':
			return true;
	}
	return false;
}

static bool s_StringWrite(FsString* str,FsFile* file)
{

	bool need_quote=false;
	const FsChar* chs=str->cstr();
	for(FsUint i=0;i<str->length();++i)
	{
		if(s_SpecialChar(chs[i])||s_EscapeChar(chs[i]))
		{
			need_quote=true;
			break;
		}
	}

	if(need_quote)
	{
		file->writeStr("\"");
		for(FsUint i=0;i<str->length();++i)
		{
			switch(chs[i])
			{
				case '\t':
					file->writeStr("\\t");
					break;
				case '\n':
					file->writeStr("\\n");
					break;
				case '\"':
					file->writeStr("\\\"");
					break;
				case '\\':
					file->writeStr("\\");
					break;
				default:
					file->writeStr("%c",chs[i]);
					break;
			}
		}
		file->writeStr("\"");
	}
	else 
	{
		file->writeStr("%s",chs);
	}
	return true;
}

FsDict* ScriptUtil::parseScript(FsFile* file)
{
	return XirParser::parse(file);
}
bool ScriptUtil::saveScript(FsFile* file,FsDict* dict,FsInt indent)
{
	FsDict::Iterator iter(dict);
	while(!iter.done())
	{
		FsObject* key=iter.getKey();
		FsObject* value=iter.getValue();
		if(indent!=-1)
		{
			s_IndentWrite(file,indent);
			s_ObjectWrite(key,file,-1);
			file->writeStr(":");
			s_ObjectWrite(value,file,indent);
			file->writeStr("\n");
		}
		else 
		{
			s_ObjectWrite(key,file,-1);
			file->writeStr(":");
			s_ObjectWrite(value,file,-1);
			file->writeStr(",");
		}
		key->decRef();
		value->decRef();
		iter.next();
	}
	return true;
}	

FAERIS_NAMESPACE_END 

