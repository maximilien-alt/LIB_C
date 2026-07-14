#include <criterion/criterion.h>

#include "free_array.h"

Test(free_array, free_array_with_null_value)
{
    char **empty = NULL;

    free_array(empty);
    cr_assert_null(empty);
}

Test(free_array, free_array_empty)
{
    char **arr = malloc(sizeof(char *) * 10);

    for (size_t i = 0; i < 10; i += 1)
        arr[i] = NULL;
    free_array(arr);
    cr_free(arr);
}

Test(free_array, free_array_basic)
{
    char **arr = malloc(sizeof(char *) * 10);

    for (size_t i = 0; i < 9; i += 1)
        arr[i] = malloc(10);
    arr[9] = NULL;
    free_array(arr);
    for (size_t i = 0; i < 9; i += 1)
        cr_free(arr[i]);
    cr_free(arr);
}
