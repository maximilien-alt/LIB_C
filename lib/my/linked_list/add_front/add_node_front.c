#include "add_node_front.h"

void add_node_front(linked_list_t **head, void *obj)
{
  linked_list_t *new_node = malloc(sizeof(linked_list_t));

  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = obj;
  if (!(*head))
  {
    (*head) = new_node;
  }
  else
  {
    new_node->next = (*head);
    (*head)->prev = new_node;
    (*head) = new_node;
  }
}