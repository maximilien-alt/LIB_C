#include <criterion/criterion.h>

#include "my_memset.h"

Test(my_memset, basic_memset)
{
  char *str = malloc(sizeof(char) * 10);

  my_memset(str, 'a', 10);
  for(size_t index = 0; index < 10; index += 1)
    if (str[index] != 'a')
      cr_assert(false);
  cr_assert(true);

  free(str);
}

