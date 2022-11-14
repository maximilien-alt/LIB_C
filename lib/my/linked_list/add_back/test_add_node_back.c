#include <criterion/criterion.h>

#include "add_node_back.h"

Test(add_node_back, add_node_back_to_empty_list)
{
  linked_list_t *empty = NULL;

  add_node_back(&empty, NULL);
  
  cr_assert_not_null(empty);
  cr_assert_null(empty->data);
  cr_assert_null(empty->next);
  cr_assert_null(empty->prev);
  
  free(empty);
}

Test(add_node_back, add_node_back_to_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *save = list;

  add_node_back(&list, NULL);
  add_node_back(&list, NULL);
  add_node_back(&list, NULL);

  cr_assert_not_null(list->next);
  cr_assert_not_null(list->next->prev);
  cr_assert_not_null(list->next->next);
  cr_assert_null(list->next->next->next);
  cr_assert_eq(list, list->next->prev);
  cr_assert_eq(list->next, list->next->next->prev);

  for (linked_list_t *copy = list; copy; copy = list)
  {
    list = list->next;
    free(copy);
  }
}
