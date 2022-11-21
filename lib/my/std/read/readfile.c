#include "readfile.h"

char *readfile(const char *path)
{
  int fd = open(path, O_RDONLY);
  char *buffer = NULL;
  struct stat st;

  if (fd <= 0)
    return NULL;
  stat(path, &st);
  buffer = malloc(sizeof(char) * st.st_size + 1);
  if (read(fd, buffer, st.st_size) <= 0)
  {
    free(buffer);
    return NULL;
  }
  close (fd);
  buffer[st.st_size] = 0;
  return buffer;
}
