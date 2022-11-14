#include <criterion/criterion.h>

#include "../strcmp/my_strcmp.h"
#include "my_strdup.h"

Test(my_strdup, strdup_with_null_string)
{
  char *str = NULL;

  cr_assert_null(my_strdup(str));
}

Test(my_strdup, strdup_with_non_null_string)
{
  char *str = "NULL";
  char *dup = my_strdup(str);

  cr_assert_eq(0, my_strcmp(str, dup));

  free(dup);
}
