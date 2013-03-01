#ifndef _FS_PARCEL_H_
#define _FS_PARCEL_H_ 

/* compress method */
enum 
{
	COMPRESS_UNKOWN,
	COMPRESS_DEFLATE,
	COMPRESS_NONE,
};
class Parcel:public FsObject
{
	public:
		static Parcel* create(const char* filename,int method=COMPRESS_UNKOWN);
		static Parcel* create(FsFile* file,int method=COMPRESS_UNKOWN);
	public:
		virtual FsFile* getBlock(const char* name)=0;
		virtual ~Parcel(){}
};


class ParcelPacker 
{
	public:
		void add(FsFile* file,const char* name);
		void clear();
		int pack(FsFile* file);
		int pack(const char* filename);
};


#endif /*_FS_PARCEL_H_ */




