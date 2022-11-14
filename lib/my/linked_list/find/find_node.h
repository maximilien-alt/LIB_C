#ifndef LIST_FIND_H_
#define LIST_FIND_H_

#include <stdlib.h>

#include "../types.h"

linked_list_t * find_node(linked_list_t *head, filter_callback callback);

#endif /* LIST_FIND_H_ */