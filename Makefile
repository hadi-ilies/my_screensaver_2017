##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC= 		$(SRC_DIR)screen_saver.c	\
		$(SRC_DIR)clear.c \
		$(SRC_DIR)display_window.c \
		$(SRC_DIR)flag.c \
		$(SRC_DIR)display.c \
		$(SRC_DIR)rayon.c \
		$(SRC_DIR)choice.c

SRC_DIR	=	src/

INC_DIR	=	include/

LIB_DIR	=	lib/

OBJ=            $(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I $(INC_DIR) -g

LDFLAGS	=	-L $(LIB_DIR) -lmy -lm -lc_graph_prog

NAME=           my_screensaver

all:            $(NAME)

$(NAME):        $(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C $(LIB_DIR)
		rm -f $(OBJ)

fclean:		clean
		make fclean -C $(LIB_DIR)
		rm -f $(NAME)

re:		fclean all
