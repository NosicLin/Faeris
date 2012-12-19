#ifndef _FS_UTIL_DICT_H_
#define _FS_UTIL_DICT_H_

#include "FsMacros.h"
#include "core/FsObject.h"

FAERIS_NAMESPACE_BEGIN
class  FsDict:public FsObject
{
	public:
		class Iterator
		{
			public:
				FsObject* getkey();
				FsObject* getValue();
				bool done();
				bool next();
			private:
				FsDict* m_dict;
		};
		class DictEntry
		{
			public:
				FsLong m_code;
				FsObject* m_key;
				FsObject* m_value;
			public:
		};

	public:
		FsDict();
		~FsDict();
		virtual const FsChar* getName();
	public:
		FsObject* lookup(FsObject* key);
		bool insert(FsObject* key,FsObject* value);
		bool insertWithNewKey(FsObject* key,FsObject* value);
		bool remove(FsObject* key);
		Iterator* getIterator();
		FsUlong size(){return m_used;}
	protected:
		DictEntry* getEntry(FsObject* key);
		DictEntry* lookupEntry(FsObject* key,FsLong code);
		void resize(FsLong minisize);
		void simpleInsert(FsObject* key,FsLong hcode,FsObject* value);
	private:
		FsLong m_fill;
		FsLong m_used;
		FsUlong m_mask;
		DictEntry* m_table;
};
FAERIS_NAMESPACE_END 

#endif /*_FS_UTIL_DICT_H_*/

