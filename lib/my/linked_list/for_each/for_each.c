#include "for_each.h"

void list_for_each(linked_list_t *head, for_each_callback callback)
{
    for (linked_list_t *copy = head; copy; copy = copy->next)
        callback(copy);
}