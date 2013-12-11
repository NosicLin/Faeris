#ifndef _FS_OBJECT_MGR_H_
#define _FS_OBJECT_MGR_H_ 

#include <set>
#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN

class ObjectMgr:public FsObject
{
	public:
		class KeyCompare
		{
			public:
				bool operator()(FsObject* l,FsObject* r) const 
				{
					return l<r;
				}
		};

		typedef std::set<FsObject*,KeyCompare> MgrSet;

	public:
		static ObjectMgr* create();

	public:
		const char* className();

	public:
		void manageObject(FsObject* ob);
		void unManageObject(FsObject* ob);

		void dropObjectData();
		void unManageAllObject();

		int getManageObjectNu();

	protected:
		ObjectMgr(); 
		virtual ~ObjectMgr();

		bool init();
		void destory();

	private:
		MgrSet m_mgr;
};

NS_FS_END

#endif /*_FS_OBJECT_MGR_H_*/

