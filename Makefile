##
## EPITECH PROJECT, 2024
## stumper4
## File description:
## Makefile
##

SRC = 		src/op.c 			\
      		lib/my_putstr.c 	\
			lib/my_putchar.c 	\
			lib/my_strlen.c 	\
			lib/my_strcat.c 	\
			lib/my_strcmp.c 	\
			lib/my_str_to_word_array.c 	\
			lib/convert_int.c 	\
			lib/my_compare.c	\
			lib/count_argv.c	\
			lib/str_cpy.c 		\
			lib/my_str_is_num.c \
			src/test_error/test_header.c 	\
			lib/reverse_int.c 	\
			lib/create_new_file.c \
			lib/my_getnbr.c 	\
			src/parsers/parsing.c	\
			src/parsers/add.c 	\
			src/parsers/aff.c 	\
			src/parsers/and.c 	\
			src/parsers/fork.c 	\
			src/parsers/ld.c 	\
			src/parsers/ldi.c 	\
			src/parsers/lfork.c 	\
			src/parsers/live.c 	\
			src/parsers/lld.c 	\
			src/parsers/lldi.c 	\
			src/parsers/or.c 	\
			src/parsers/st.c 	\
			src/parsers/sti.c 	\
			src/parsers/sub.c 	\
			src/parsers/xor.c 	\
			src/parsers/zjmp.c 	\
			src/parsers/utils.c \
			src/test_error/test_label_char.c	\
			lib/str_in_str.c	\
			src/test_error/test_head_file.c

SRC_TESTS =	$(SRC)
SRC_TESTS	+=	tests/test.c

SRC_MAIN = 	$(SRC)
SRC_MAIN += 	src/main.c

OBJ	=	${SRC_MAIN:.c=.o}

NAME	=	asm

NAME_CRIT	=	unit_tests

CFLAGS	=	-I./includes/

CPPFLAGS = -Wall -Wextra -std=c99 -Werror

LDLIB	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

unit_tests:
	gcc -o $(NAME_CRIT) $(SRC_TESTS) $(LDLIB)

tests_run:	unit_tests
	./$(NAME_CRIT)

debug:	CPPFLAGS += -g
debug:	re

clean:
	rm -f $(OBJ)
	rm -f  src/*.o
	rm -f tests/*.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.cor
	rm -f *.log
	rm -f test

fclean:	clean
	rm -f $(NAME) *.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(NAME_CRIT) *.o
	rm -f *.gcov

re:	fclean all clean

.PHONY: all clean fclean re tests_run unit_tests
