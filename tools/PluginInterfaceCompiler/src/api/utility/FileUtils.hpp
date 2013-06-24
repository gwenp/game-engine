#ifndef DEF_FILEUTILS
#define DEF_FILEUTILS

#include <sys/stat.h>

bool is_file(const char* path) {
	struct stat buf;
	stat(path, &buf);
	return S_ISREG(buf.st_mode);
}

bool is_dir(const char* path) {
	struct stat buf;
	stat(path, &buf);
	return S_ISDIR(buf.st_mode);
}

#endif /* DEF_FILEUTILS */
