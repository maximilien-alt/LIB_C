SRC	=	linked_list/add/add_node.c	\
			linked_list/size/list_size.c	\
			linked_list/remove/remove_node.c

TESTS	=	linked_list/add/test_add_node.c	\
			linked_list/size/test_list_size.c	\
			linked_list/remove/test_remove_node.c

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
