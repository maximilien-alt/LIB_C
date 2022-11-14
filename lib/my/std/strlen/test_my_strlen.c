#include <criterion/criterion.h>

#include "my_strlen.h"

Test(my_strlen, strlen_with_null_string)
{
  char *str = NULL;

  cr_assert_eq(0, my_strlen(str));
}

Test(my_strlen, strlen_with_non_null_string)
{
  char *str = "NULL";

  cr_assert_eq(4, my_strlen(str));
}
