#include "find_node.h"

linked_list_t *find_node(linked_list_t *head, find_callback callback, void *args)
{
  if (!callback)
    return NULL;

  for (linked_list_t *copy = head; copy; copy = copy->next)
  {
    if (callback(copy, args))
      return copy;
  }
  return NULL;
}
