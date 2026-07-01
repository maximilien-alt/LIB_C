#include "valididty.h"

int is_numeric(char c, eval_opts_t args, int strict)
{
    if (!strict)
        return (c >= '0' && c <= '9') || c == args.operators[0] || c == args.operators[1] || c == args.operators[5] || c == args.operators[6];
    return (c >= '0' && c <= '9') || c == args.operators[5] || c == args.operators[6];
}

void ensure_expression_exists(const char *expression, eval_opts_t args, error_t *error)
{
    (void)args;

    if (!expression)
        return set_default_input_error(error, "Expression is non existent\n");
    if (my_strlen(expression) == 0)
        return set_default_input_error(error, "Empty expression\n");
}

void ensure_characters_validity(const char *expression, eval_opts_t args, error_t *error)
{
    int operator_exist = 0;

    for (int index = 0; expression[index]; index += 1)
    {
        if (expression[index] >= '0' && expression[index] <= '9')
            continue;

        operator_exist = 0;
        for (int operator = 0; operator < 7; operator += 1)
            if (expression[index] == args.operators[operator])
            {
                operator_exist = 1;
                break;
            }
        if (!operator_exist)
            return set_default_input_error(error, "Expression contains uncomputable characters\n");
    }
}

void ensure_operators_validity(const char *expression, eval_opts_t args, error_t *error)
{
    const size_t expression_len = my_strlen(expression);

    for (size_t index = 0; expression[index]; index += 1)
    {
        if (is_numeric(expression[index], args, 0))
            continue;
        
        if (index == 0 || index == expression_len - 1)
            return set_default_input_error(error, "Expression can't starts or ends with this operator\n");
        
        if (!is_numeric(expression[index - 1], args, 1) || !is_numeric(expression[index + 1], args, 0))
            return set_default_input_error(error, "Invalid operation\n");
    }
}

void ensure_numbers_validity(const char *expression, eval_opts_t args, error_t *error)
{
    const size_t expression_len = my_strlen(expression);

    if (!is_numeric(expression[expression_len - 1], args, 1) && expression[expression_len - 1] != args.operators[6])
        return set_default_input_error(error, "Expression must ends with a valid number\n");
}

static void (*const errors_patterns[])(const char *, eval_opts_t, error_t *) = {
    ensure_expression_exists,
    ensure_characters_validity,
    ensure_operators_validity,
    ensure_numbers_validity,
    NULL
};

void check_errors(const char *expression, eval_opts_t args)
{
    error_t err;

    for (int index = 0; errors_patterns[index]; index += 1)
    {
        errors_patterns[index](expression, args, &err);
        if (err.status == INVALID_INPUT_STATUS)
            my_throw(err);
    }
}