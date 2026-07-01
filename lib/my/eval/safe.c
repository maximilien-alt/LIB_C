#include "safe.h"

int safe_add(int a, int b)
{
    error_t err = get_default_input_error();

    if (b > 0 && a > INT_MAX - b)
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while adding" });
    if (b < 0 && a < INT_MIN - b)
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while adding" });
    return a + b;
}

int safe_sub(int a, int b)
{
    error_t err = get_default_input_error();

    if (b < 0 && a > INT_MAX + b)
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while subing" });
    if (b > 0 && a < INT_MIN + b)
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while subing" });
    return a - b;
}

int safe_mul(int a, int b)
{
    error_t err = get_default_input_error();

    if (a != 0 && b != 0)
    {
        if (a > INT_MAX / b || a < INT_MIN / b)
            my_throw((error_t){ err.status, err.code, err.msg, "Overflow while multiplying" });
    }
    return a * b;
}

int safe_div(int a, int b)
{
    error_t err = get_default_input_error();

    if (b == 0 || (a == INT_MIN && b == -1))
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while dividing" });
    return a / b;
}

int safe_mod(int a, int b)
{
    error_t err = get_default_input_error();

    if (b == 0 || (a == INT_MIN && b == -1))
        my_throw((error_t){ err.status, err.code, err.msg, "Overflow while moduling" });
    return a % b;
}