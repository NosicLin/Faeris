#ifndef _FS_UTIL_ARRAY_H_
#define _FS_UTIL_ARRAY_H_ 

#include "FsMacros.h"
#include "core/FsObject.h"

FAERIS_NAMESPACE_BEGIN
class FsArray:public FsObject
{
	public:
		class Iterator
		{
			FS_FEATURE:
				FS_MAKE_NO_COPYABLE(Iterator);
			public:
				bool done()
				{
					return m_curPos>=m_host->m_size;
				}
				bool next()
				{
					return ++m_curPos>=m_host->m_size;
				}
				FsObject* getValue()
				{
					FsObject* ret=m_host->m_obs[m_curPos];
					if(ret) ret->addRef();
					return ret;
				}
				Iterator(FsArray* ay)
				{
					m_host=ay;
					m_host->addRef();
					m_curPos=0;
				}
				~Iterator()
				{
					m_host->decRef();
				}

			private:
				FsArray* m_host;
				FsUlong m_curPos;
		};
	public:
		void push(FsObject* item);
		void pop();

		bool set(FsUlong index,FsObject*  item);
		FsObject* get(FsUlong index);
		bool insert(FsUlong index,FsObject* item);
		bool remove(FsUlong index);
		void resize(FsUlong new_size);
		FsUlong size() { return m_size; }
	public:
		FsArray();
		FsArray(FsUlong size);
		virtual ~FsArray();
		virtual const FsChar* getName();
		static bool checkType(FsObject* ob);

	protected:
		void enlarge(FsUlong new_size);
	private:
		FsUlong m_size;
		FsUlong m_cap;
		FsObject** m_obs;

};

FAERIS_NAMESPACE_END 
#endif /*_FS_UTIL_ARRAY_H_*/

