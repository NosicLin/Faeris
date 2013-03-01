#ifndef _FS_BASE_64_H_
#define _FS_BASE_64_H_ 
#include "FsMacros.h"

/* Note:
 * 	decode/encode  base64  from memory 
 * 	when success return 0,else return -1
 */

int FsBase64_Decode(FsUint8* src_buf,FsUint src_length,FsUint8** dst_buf,FsUint* dst_length);


/* Note:
 * 	dst_buf will be end with '/0', buf dst_length is only the not include '/0' 
 */

int FsBase64_Encode(FsUint8* src_buf,FsUint src_length,FsUint8** dst_buf,FsUint* dst_length);

#endif /*_FS_BASE_64_H_*/


