##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	include
DLIB	=	lib/my/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)

DSRC	=	src/
DINIT	=	$(DSRC)init/
DSTATES	=	$(DSRC)states/
DRAW	=	$(DSTATES)draw/
DESTROY	=	$(DSRC)destroy/
DPARSE	=	$(DINIT)parse/

SRC     =	$(DSRC)main.c			\
		$(DSRC)game_loop.c		\
		$(DSTATES)states.c		\
		$(DRAW)draw.c			\
		$(DSTATES)update.c		\
		$(DSTATES)event.c		\
		$(DINIT)init.c			\
		$(DINIT)init_event.c		\
		$(DINIT)init_window.c		\
		$(DINIT)init_scenes.c		\
		$(DESTROY)destroy.c		\
		$(DESTROY)destroy_window.c	\
		$(DESTROY)destroy_event.c	\
		$(DPARSE)parse_image.c		\
		$(DPARSE)tile_list.c

CFLAGS	+=	-Wall -W -Wextra -I$(INC) -g
LDFLAGS	=	-lc_graph_prog
OBJ	=	$(SRC:.c=.o)
NAME	=	my_rpg

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re: fclean all
