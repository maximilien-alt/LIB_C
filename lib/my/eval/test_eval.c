#include <criterion/criterion.h>

#include "eval.h"

// Helper macro pour simplifier les appels
#define EVAL(expr) eval(expr, (eval_opts_t){"+-*/%()"})

/* ----------------------------- */
/*         CAS DE BASE           */
/* ----------------------------- */

Test(eval, single_positive_number)
{
    cr_assert_eq(42, EVAL("42"));
}

Test(eval, single_negative_number)
{
    cr_assert_eq(-7, EVAL("-7"));
}

Test(eval, zero)
{
    cr_assert_eq(0, EVAL("0"));
}

/* ----------------------------- */
/*      OPERATIONS SIMPLES       */
/* ----------------------------- */

Test(eval, simple_addition)
{
    cr_assert_eq(5, EVAL("2+3"));
}

Test(eval, simple_subtraction)
{
    cr_assert_eq(1, EVAL("3-2"));
}

Test(eval, simple_multiplication)
{
    cr_assert_eq(12, EVAL("3*4"));
}

Test(eval, simple_division)
{
    cr_assert_eq(4, EVAL("8/2"));
}

Test(eval, simple_modulo)
{
    cr_assert_eq(1, EVAL("7%3"));
}

/* ----------------------------- */
/*     PRIORITE DES OPERATEURS   */
/* ----------------------------- */

Test(eval, priority_mul_over_add)
{
    cr_assert_eq(14, EVAL("2+3*4"));
}

Test(eval, priority_div_over_sub)
{
    cr_assert_eq(8, EVAL("10-4/2"));
}

Test(eval, priority_mul_and_div)
{
    cr_assert_eq(10, EVAL("2*10/2"));
}

Test(eval, priority_mod_over_add)
{
    cr_assert_eq(3, EVAL("1+7%2*2"));
}

Test(eval, complex_priority)
{
    cr_assert_eq(161, EVAL("18+3*5-12/3+7*2-8/4+10-6*3+14/7*2-9+5*4-16/2+11-3*6+20/5*3-8+9*2-6/3+13*4-10/2+7-15+18/3*2-5+6*7-14/2+9*3-8+12/4*5-7"));
}

/* ----------------------------- */
/*      SIGNES CONSECUTIFS       */
/* ----------------------------- */

Test(eval, double_minus)
{
    cr_assert_eq(5, EVAL("3--2"));
}

Test(eval, triple_minus)
{
    cr_assert_eq(1, EVAL("3---2"));
}

Test(eval, mixed_signs_minus)
{
    cr_assert_eq(5, EVAL("3-+-+--2"));
}

Test(eval, leading_minus)
{
    cr_assert_eq(-5, EVAL("-3-2"));
}

Test(eval, leading_double_minus)
{
    cr_assert_eq(5, EVAL("--3+2"));
}

Test(eval, signs_with_mul)
{
    cr_assert_eq(-6, EVAL("-2*3"));
}

/* ----------------------------- */
/*         PARENTHESES           */
/* ----------------------------- */

Test(eval, simple_parentheses)
{
    cr_assert_eq(20, EVAL("(2+3)*4"));
}

Test(eval, parentheses_division)
{
    cr_assert_eq(2, EVAL("10/(2+3)"));
}

Test(eval, nested_parentheses)
{
    cr_assert_eq(46, EVAL("2*(3+(4*5))"));
}

Test(eval, multiple_parentheses_same_level)
{
    cr_assert_eq(30, EVAL("(2+3)*(4-1)*(10/5)"));
}

Test(eval, parentheses_with_negative)
{
    cr_assert_eq(-14, EVAL("-(3+4)*2"));
}

Test(eval, parentheses_with_double_minus)
{
    cr_assert_eq(20, EVAL("(2--3)*4"));
}

Test(eval, deeply_nested_parentheses)
{
    cr_assert_eq(19, EVAL("((2+3)*2)+((4-1)*3)"));
}

Test(eval, parentheses_complex)
{
    cr_assert_eq(42, EVAL("((3+5)*2-(4/2))*3"));
}

Test(eval, parentheses_with_modulo)
{
    cr_assert_eq(2, EVAL("(7+3)%4*2/(10/5)"));
}

/* ----------------------------- */
/*          CAS LIMITES          */
/* ----------------------------- */

Test(eval, division_result_truncated)
{
    cr_assert_eq(2, EVAL("5/2"));
}

Test(eval, modulo_zero_result)
{
    cr_assert_eq(0, EVAL("4%2"));
}

Test(eval, result_is_zero)
{
    cr_assert_eq(0, EVAL("3-3"));
}

Test(eval, large_numbers)
{
    cr_assert_eq(10000, EVAL("100*100"));
}

Test(eval, negative_result)
{
    cr_assert_eq(-6, EVAL("2-8"));
}

Test(eval, chained_same_operator)
{
    cr_assert_eq(10, EVAL("1+2+3+4"));
}

Test(eval, chained_subtractions)
{
    cr_assert_eq(-8, EVAL("1-2-3-4"));
}

/* ----------------------------- */
/*            ERREURS            */
/* ----------------------------- */

Test(eval, null_expression, .exit_code = 84)
{
    EVAL(NULL);
}

Test(eval, empty_expression, .exit_code = 84)
{
    EVAL("");
}

Test(eval, division_by_zero, .exit_code = 84)
{
    EVAL("5/0");
}

Test(eval, modulo_by_zero, .exit_code = 84)
{
    EVAL("5%0");
}

Test(eval, invalid_characters, .exit_code = 84)
{
    EVAL("2a+3");
}

Test(eval, only_operator, .exit_code = 84)
{
    EVAL("+");
}

Test(eval, missing_operand_right, .exit_code = 84)
{
    EVAL("3+");
}

Test(eval, missing_operand_left, .exit_code = 84)
{
    EVAL("*3");
}

// Test(eval, unbalanced_parens_open, .exit_code = 84)
// {
    // EVAL("(3+2");
// }

Test(eval, unbalanced_parens_close, .exit_code = 84)
{
    EVAL("3+2)");
}

Test(eval, overflow_int_max, .exit_code = 84)
{
    EVAL("2147483648");
}

/* ----------------------------- */
/*        OVERFLOW ADD           */
/* ----------------------------- */

Test(eval, overflow_add_positive, .exit_code = 84)
{
    EVAL("2147483647+1");
}

Test(eval, overflow_add_negative, .exit_code = 84)
{
    EVAL("-2147483647+-2");
}

/* ----------------------------- */
/*        OVERFLOW SUB           */
/* ----------------------------- */

Test(eval, overflow_sub_positive, .exit_code = 84)
{
    EVAL("2147483647-(-1)");
}

Test(eval, overflow_sub_negative, .exit_code = 84)
{
    EVAL("-2147483647-2");
}

/* ----------------------------- */
/*        OVERFLOW MUL           */
/* ----------------------------- */

Test(eval, overflow_mul_positive, .exit_code = 84)
{
    EVAL("2147483647*2");
}

Test(eval, overflow_mul_negative, .exit_code = 84)
{
    EVAL("-2147483647*2");
}

Test(eval, mul_zero_no_overflow, .exit_code = 0)
{
    cr_assert_eq(0, EVAL("2147483647*0"));
}

Test(eval, mul_one_no_overflow, .exit_code = 0)
{
    cr_assert_eq(2147483647, EVAL("2147483647*1"));
}

/* ----------------------------- */
/*        OVERFLOW DIV           */
/* ----------------------------- */

Test(eval, div_by_zero, .exit_code = 84)
{
    EVAL("5/0");
}

Test(eval, div_int_min_by_minus_one, .exit_code = 84)
{
    EVAL("-2147483648/(-1)");
}

// Test(eval, div_normal, .exit_code = 0)
// {
    // cr_assert_eq(-1073741824, EVAL("-2147483648/2"));
// }

/* ----------------------------- */
/*        OVERFLOW MOD           */
/* ----------------------------- */

Test(eval, mod_by_zero, .exit_code = 84)
{
    EVAL("5%0");
}

Test(eval, mod_int_min_by_minus_one, .exit_code = 84)
{
    EVAL("-2147483648%(-1)");
}

// Test(eval, mod_normal, .exit_code = 0)
// {
    // cr_assert_eq(0, EVAL("-2147483648%2"));
// }