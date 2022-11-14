#include "find_node.h"

linked_list_t *find_node(linked_list_t *head, filter_callback callback)
{
  if (!callback)
    return NULL;

  for (linked_list_t *copy = head; copy; copy = copy->next)
  {
    if (callback(copy))
      return copy;
  }
  return NULL;
}
