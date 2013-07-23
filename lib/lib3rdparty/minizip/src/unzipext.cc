#include "unzipext.h"

extern uint32_t ZEXPORT unzextGetFileOffset (unzFile file)
	unzFile file;
{
	unzOpenCurrentFile3(file);
	uint32_t offset=file->pfile_in_zip_read->pos_in_zipfile+
					file->pfile_in_zip_read->byte_before_the_zipfile;

	
	unzCloseCurrentFile();
	return offset;
}




