#include "free_list.h"

void free_list(linked_list_t *head)
{
  for (linked_list_t *copy = head; copy; copy = head)
  {
    head = head->next;
    free(copy);
  }
}
