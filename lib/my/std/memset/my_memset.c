#include "my_memset.h"

void my_memset(void *ptr, char c, size_t size)
{
  char *ptr_str = (char *)ptr;

  for(size_t index = 0; index < size; index += 1)
    ptr_str[index] = c;
}
