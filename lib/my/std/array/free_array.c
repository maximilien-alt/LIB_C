#include "free_array.h"

void free_array(char **arr)
{
    if (!arr)
        return;

    for (size_t index = 0; arr[index]; index += 1)
        free(arr[index]);
    free(arr);
}