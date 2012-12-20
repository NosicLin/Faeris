#include <stdlib.h>
#include <string.h>

#include "FsDict.h"

#define FS_DICT_MIN_SIZE 8
#define FS_DICT_DEFAULT_PERTURB_SHIFT 5
FAERIS_NAMESPACE_BEGIN


static const FsChar* s_FsDict_Name="FsDictObject";
static int s_dummy_int=0; /* only for get an unique address value */
FsObject* s_dict_dummy_entry=(FsObject*)&s_dummy_int;

bool FsDict::checkType(FsObject* ob)
{
	return ob->getName()==s_FsDict_Name;
}

const FsChar* FsDict::getName()
{
	return s_FsDict_Name;
}

FsDict::FsDict()
{
	m_fill=0;
	m_used=0;
	m_mask=FS_DICT_MIN_SIZE-1;
	m_table=(DictEntry*)malloc(sizeof(DictEntry)*FS_DICT_MIN_SIZE);
	memset(m_table,0,sizeof(DictEntry)*FS_DICT_MIN_SIZE);
}
bool FsDict::validEntry(FsDict::DictEntry* entry)
{
	return entry->m_key!=NULL&&entry->m_key!=s_dict_dummy_entry;
}

FsDict::DictEntry* FsDict::lookupEntry(FsObject* key,FsLong code)
{
	FsUlong mask=m_mask;
	FsUlong i=code&mask;
	FsUlong perturb;

	DictEntry* table=m_table;
	DictEntry* p=table+i;
	DictEntry* freeslot=NULL;
	FsInt cmp;
	if(p->m_key==NULL)
	{
		return p;
	}
	if(p->m_key==s_dict_dummy_entry)
	{
		freeslot=p;
	}
	else if(p->m_code==code)
	{
		cmp=key->equal(p->m_key);
		if(cmp)
		{
			return p;
		}
	}
	for(perturb=code;;perturb>>=FS_DICT_DEFAULT_PERTURB_SHIFT)
	{
		i=(i<<2)+i+1+perturb;
		p=table+(i&mask);

		if(p->m_key==NULL) 
		{
			return freeslot==NULL?p:freeslot;
		}

		if(p->m_key==s_dict_dummy_entry)
		{
			if(freeslot==NULL) freeslot=p;
		}
		else if(p->m_code==code)
		{
			FS_ASSERT(p->m_key);
			cmp=key->equal(p->m_key);
			if(cmp)
			{
				return p;
			}
		}
	}
}
void FsDict::simpleInsert(FsObject* key,FsLong code,FsObject* value)
{
	FsUlong mask=m_mask;
	FsUlong i=code&mask;
	FsUlong perturb=code;

	DictEntry* table=m_table;
	DictEntry* p=table+i;

	while(p->m_key!=NULL)
	{
		i=(i<<2)+i+1+perturb;
		perturb>>=FS_DICT_DEFAULT_PERTURB_SHIFT;
		p=table+(i&mask);
	}
	FS_ASSERT(p->m_value==NULL);
	p->m_key=key;
	p->m_value=value;
	p->m_code=code;
	m_fill++;
	m_used++;
}

void FsDict::resize(FsLong minisize)
{
	DictEntry* old_table=0;
	DictEntry* new_table=0;
	DictEntry* p=0;
	FsLong new_size=FS_DICT_MIN_SIZE;
	FsLong i;

	while(new_size<minisize&&new_size>0) new_size<<=1;
	FS_TRACE_ERROR_ON(new_size<0,"Can't Alloc Memory For Resize Hash Object");

	new_table=(DictEntry*)malloc(sizeof(DictEntry)*new_size);
	memset(new_table,0,sizeof(DictEntry)*new_size);

	old_table=m_table;
	m_table=new_table;
	m_mask=new_size-1;
	m_used=0;

	i=m_fill;
	m_fill=0;

	for(p=old_table;i>0;p++)
	{
		if(p->m_key!=NULL)
		{
			i--;
			if(p->m_key!=s_dict_dummy_entry)
			{

				simpleInsert(p->m_key,p->m_code,p->m_value);
			}
		}
	}
	free(old_table);
}
bool FsDict::remove(FsObject* key)
{
	FsLong code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->getName());
		return false;
	}
	DictEntry* p=lookupEntry(key,code);

	if(p->m_key==NULL||p->m_key==s_dict_dummy_entry)
	{
		FS_TRACE_WARN(" %s Key Not Map ",key->getName());
		return false;
	}
	p->m_key->decRef();
	p->m_key=s_dict_dummy_entry;

	p->m_value->decRef();
	p->m_value=NULL;
	m_used--;
	return true;
}




FsObject* FsDict::lookup(FsObject* key)
{
	FsLong code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->getName());
		return NULL ;
	}
	DictEntry* p=lookupEntry(key,code);
	if(p->m_key==NULL||p->m_key==s_dict_dummy_entry)
	{
		return NULL;
	}
	FS_ASSERT(p->m_value);
	p->m_value->addRef();
	return p->m_value;
}

bool FsDict::insert(FsObject* key,FsObject* value)
{
	FsLong code=key->getHashCode();
	if(code==FS_INVALID_HASH_CODE)
	{
		FS_TRACE_WARN("Can't Hash %s Object",key->getName());
		return false;
	}
	FsLong used=m_used;
	DictEntry* p=lookupEntry(key,code);

	key->addRef();
	value->addRef();
	/* key not map before */
	if(p->m_key==NULL)
	{
		m_fill++;
		m_used++;
	}
	else if(p->m_key==s_dict_dummy_entry) /* key is dummy */
	{
		m_used++;
		p->m_key=NULL;
	}
	else  /* key aready map */
	{
		p->m_value->decRef();
		p->m_value=NULL;
	}

	if(p->m_key==NULL)
	{
		p->m_key=key;
	}
	else 
	{
		key->decRef();
	}

	p->m_value=value;
	p->m_code=code;

	/* check space, make sure 1/3 free slot */
	if(used<m_used && (FsUlong)m_fill*3>m_mask*2)
	{
		resize((m_used>50000?2:4)*m_used);
	}
	return true;
}
FsDict::~FsDict()
{
	DictEntry* p;
	FsLong i=m_fill;
	for(p=m_table;i>0;p++)
	{
		if(p->m_key!=NULL)
		{
			i--;
			if(p->m_key!=s_dict_dummy_entry)
			{
				p->m_key->decRef();
				p->m_value->decRef();
			}
		}
	}
	free(m_table);
}







FAERIS_NAMESPACE_END 

