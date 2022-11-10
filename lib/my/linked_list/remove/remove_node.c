#include "remove_node.h"

void remove_node(linked_list_t **head, linked_list_t *to_remove)
{
  linked_list_t *to_free = NULL;
  linked_list_t **copy = head;

  if (!(*head) || !to_remove)
    return;
  for (linked_list_t *it = *copy; it; it = it->next)
  {
    if (it != to_remove)
      continue;
    to_free = it;
    if (!it->prev)
      *copy = (*copy)->next;
    else
      it->prev->next = it->next;
    if (it->next)
      it->next->prev = it->prev;
    break;
  }
  if (to_free)
    free(to_free);
  head = copy;
}
