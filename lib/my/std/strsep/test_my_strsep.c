#include <criterion/criterion.h>

#include "../strlen/my_strlen.h"
#include "../strcmp/my_strcmp.h"
#include "my_strsep.h"

Test(my_strsep, strsep_with_null_string)
{
  char *str = NULL;

  cr_assert_null(my_strsep(&str, " "));
}

Test(my_strsep, strsep_with_null_pointer)
{
  cr_assert_null(my_strsep(NULL, " "));
}

Test(my_strsep, strsep_without_sep)
{
  char *test = strdup("Ceciestuntestsansseparateur");
  char *save = test;
  char *result = my_strsep(&test, " ");

  cr_assert_eq(my_strcmp(result, "Ceciestuntestsansseparateur"), 0);
  cr_assert_eq(my_strlen(test), 0);

  free(result);
  free(save);
}

Test(my_strsep, strsep_with_multiple_sep)
{
  char *test = strdup("  Ceci est un test avec separateurs   ");
  char *save = test;
  char *result = my_strsep(&test, " ");

  cr_assert_eq(my_strcmp(result, "Ceci"), 0);
  cr_assert_eq(my_strlen(test), 32);
  
  free(result);
  result = my_strsep(&test, " ");
  cr_assert_eq(my_strcmp(result, "est"), 0);
  cr_assert_eq(my_strlen(test), 28);

  free(result);
  result = my_strsep(&test, " ");
  cr_assert_eq(my_strcmp(result, "un"), 0);
  cr_assert_eq(my_strlen(test), 25);

  free(result);
  result = my_strsep(&test, " ");
  cr_assert_eq(my_strcmp(result, "test"), 0);
  cr_assert_eq(my_strlen(test), 20);

  free(result);
  result = my_strsep(&test, " ");
  cr_assert_eq(my_strcmp(result, "avec"), 0);
  cr_assert_eq(my_strlen(test), 15);

  free(result);
  result = my_strsep(&test, " ");
  cr_assert_eq(my_strcmp(result, "separateurs"), 0);
  cr_assert_eq(my_strlen(test), 3);
  
  free(result);
  result = my_strsep(&test, " ");
  cr_assert_null(result);
  cr_assert_eq(my_strlen(test), 0);

  free(save);
}
