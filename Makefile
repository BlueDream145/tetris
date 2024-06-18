##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/check.c \
		src/color.c \
		src/display.c \
		src/engine_colision.c \
		src/engine_entities.c \
		src/engine_game.c \
		src/engine_keys.c \
		src/engine_line.c \
		src/engine_movement.c \
		src/engine_param_adapter.c \
		src/engine_param_debug.c \
		src/engine_param_handler.c \
		src/engine_param_keys.c \
		src/engine_param_utils.c \
		src/engine_param.c \
		src/engine_tetriminos.c \
		src/engine_reader.c \
		src/engine.c \
		src/instances.c \
		src/main.c \
		src/string_extra.c \
		src/string.c \
		src/output.c \
		src/utils.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -pedantic -std=c99 \
		-I include -ggdb3 -O0

LDFLAGS	+=	-lncurses -lm

NAME	=	tetris

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
