#include <criterion/criterion.h>

#include "../strcmp/my_strcmp.h"
#include "readfile.h"

Test(readfile, invalid_file)
{
  cr_assert_null(readfile(""));
}

Test(readfile, empty_file)
{
  cr_assert_null(readfile("std/read/empty_file.txt"));
}

Test(readfile, good_read)
{
  char *test = readfile("std/read/test_read.txt");

  if (!test)
    cr_assert(false);
  else
    cr_assert_eq(my_strcmp(test, "test de read"), 0);
  free(test);
}
