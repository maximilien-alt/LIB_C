#include <criterion/criterion.h>

#include "../free/free_list.h"
#include "../add_back/add_node_back.h"
#include "find_node.h"

typedef struct test_s
{
  int value;
} test_t;

int filter(linked_list_t *node)
{
  test_t *test = (test_t *)(node->data);

  if (!test)
    return 0;
  return test->value == 42;
}

int is_null(linked_list_t *node)
{
  return (node->data == NULL);
}

Test(find_node, find_data_in_empty_list)
{
  linked_list_t *empty = NULL;

  cr_assert_null(find_node(empty, NULL));
}

Test(find_node, find_data_in_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *save = list;
  linked_list_t *temp = NULL;
  test_t t_1 = { 10 };
  test_t t_2 = { 42 };

  add_node_back(&list, NULL);
  add_node_back(&list, &t_1);
  add_node_back(&list, &t_2);

  save = list;
  temp = find_node(list, NULL);
  cr_assert_null(temp);
  temp = find_node(list, &is_null);
  cr_assert_eq(temp, list);
  temp = temp->next->next;
  cr_assert_eq(find_node(list, &filter), temp);
  t_2.value = 43;
  cr_assert_null(find_node(list, &filter));
  cr_assert_eq(list, save);

  free_list(list);
}