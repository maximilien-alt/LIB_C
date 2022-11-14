#include "list_filter.h"
#include "../add_back/add_node_back.h"

linked_list_t *list_filter(linked_list_t *head, filter_callback callback)
{
  linked_list_t *filtered = NULL;

  for(linked_list_t *copy = head; copy; copy = copy->next)
  {
    if (callback(copy))
      add_node_back(&filtered, copy->data);
  }
  return filtered;
}
