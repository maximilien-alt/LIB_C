#include "add_node.h"

void add_node(linked_list_t **head, void *obj)
{
  linked_list_t *new_node = malloc(sizeof(linked_list_t));
  linked_list_t *current = *head;

  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = obj;
  if (!current)
  {
    (*head) = new_node;
  }
  else
  {
    for (;current->next;current = current->next);
    new_node->prev = current;
    current->next = new_node;
  }
}
