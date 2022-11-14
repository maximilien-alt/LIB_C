#include <criterion/criterion.h>

#include "../strcmp/my_strcmp.h"
#include "my_str_to_word_array.h"

Test(my_str_to_word_array, split_with_null_string)
{
  char **res = my_str_to_word_array(NULL, " ");

  cr_assert_null(res);
}

Test(my_str_to_word_array, split_without_sep)
{
  char **result = my_str_to_word_array("Ceci est un test sans separateur", "\t");

  cr_assert_not_null(result);
  cr_assert_not_null(result[0]);
  cr_assert_null(result[1]);
  cr_assert_eq(my_strcmp("Ceci est un test sans separateur", result[0]), 0);

  free(result[0]);
  free(result);
}

Test(my_str_to_word_array, split_with_sep)
{
  char **result = my_str_to_word_array("  Ceci,,,est   un,test avec,,, separateurs  ,, ", " ,");

  cr_assert_not_null(result);
  cr_assert_not_null(result[0]);
  cr_assert_not_null(result[1]);
  cr_assert_not_null(result[2]);
  cr_assert_not_null(result[3]);
  cr_assert_not_null(result[4]);
  cr_assert_not_null(result[5]);
  cr_assert_null(result[6]);
  cr_assert_eq(0, my_strcmp("Ceci", result[0]));
  cr_assert_eq(0, my_strcmp("est", result[1]));
  cr_assert_eq(0, my_strcmp("un", result[2]));
  cr_assert_eq(0, my_strcmp("test", result[3]));
  cr_assert_eq(0, my_strcmp("avec", result[4]));
  cr_assert_eq(0, my_strcmp("separateurs", result[5]));

  for (size_t index = 0; result[index]; index += 1)
    free(result[index]);
  free(result);
}