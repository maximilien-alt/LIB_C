#include "parse.h"

int get_number(char *nptr, eval_opts_t args)
{
    int result = 0;
    size_t index = 0;
    size_t number_of_subs = 0;
    error_t err;

    for (; nptr[index] == args.operators[0] || nptr[index] == args.operators[1]; index++)
        number_of_subs += (nptr[index] == args.operators[1]) ? 1 : 0;
    for (; nptr[index] && (nptr[index] >= '0' && nptr[index] <= '9'); index++)
    {
        if (INT_MAX / 10 < result)
        {
            err = get_default_input_error();
            my_throw((error_t){ err.status, err.code, err.msg, "Maximum int size reached\n" });
        }
        result *= 10;
        if (INT_MAX - (nptr[index] - '0') < result)
        {
            err = get_default_input_error();
            my_throw((error_t){ err.status, err.code, err.msg, "Maximum int size reached\n" });
        }
        result += nptr[index] - '0';
    }
    if (number_of_subs % 2)
    {
        if (result > (int)((unsigned int)INT_MAX + 1))
        {
            err = get_default_input_error();
            my_throw((error_t){ err.status, err.code, err.msg, "Maximum int size reached\n" });
        }
        result *= -1;
    }
    return result;
}

int resolve_sign(char *expr, int start, int *new_start, eval_opts_t args)
{
    int sign = 1;
    
    while (start >= 0 && (expr[start] == args.operators[0] || expr[start] == args.operators[1]))
    {
        if (expr[start] == args.operators[1])
            sign *= -1;
        start -= 1;
    }
    *new_start = start;
    return sign;
}

binary_tree_t *create_node_operator(
    char *expression,
    eval_opts_t args,
    binary_tree_t *tree,
    int expression_index,
    int operator_index
)
{
    int new_start = 0;
    int sign = resolve_sign(expression, expression_index, &new_start, args);
                
    tree = my_realloc(tree, 0, sizeof(binary_tree_t));
    tree->number = 0;
    if (expression[expression_index] == args.operators[0] || expression[expression_index] == args.operators[1])
        tree->operator = (sign == -1) ? args.operators[1] : args.operators[0];
    else
        tree->operator = args.operators[operator_index];
    expression[(new_start != expression_index) ? new_start + 1 : expression_index] = 0;
    tree->left = parse(expression, args, NULL);
    tree->right = parse(&expression[expression_index + 1], args, NULL);
    return tree;
}

int find_matching_bracket(char *expression, int start_index, eval_opts_t args)
{
    error_t err;
    int searching_index = (size_t)start_index - 1;
    size_t bracket_count = 1;

    for (; searching_index >= 0; searching_index -= 1)
    {
        if (expression[searching_index] == args.operators[5])
        {
            if (bracket_count == 1)
                return searching_index;
            bracket_count -= 1;
        }
        if (expression[searching_index] == args.operators[6])
            bracket_count += 1;
    }

    err = get_default_input_error();
    my_throw((error_t){ err.status, err.code, err.msg, "Matching bracket not found\n" });
    return 0;
}

binary_tree_t *parse(char *expression, eval_opts_t args, binary_tree_t *tree)
{
    size_t expression_length = my_strlen(expression);

    for (int expression_index = expression_length - 1; expression_index >= 0; expression_index -= 1)
    {
        if (expression[expression_index] == args.operators[6])
        {
            expression_index = find_matching_bracket(expression, expression_index, args);
            continue;
        }
        for (int operator_index = 0; operator_index < 2; operator_index += 1)
        {
            if (expression[expression_index] == args.operators[operator_index])
                return create_node_operator(expression, args, tree, expression_index, operator_index);
        }
    }
    for (int expression_index = expression_length - 1; expression_index >= 0; expression_index -= 1)
    {
        if (expression[expression_index] == args.operators[6])
        {
            expression_index = find_matching_bracket(expression, expression_index, args);
            continue;
        }
        for (int operator_index = 2; operator_index < 5; operator_index += 1)
        {
            if (expression[expression_index] == args.operators[operator_index])
                return create_node_operator(expression, args, tree, expression_index, operator_index);
        }
    }

    if (expression[0] == args.operators[5])
    {
        expression[expression_length - 1] = 0;
        return parse(&expression[1], args, tree);
    }
    tree = my_realloc(tree, 0, sizeof(binary_tree_t));
    tree->number = get_number(expression, args);
    tree->operator = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}