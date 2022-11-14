#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
  char *src_str = (char *)src;
  char *dest_str = (char *)dest;

  for(size_t index = 0; index < n; index += 1)
    dest_str[index] = src_str[index];
}