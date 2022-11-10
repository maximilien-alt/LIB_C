#include <criterion/criterion.h>

#include "list_size.h"
#include "../add/add_node.h"

Test(list_size, list_size_to_empty_list)
{
  linked_list_t *empty = NULL;

  cr_assert_eq(get_list_size(empty), 0);
}

Test(add_node, list_size_to_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *save = NULL;

  add_node(&list, NULL);
  add_node(&list, NULL);
  add_node(&list, NULL);

  save = list;
  cr_assert_eq(get_list_size(list), 3);
  cr_assert_not_null(list);
  cr_assert_eq(list, save);

  for (linked_list_t *copy = list; copy; copy = list)
  {
    list = list->next;
    free(copy);
  }
}