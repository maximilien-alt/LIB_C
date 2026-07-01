#ifndef PARSE_H_
#define PARSE_H_

#include "types.h"
#include "../errors/errors.h"
#include "../std/realloc/my_realloc.h"
#include "../std/strlen/my_strlen.h"

#include <stdlib.h>
#include <limits.h>

binary_tree_t *parse(char *expression, eval_opts_t args, binary_tree_t *);

#endif /* PARSE_H_ */