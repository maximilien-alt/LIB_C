#include <criterion/criterion.h>

#include "../free/free_list.h"
#include "../add_back/add_node_back.h"
#include "../size/list_size.h"
#include "list_filter.h"

typedef struct test_s
{
  int value;
} test_t;

int is_null(linked_list_t *node);

int is_not_null(linked_list_t *node)
{
  return !is_null(node);
}

Test(list_filter, list_filter_in_empty_list)
{
  linked_list_t *empty = NULL;

  cr_assert_null(list_filter(empty, &is_null));
}

Test(list_filter, list_filter_in_non_empty_list)
{
  linked_list_t *list = NULL;
  linked_list_t *filter_null = NULL;
  linked_list_t *filter_non_null = NULL;
  test_t t_1 = { 10 };
  test_t t_2 = { 42 };

  add_node_back(&list, NULL);
  add_node_back(&list, &t_1);
  add_node_back(&list, &t_2);

  filter_null = list_filter(list, &is_null);
  filter_non_null = list_filter(list, &is_not_null);

  cr_assert_not_null(filter_null);
  cr_assert_not_null(filter_non_null);
  cr_assert_eq(get_list_size(filter_non_null), 2);
  cr_assert_eq(get_list_size(filter_null), 1);

  free_list(list);
  free_list(filter_null);
  free_list(filter_non_null);
}