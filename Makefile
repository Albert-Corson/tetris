##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	src/main.c							\
		src/tools/get_tetrimino.c			\
		src/tools/init_tetriminos.c			\
		src/tools/init_tetris_var.c			\
		src/tools/usage.c					\
		src/tools/list.c					\
		src/tools/table.c					\
		src/tools/pattern.c					\
		src/tools/my_nisnum.c				\
		src/tools/list_sort.c				\
		src/tools/my_strlowcase.c			\
		src/debug/debug_mode.c				\
		src/flags/read_flags.c				\
		src/game/game.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra
CFLAGS	+=	-I ./include

NCURSES	=	-lncurses

LIBPATH	= ./lib/

NAME	=	tetris

DEBUG	?=	0

ifneq ($(DEBUG), 0)
	ifeq ($(DEBUG), 1)
		CFLAGS += -g -g3 -ggdb
	endif
endif

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C$(LIBPATH)
	gcc -o $(NAME) $(OBJ) $(NCURSES) -L$(LIBPATH) -lmy

debug: fclean
	make DEBUG=1 -C./

clean:
	make clean -C$(LIBPATH)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C$(LIBPATH)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean debug