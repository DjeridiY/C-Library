##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE =	src/

SRC =	$(SOURCE)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_program

CPPFLAGS = -iquote./include/

CFLAGS	= -Wall -Wextra

LDFLAGS = -L./lib/my

LDLIBS = -lmy

all:	$(NAME)

debug: CFLAGS += -g3

debug: clean $(NAME)

valgrind: debug
	valgrind ./$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean :
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re debug
