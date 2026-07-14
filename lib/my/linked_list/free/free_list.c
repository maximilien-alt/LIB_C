#include "free_list.h"

void free_list(linked_list_t *head, free_callback callback)
{
  for (linked_list_t *copy = head; copy; copy = head)
  {
    head = head->next;
    if (callback)
        callback(copy);
    free(copy);
  }
}
