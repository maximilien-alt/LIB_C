#include "../strlen/my_strlen.h"
#include "my_strdup.h"

char *my_strdup(char *src)
{
  size_t malloc_size = my_strlen(src);
  char *result = NULL;

  if (!malloc_size)
    return NULL;
  result = malloc(malloc_size + 1);
  for (size_t index = 0; src[index]; index += 1)
    result[index] = src[index];
  result[malloc_size] = 0;
  return result;
}
