#include <criterion/criterion.h>

#include "my_strcat.h"

Test(my_strcat, strcat_with_first_null)
{
  char *str = my_strcat(NULL, "second");

  cr_assert_eq(str, "second");
}

Test(my_strcat, strcat_with_second_null)
{
  char *str = my_strcat("first", NULL);

  cr_assert_eq(str, "first");
}

Test(my_strcat, basic_strcat)
{
  char *str = my_strcat("first", "second");

  cr_assert_eq(0, strcmp("firstsecond", str));
}
