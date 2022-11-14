#include "my_strlen.h"

size_t my_strlen(char *str)
{
  size_t index = 0;

  if (!str)
    return 0;
  for(; str[index]; index += 1);
  return index;
}
