#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct error_s
{
    int status;
    const char *code;
    char *msg;
    char *display;
} error_t;

extern const int INVALID_INPUT_STATUS;

void my_throw(error_t error);
error_t get_default_input_error();
void set_default_input_error(error_t *err, char *display);

#endif /* ERRORS_H_ */