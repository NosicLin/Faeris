#include <string.h>
#include <stdlib.h>

#include "util/FsScriptUtil.h"
#include "util/FsArray.h"
#include "util/FsDict.h"
#include "util/FsString.h"
#include "script/xir_parser.h"

NS_FS_BEGIN
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
		/* Specifal char */
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

		/* reverse */
		case '$':
		case '%':
		case '&':
		case '(':
		case ')':
		case '*':
		case '/':
		case ';':
		case '<':
		case '=':
		case '>':
		case '?':
		case '@':
		case '^':
		case '`':
		case '|':
		case '~':
			return true;



	}
	return false;
}
static inline bool s_EscapeChar(FsChar ch)
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

static inline FsChar  s_EscapeCharToOrign(FsChar ch)
{
	switch(ch)
	{
		case 't':
			return '\t';
		case 'n':
			return '\n';
		case '\\':
			return '\\';
		case '\"':
			return '\"';
	}
	return ch;
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

FsChar* ScriptUtil::escapeStringToOrign(const FsChar* src)
{
	FsChar* buffer=NULL;
	FsLong src_len=0;
	FsLong dst_len=0;

	if(src[0]!='\''&&src[0]!='\"')
	{
		return NULL;
	}

	src_len=strlen(src);

	FS_TRACE_ERROR_ON(src_len<2,"Some Error Must Happen");

	buffer=new FsChar[src_len+1];

	FsLong i=1;
	while(i<src_len-1)
	{
		if(src[i]=='\\')
		{
			i++;
			buffer[dst_len++]=s_EscapeCharToOrign(src[i]);
		}
		else 
		{
			buffer[dst_len++]=src[i];
		}
		i++;
	}
	buffer[dst_len]='\0';
	return buffer;
}


FsArray* ScriptUtil::getArray(FsDict* dict,const FsChar* key)
{
	FsObject* ob=dict->lookup(key);
	if(ob==NULL)
	{
		return NULL;
	}

	if(FsArray::checkType(ob))
	{
		return (FsArray*)ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}

FsDict* ScriptUtil::getDict(FsDict* dict,const FsChar* key)
{
	FsObject* ob=dict->lookup(key);
	if(ob==NULL)
	{
		return NULL;
	}

	if(FsDict::checkType(ob))
	{
		return (FsDict*)ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}
FsString* ScriptUtil::getString(FsDict* dict,const FsChar* key)
{
	FsObject* ob=dict->lookup(key);
	if(ob==NULL)
	{
		return NULL;
	}

	if(FsString::checkType(ob))
	{
		return (FsString*)ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}

FsBool ScriptUtil::getInteger(FsDict* dict,const FsChar* key,FsInt* value)
{
	FsString* str=getString(dict,key);
	if(str==NULL)
	{
		return false;
	}
	*value=parseInteger(str);
	str->decRef();
	return true;

}

FsBool ScriptUtil::getFloat(FsDict* dict,const FsChar* key,FsFloat* value)
{
	FsString* str=getString(dict,key);
	if(str==NULL)
	{
		return false;
	}
	*value=parseFloat(str);
	str->decRef();
	return true;
}
/* aux for quick get object in array */
FsArray* ScriptUtil::getArray(FsArray* array,FsUint index)
{
	FsObject* ob=array->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsArray::checkType(ob))
	{
		return (FsArray*) ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}


FsDict* ScriptUtil::getDict(FsArray* array,FsUint index)
{
	FsObject* ob=array->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsDict::checkType(ob))
	{
		return (FsDict*) ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}

FsString* ScriptUtil::getString(FsArray* array,FsUint index)
{
	FsObject* ob=array->get(index);
	if(ob==NULL)
	{
		return NULL;
	}
	if(FsString::checkType(ob))
	{
		return (FsString*) ob;
	}
	else 
	{
		ob->decRef();
		return NULL;
	}
}

FsBool ScriptUtil::getInteger(FsArray* array,FsUint index,FsInt* v)
{
	FsString* str=ScriptUtil::getString(array,index);
	if(str==NULL)
	{
		return false;
	}

	*v=parseInteger(str);
	str->decRef();
	return true;
}
FsBool ScriptUtil::getFloat(FsArray* array,FsUint index,FsFloat* v)
{
	FsString* str=ScriptUtil::getString(array,index);
	if(str==NULL)
	{
		return false ;
	}
	*v=parseFloat(str);
	str->decRef();
	return true;
}
	


FsFloat ScriptUtil::parseFloat(const FsChar* str)
{
	return atof(str);
}
FsInt ScriptUtil::parseInteger(const FsChar* str)
{
	return atoi(str);
}




NS_FS_END 



































