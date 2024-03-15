#include "list_at_index.h"

linked_list_t *list_at_index(linked_list_t *head, size_t index)
{
  size_t current = 0;

  for (linked_list_t *copy = head; copy; copy = copy->next)
  {
    if (current == index)
      return copy;
    current += 1;
  }
  return NULL;
}