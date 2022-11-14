#include <criterion/criterion.h>

#include "../free/free_list.h"
#include "add_node_front.h"

Test(add_node_front, add_node_front_to_empty_list)
{
  linked_list_t *empty = NULL;

  add_node_front(&empty, NULL);

  cr_assert_not_null(empty);
  cr_assert_null(empty->next);
  cr_assert_null(empty->prev);
}

Test(add_node_front, add_node_front_to_non_empty_list)
{
  linked_list_t *list = NULL;

  add_node_front(&list, NULL);
  add_node_front(&list, NULL);
  add_node_front(&list, NULL);

  cr_assert_null(list->prev);

  free_list(list);
}