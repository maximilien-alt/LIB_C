#include "errors.h"
#include "../std/strdup/my_strdup.h"

const int INVALID_INPUT_STATUS = 84;

error_t get_default_input_error()
{
    return (error_t) {
        INVALID_INPUT_STATUS,
        "INVALID_INPUT",
        "Provided input is invalid"
    };
}

void set_default_input_error(error_t *err, char *display)
{
    error_t def = get_default_input_error();

    err->code = def.code;
    err->status = def.status;
    err->msg = def.msg;
    if (display)
        err->display = display;
}

void my_throw(error_t error)
{
    if (error.msg)
    {
        fprintf(stderr, "[%s]: %s\n", error.code, error.msg);
        //free(error.msg);
    }
    if (error.display)
    {
        printf("%s", error.display);
        //free(error.display);
    }
    exit(error.status);
}