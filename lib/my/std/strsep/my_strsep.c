#include "../strdup/my_strdup.h"
#include "my_strsep.h"

int is_sep(char c, const char *delim)
{
  if (!c)
    return 0;
  for (size_t index = 0; delim[index]; index += 1)
    if (c == delim[index])
      return 1;
  return 0;
}

char *my_strsep(char **stringp, const char *delim)
{
  char *copy = NULL;
  size_t index = 0;
  char *result = NULL;
  char save = 0;

  if (!stringp || !(*stringp))
    return NULL;

  for(; is_sep(*(*stringp), delim); *stringp += 1);
  copy = *stringp;
  if (!copy[0])
    return NULL;
  for(; !is_sep(copy[index], delim) && copy[index]; index += 1);
  save = copy[index];
  copy[index] = 0;
  result = my_strdup(copy);
  copy[index] = save;
  *stringp += index;
  return result;
}
