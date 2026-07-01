#ifndef SAFE_H_
#define SAFE_H_

#include "../errors/errors.h"

#include <stdlib.h>
#include <limits.h>

int safe_add(int a, int b);
int safe_sub(int a, int b);
int safe_mul(int a, int b);
int safe_div(int a, int b);
int safe_mod(int a, int b);

#endif /* SAFE_H_ */