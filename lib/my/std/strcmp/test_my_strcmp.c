#include <criterion/criterion.h>

#include "my_strcmp.h"

Test(my_strcmp, strcmp_not_matching_first_letter)
{
  cr_assert_eq(my_strcmp("first", "second"), 'f'-'s');
}

Test(my_strcmp, strcmp_with_substr)
{
  cr_assert_eq(my_strcmp("stringstring", "string"), 's');
}
