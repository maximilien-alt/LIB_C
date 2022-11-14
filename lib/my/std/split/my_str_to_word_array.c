#include "../strsep/my_strsep.h"
#include "../realloc/my_realloc.h"
#include "../strdup/my_strdup.h"
#include "my_str_to_word_array.h"

char **my_str_to_word_array(char *src, const char *delim)
{
  char **result = NULL;
  char *copy = my_strdup(src);
  char *to_free = copy;
  size_t index = 0;

  if (!src)
    return NULL;
  for(char *temp = my_strsep(&copy, delim); temp; index += 1)
  {
    result = my_realloc(result, sizeof(char *) * index, sizeof(char *) * (index + 1));
    result[index] = temp;
    temp = my_strsep(&copy, delim);
  }
  result = my_realloc(result, sizeof(char *) * index, sizeof(char *) * (index + 1));
  result[index] = NULL;
  free(to_free);
  return result;
}
