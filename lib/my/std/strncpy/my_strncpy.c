#include "my_strncpy.h"

void my_strncpy(char *dest, char *src, size_t size)
{
    if (!dest || !src)
        return;
    
    for (size_t index = 0; index < size && src[index]; index += 1)
        dest[index] = src[index];
    dest[size] = 0;
}