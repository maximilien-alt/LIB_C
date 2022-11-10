#include <criterion/criterion.h>

#include "remove_node.h"
#include "../add/add_node.h"
#include "../size/list_size.h"

linked_list_t *setup_list(int size)
{
  linked_list_t *list = NULL;

  for (int index = 0; index < size; index += 1)
    add_node(&list, NULL);
  return list;
}

void free_list(linked_list_t *list)
{
  for (linked_list_t *copy = list; copy; copy = list)
  {
    list = list->next;
    free(copy);
  }
}

Test(remove_node, remove_node_to_empty_list)
{
  linked_list_t *empty = NULL;

  remove_node(&empty, NULL);
  
  cr_assert_null(empty);
}

Test(remove_node, remove_empty_node_to_list)
{
  linked_list_t *list = setup_list(3);

  remove_node(&list, NULL);
  
  cr_assert_eq(get_list_size(list), 3);

  free_list(list);
}

Test(remove_node, remove_unknown_node_to_list)
{
  linked_list_t *list = setup_list(3);
  linked_list_t *unknown = malloc(sizeof(linked_list_t));

  remove_node(&list, unknown);
  
  cr_assert_eq(get_list_size(list), 3);

  free_list(list);
  free(unknown);
}

Test(remove_node, remove_unique_node)
{
  linked_list_t *list = setup_list(1);

  remove_node(&list, list);
  
  cr_assert_null(list);
}

Test(remove_node, remove_first_node)
{
  linked_list_t *list = setup_list(2);

  remove_node(&list, list);
  
  cr_assert_not_null(list);
  cr_assert_null(list->prev);
  cr_assert_null(list->next);
  
  free(list);
}

Test(remove_node, remove_last_node)
{
  linked_list_t *list = setup_list(2);

  remove_node(&list, list->next);
  
  cr_assert_not_null(list);
  cr_assert_null(list->prev);
  cr_assert_null(list->next);
  
  free(list);
}

Test(remove_node, remove_mid_node)
{
  linked_list_t *list = setup_list(3);

  remove_node(&list, list->next);
  
  cr_assert_eq(get_list_size(list), 2);
  cr_assert_not_null(list);
  cr_assert_null(list->next->next);
  cr_assert_eq(list, list->next->prev);

  
  free_list(list);
}