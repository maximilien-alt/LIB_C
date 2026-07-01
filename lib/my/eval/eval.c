#include "eval.h"

int compute_tree(binary_tree_t *tree, eval_opts_t args)
{
    int result = 0;
    error_t err;


    if (tree->operator == 0)
    {
        result = tree->number;
        free(tree);
        return result;
    }
    
    if (tree->operator == args.operators[0])
    {
        result = safe_add(compute_tree(tree->left, args), compute_tree(tree->right, args));
        free(tree);
        return result;
    }
    if (tree->operator == args.operators[1])
    {
        result = safe_sub(compute_tree(tree->left, args), compute_tree(tree->right, args));
        free(tree);
        return result;
    }
    if (tree->operator == args.operators[2])
    {
        result = safe_mul(compute_tree(tree->left, args), compute_tree(tree->right, args));
        free(tree);
        return result;
    }
    if (tree->operator == args.operators[3])
    {
        const int right_side = compute_tree(tree->right, args);
        err = get_default_input_error();
        if (right_side == 0)
            my_throw((error_t){ err.status, err.code, err.msg, "Can't divide by zero/n" });
        result = safe_div(compute_tree(tree->left, args), right_side);
        free(tree);
        return result;
    }
    
    const int right_side = compute_tree(tree->right, args);
    err = get_default_input_error();
    if (right_side == 0)
        my_throw((error_t){ err.status, err.code, err.msg, "Can't divide by zero/n" });
    result = safe_mod(compute_tree(tree->left, args), right_side);
    free(tree);
    return result;
}

int eval(const char *expression, eval_opts_t args)
{
    binary_tree_t *tree = NULL;
    char *copy = NULL;

    check_errors(expression, args);

    copy = my_strdup(expression);
    tree = parse(copy, args, tree);
    free(copy);
    return compute_tree(tree, args);
}