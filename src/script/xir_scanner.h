#ifndef _FAERY_XIR_SCRIPT_SCANNER_H_
#define _FAERY_XIR_SCRIPT_SCANNER_H_
#include <string>
#include "fsys/FsVFS.h"
#include "xir_file.h"
#include "xir_state.h"
class XirScanner
{
	private:
		XirFile* m_file;
		int m_cur_token;
		int m_cur_line;
		std::string m_cur_string;
		XirState* m_begin_state;
		bool m_eof;
	public:
		XirScanner(Faeris::FsFile* file,XirState* begin_state);
		~XirScanner();
		int nextToken();
		int curToken(){return m_cur_token;}
		int curLine(){return m_cur_line;}
		std::string curString(){return m_cur_string;}
		std::string curTokenName();
};

#endif /*_FAERY_XIR_SCRIPT_SCANNER_H_*/

