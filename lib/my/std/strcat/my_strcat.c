#include "../strlen/my_strlen.h"
#include "../memcpy/my_memcpy.h"
#include "my_strcat.h"

char *my_strcat(char *first, char *second)
{
  char *result = NULL;
  size_t second_len = 0;
  size_t first_len = 0;
  size_t total_len = 0;

  if (!first)
    return second;
  if (!second)
    return first;

  first_len = my_strlen(first);
  second_len = my_strlen(second);
  total_len = first_len + second_len;
  result = malloc(sizeof(char) * (total_len + 1));
  my_memcpy(result, first, first_len);
  my_memcpy(&result[first_len], second, second_len);
  result[total_len] = 0;
  return result;
}
