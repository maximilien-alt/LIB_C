#ifndef EVAL_TYPES_H_
#define EVAL_TYPES_H_

typedef struct eval_opts_s
{
    char *operators;//+-*/%() by default
} eval_opts_t;

typedef struct binary_tree_s
{
    char operator;
    int number;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

#endif /* EVAL_TYPES_H_ */