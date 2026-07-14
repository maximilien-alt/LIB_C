#include <criterion/criterion.h>

#include "my_strncpy.h"
#include <unistd.h>
#include <stdio.h>

Test(my_strncpy, strncpy_null_src)
{
    char *dest = "test";

    my_strncpy(dest, NULL, 13);
    
    cr_assert_str_eq(dest, "test");
}

Test(my_strncpy, strncpy_null_dest)
{
    char *dest = NULL;

    my_strncpy(dest, "NULL", 4);
    cr_assert_null(dest);
}

Test(my_strncpy, strncpy_bigger_size)
{
    char *dest = malloc(4);

    my_strncpy(dest, "NULL", 40);

    cr_assert_str_eq(dest, "NULL");
    free(dest);
}

Test(my_strncpy, strncpy_normal)
{
    char *dest = malloc(6);

    my_strncpy(dest, "NULLLL", 4);

    cr_assert_str_eq(dest, "NULL");
    free(dest);
}