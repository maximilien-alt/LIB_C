#ifndef TYPES_H_
#define TYPES_H_

typedef struct linked_list_s
{
  void *data;
  struct linked_list_s *next;
  struct linked_list_s *prev;
} linked_list_t;

#endif /* TYPES_H_ */