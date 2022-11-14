#include "my_atoi.h"

int my_atoi(char *nptr)
{
  int result = 0;
  size_t index = 0;
  size_t number_of_subs = 0;

  if (!nptr)
    return 0;
  for(; nptr[index] == '+' || nptr[index] =='-' ; index += 1)
    number_of_subs += (nptr[index] == '-') ? 1 : 0;
  for(; nptr[index]; index += 1)
  {
    if (INT_MAX / 10 < result)
      return 0;
    result *= 10;
    result += nptr[index] - '0';
  }
  if (number_of_subs % 2)
    result *= -1;
  return result;
}
