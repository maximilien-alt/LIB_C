#include "list_size.h"

size_t get_list_size(linked_list_t *head)
{
  size_t len = 0;

  for(linked_list_t *copy = head;copy;copy = copy->next)
    len += 1;
  return len;
}
