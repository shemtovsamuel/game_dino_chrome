##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## build my_hunter project
##

SRC = 	src/main.c \
	src/util.c \
	src/lib.c \
	src/animation_1.c \
	src/init.c \
	src/management.c \

OBJ = $(SRC:.c=.o)

NAME = my_runner

CFLAGS += -I./ -Wall

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re
