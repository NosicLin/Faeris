#ifndef _FAERY_MEM_FILE_H_
#define _FAERY_MEM_FILE_H_

#include"FsIFile.h"

FAERY_NAMESPACE_BEGIN
class FsMemFile:public FsIFile
{
	public:
		FsMemFile(const void* mem,ulong len);
		FsMemFile();
	public:
		virtual long read(void* buf,long len);
		virtual long write(const void* buf,long len);
		virtual long seek(long offset,int where);
		virtual long tell();
		virtual int close();
		virtual ~FsMemFile();
	public:
		int save(const char* name);
	protected:
		void ensureMore(uint len);
	private:
		char* m_mem;
		ulong m_length;
		ulong m_cap;
		ulong m_pos;
};

FAERY_NAMESPACE_END

#endif /*_FAERY_MEM_FILE_H_*/

