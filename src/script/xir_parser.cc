#include <stdio.h>
#include "xir_token.h"
#include "sl_state.h"

#include "xir_parser.h"
#define YYACCEPT 0

int yylex(void* lvap,void* parm)
{
	YYParserParm* pm=(YYParserParm*)parm;
	XirScanner* l=pm->m_lex;
	int token;
	while(1)
	{
		token=l->nextToken();
		if(token==XT_COMMENT)
		{
			token=XT_NEWLINE;
		}
		else if(token==XT_WS)
		{
			continue;
		}
		else if(token==XT_EOF)
		{
			return EOF;
		}
		if(token==XT_NEWLINE||token==XT_COMMA)
		{
			if(pm->m_delimiter)
			{
				continue;
			}
			pm->m_delimiter=true;
		}
		else
		{
			pm->m_delimiter=false;
		}
		break;
	}

	return token+YACC_SHIFT_BASE;
}
void xir_parse_err(const char* msg,void* parm)
{
	YYParserParm* pm=(YYParserParm*)parm;
	XirScanner* l=pm->m_lex;
	
	int line=l->curLine();
	printf("yyerror:At Line(%d)\n",line);

}

FsDict* XirParser::parse(Faeris::FsFile* file)
{
	XirScanner* lex=new XirScanner(file,&Xir_Top);
	YYParserParm* parm=new YYParserParm(lex);
	int ret=yyparse(parm);
	if(ret!=YYACCEPT)
	{
		delete lex;
		delete parm;
		return NULL;
	}

	delete lex;
	FsDict* root=parm->getRoot();
	FS_TRACE_ERROR_ON(ast==NULL,"Some Error Must Happened In xir_grammy.y");
	delete parm;
	return root;
}
