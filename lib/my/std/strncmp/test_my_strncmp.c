#include <criterion/criterion.h>

#include "my_strncmp.h"

Test(my_strncmp, strncmp_not_matching_first_letter)
{
  cr_assert_eq(my_strncmp("first", "second", 13), 'f'-'s');
}

Test(my_strncmp, strncmp_with_substr_false)
{
  cr_assert_eq(my_strncmp("stringstring", "string", 13), 's');
}

Test(my_strncmp, strncmp_with_substr_true)
{
  cr_assert_eq(my_strncmp("string", "stringstring", 6), 0);
  cr_assert_eq(my_strncmp("string", "stringstring", 9), -'s');
}