#include "my_strcmp.h"

int my_strcmp(char *s1, char *s2)
{
  size_t index = 0;

  for(; s1[index] && s2[index]; index += 1)
    if (s1[index] != s2[index])
      break;
  return (int)(s1[index] - s2[index]);
}
