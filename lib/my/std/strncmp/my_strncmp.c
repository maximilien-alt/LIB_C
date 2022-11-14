#include "my_strncmp.h"

int my_strncmp(char *s1, char *s2, size_t size)
{
  size_t index = 0;

  size -= 1;
  for(; s1[index] && s2[index] && index < size; index += 1)
    if (s1[index] != s2[index])
      break;
  return (int)(s1[index] - s2[index]);
}
