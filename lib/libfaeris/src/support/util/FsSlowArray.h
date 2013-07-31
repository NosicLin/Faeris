#ifndef _FS_SLOW_ARRAY_H_
#define _FS_SLOW_ARRAY_H_

#include <vector>

#include "FsMacros.h"
#include "util/FsArray.h"
#include "FsObject.h"

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
		void pop();
		void remove(FsObject* object);
		void set(int pos,FsObject* object);
		void insert(int pos,FsObject* object);
		FsObject* get(ulong index);
		FsObject* top();
		int size();
		

	protected:
		FsSlowArray();
		virtual ~FsSlowArray();
		void init();
		void destroy();


	private:
		enum
		{
			CM_POP,
			CM_PUSH,
			CM_REMOVE,
			CM_SET,
			CM_INSERT,
		};

		class PendingCommand
		{
			public:
				PendingCommand(int type,int pos,FsObject* ob)
				{
					m_type=type;
					m_pos=pos;
					m_object=ob;
				}
			public:
				int m_type;
				int m_pos;
				FsObject* m_object;
		};


	private:
		bool m_lock;
		FsArray* m_items;
		std::vector<PendingCommand*> m_pendingCommand;
};
NS_FS_END

#endif /*_FS_SLOW_ARRAY_H_*/

















