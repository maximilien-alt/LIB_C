#ifndef LIST_FILTER_H_
#define LIST_FILTER_H_

#include <stdlib.h>

#include "../types.h"

linked_list_t *list_filter(linked_list_t *head, filter_callback callback);

#endif /* LIST_FILTER_H_ */