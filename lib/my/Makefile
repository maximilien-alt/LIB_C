SRC	=	linked_list/add_back/add_node_back.c	\
			linked_list/add_front/add_node_front.c	\
			linked_list/size/list_size.c	\
			linked_list/remove/remove_node.c	\
			linked_list/free/free_list.c	\
			linked_list/at_index/list_at_index.c	\
			linked_list/find/find_node.c	\
			linked_list/filter/list_filter.c	\
			std/memcpy/my_memcpy.c	\
			std/memset/my_memset.c	\
			std/realloc/my_realloc.c	\
			std/strdup/my_strdup.c	\
			std/strlen/my_strlen.c	\
			std/strsep/my_strsep.c	\
			std/strcat/my_strcat.c	\
			std/strcmp/my_strcmp.c	\
			std/strncmp/my_strncmp.c	\
			std/split/my_str_to_word_array.c	\
			std/atoi/my_atoi.c	\

TESTS	=	linked_list/add_back/test_add_node_back.c	\
			linked_list/add_front/test_add_node_front.c	\
			linked_list/size/test_list_size.c	\
			linked_list/remove/test_remove_node.c	\
			linked_list/free/test_free_list.c	\
			linked_list/at_index/test_list_at_index.c	\
			linked_list/find/test_find_node.c	\
			linked_list/filter/test_list_filter.c	\
			std/memset/test_my_memset.c	\
			std/strdup/test_my_strdup.c	\
			std/strlen/test_my_strlen.c	\
			std/strsep/test_my_strsep.c	\
			std/strcat/test_my_strcat.c	\
			std/strcmp/test_my_strcmp.c	\
			std/strncmp/test_my_strncmp.c	\
			std/split/test_my_str_to_word_array.c	\
			std/atoi/test_my_atoi.c	\

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

TEST_OBJ	=	$(SRC:.c=.o) $(TESTS:.c=.o)

DIR_GCOVR	=	gcovr/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)
	rm -f *.gcda
	rm -f *.gcno
	rm -rf $(DIR_GCOVR)

fclean: clean
	rm -rf $(NAME)
	rm -f unit_tests

re: fclean all

test_run: clean $(TEST_OBJ)
	$(CC) -o unit_tests ${SRC} $(TESTS) --coverage -lcriterion
	./unit_tests

gcovr: test_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude='.*test.*' --html --html-details --html-title $(NAME) -o $(NAME).html
