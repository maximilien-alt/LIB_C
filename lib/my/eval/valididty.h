#ifndef VALIDITY_H_
#define VALIDITY_H_

#include "types.h"
#include "../errors/errors.h"
#include "../std/strlen/my_strlen.h"

#include <stdio.h>

void check_errors(const char *expression, eval_opts_t args);

#endif /* VALIDITY_H_ */