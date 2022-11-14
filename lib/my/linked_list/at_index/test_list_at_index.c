#include <criterion/criterion.h>

#include "list_at_index.h"
#include "../free/free_list.h"
#include "../add_back/add_node_back.h"

Test(list_at_index, list_at_index_to_empty_list)
{
  linked_list_t *empty = NULL;

  cr_assert_null(list_at_index(empty, 0));
}

Test(list_at_index, list_at_index_to_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *temp = NULL;

  add_node_back(&list, NULL);
  add_node_back(&list, NULL);
  add_node_back(&list, NULL);

  temp = list_at_index(list, 0);
  cr_assert_eq(temp, list);
  temp = temp->next;
  cr_assert_eq(list_at_index(list, 1), temp);
  temp = temp->next;
  cr_assert_eq(list_at_index(list, 2), temp);
  cr_assert_null(list_at_index(list, 3));

  free_list(list);
}