#ifndef _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#define _FAERY_XIR_SCRIPT_XIR_PARSE_H_
#include <vector>

#include "fsys/FsFile.h"
#include "xir_scanner.h"
#include "util/FsDict.h"

class XirParser
{
	public:
		static XirAstNode* parse(Faeris::FsFile* file);
};
class YYParserParm
{
	public:
		XirScanner* m_lex;
		FsDict* m_root;
		bool m_delimiter;
		std::vector<FsObject*> m_pending_obs;
	public:
		YYParserParm(XirScanner* lex)
		{
			m_lex=lex;
			m_root=NULL;
			m_delimiter=false;
		}
		void releasePendingNode()
		{
			std::vector iter;
			for(iter=m_pending_obs.begin();iter!=m_pending_obs.end();++iter)
			{
				iter->release();
			}
			m_pending_obs.clear();
		}
		FsString* newStringObject()
		{
			FsString* ob=new FsString(m_lex->curString());
			m_pending_node.push_back(ob);
			return ob;
		}
		FsDict* newDictObject()
		{
			FsDict* ob=new FsDict();
			m_pending_obs.push_back(ob);
			return ob;
		}

		FsArray* newArrayObject(int type)
		{
			FsArray* ob=new FsArray;
			m_pending_obs.push_back(ob);
			return ob;
		}

		void setRoot(FsDict* root)
		{
			if(root) root->addRef();
			if(m_root) { m_root->release(); }
			m_root=root;
		}
		FsDict* getRoot()
		{
			if(m_root)
			{
				m_root->addRef();
			}
			return m_root;
		}
		~YYParserParm()
		{
			if(m_root) m_root->release();
			releasePendingNode();
		}
};
#define YACC_SHIFT_BASE  258

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm

int yylex(void* lvap,void* parm);
int yyparse(void* parm);
void xir_parse_err(const char* ,void* YYPARSE_PARAM);

#define yyerror(msg)  xir_parse_err(msg,YYPARSE_PARAM)

#endif 

