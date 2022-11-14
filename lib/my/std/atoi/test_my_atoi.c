#include <criterion/criterion.h>

#include "my_atoi.h"

Test(my_atoi, atoi_with_null_value)
{
  cr_assert_eq(my_atoi(NULL), 0);
}

Test(my_atoi, atoi_with_basic_value)
{
  cr_assert_eq(185, my_atoi("185"));
}

Test(my_atoi, atoi_with_multiple_operators_value)
{
  cr_assert_eq(-47284, my_atoi("+-+-+----+--+-47284"));
}

Test(my_atoi, atoi_overflow_handle)
{
  cr_assert_eq(0, my_atoi("4728400000000"));
}
