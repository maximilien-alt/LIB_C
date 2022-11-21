#ifndef REAFILE_H_
#define REAFILE_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *readfile(const char *path);

#endif /* REAFILE_H_ */