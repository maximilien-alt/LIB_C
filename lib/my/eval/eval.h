#ifndef EVAL_H_
#define EVAL_H_

#include "types.h"
#include "../errors/errors.h"
#include "../std/index.h"
#include "valididty.h"
#include "parse.h"
#include "safe.h"

#include <stdio.h>

int eval(const char *expression, eval_opts_t args);

#endif /* EVAL_H_ */