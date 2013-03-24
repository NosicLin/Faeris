#ifndef _FS_SLOW_ARRAY_H_
#define _FS_SLOW_ARRAY_H_

#include "FsMacros.h"
#include "util/FsArray.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class FsSlowArray:public FsObject
{
	public:
		static FsSlowArray* create();

	public:
		virtual const char* className() ;

	public:
		void lock();
		void unlock();
		void flush();
		void push(FsObject* object);
		void remove(FsObject* object);
		FsObject* get(ulong index);
		int size();

	protected:
		FsSlowArray();
		virtual ~FsSlowArray();
		void init();
		void destroy();

	private:
		bool m_lock;
		FsArray* m_items;
		FsArray* m_deletes;
		FsArray* m_adds;
};
NS_FS_END

#endif /*_FS_SLOW_ARRAY_H_*/


