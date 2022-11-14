#include <criterion/criterion.h>

#include "free_list.h"
#include "../add_back/add_node_back.h"

Test(free_list, free_list_to_empty_list)
{
  linked_list_t *empty = NULL;

  free_list(empty);
  cr_assert_null(empty);
}

Test(free_list, list_size_to_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *save = list;

  add_node_back(&list, NULL);
  add_node_back(&list, NULL);
  add_node_back(&list, NULL);

  cr_assert_not_null(list);

  free_list(list);

  cr_assert_neq(list, save);
}