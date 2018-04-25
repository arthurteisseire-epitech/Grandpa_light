##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	include
DLIB	=	lib/
DMY	=	$(DLIB)my/
MY	=	my
DLCFG	=	$(DLIB)libconfig
LCFG	=	config
LIBS	=	-L$(DMY) -l$(MY) -L$(DLCFG) -l$(LCFG)

DSRC	=	src/
DINIT	=	$(DSRC)init/
DSTATES	=	$(DSRC)states/
DESTROY	=	$(DSRC)destroy/

SRC     =	$(DSRC)main.c			\
		$(DSRC)game_loop.c		\
		$(DSTATES)states.c		\
		$(DSTATES)draw.c		\
		$(DSTATES)update.c		\
		$(DSTATES)event.c		\
		$(DINIT)init.c			\
		$(DINIT)init_event.c		\
		$(DINIT)init_window.c		\
		$(DESTROY)destroy.c		\
		$(DESTROY)destroy_window.c	\
		$(DESTROY)destroy_event.c	\

CFLAGS	+=	-Wall -W -Wextra -I$(INC)
LDFLAGS	=	-lc_graph_prog -lconfig
OBJ	=	$(SRC:.c=.o)
NAME	=	my_rpg

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DMY)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS)

clean:
	make clean -C $(DMY)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DMY)
	rm -f $(NAME)

re: fclean all
