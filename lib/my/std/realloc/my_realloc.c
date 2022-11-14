#include "../memcpy/my_memcpy.h"
#include "my_realloc.h"

void *my_realloc(void *src, size_t old_size, size_t new_size)
{
  void *new_ptr = malloc(new_size);

  if (!src)
    return new_ptr;
  my_memcpy(new_ptr, src, old_size);
  free(src);
  return new_ptr;
}
