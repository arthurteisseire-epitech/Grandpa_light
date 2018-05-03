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
DRAW	=	$(DSTATES)draw/
DESTROY	=	$(DSRC)destroy/
DPARSE	=	$(DINIT)parse/

SRC     =	$(DSRC)main.c			\
		$(DSRC)game_loop.c		\
		$(DSRC)get_texture.c		\
		$(DSTATES)states.c		\
		$(DRAW)draw.c			\
		$(DRAW)draw_scene.c		\
		$(DSTATES)update.c		\
		$(DSTATES)event.c		\
		$(DINIT)init.c			\
		$(DINIT)init_event.c		\
		$(DINIT)init_window.c		\
		$(DINIT)init_scenes.c		\
		$(DINIT)init_map.c		\
		$(DINIT)init_buttons.c		\
		$(DINIT)init_text.c		\
		$(DINIT)init_textures.c		\
		$(DINIT)init_config.c		\
		$(DINIT)init_clock.c	\
		$(DESTROY)destroy.c		\
		$(DESTROY)destroy_window.c	\
		$(DESTROY)destroy_event.c	\
		$(DESTROY)destroy_scenes.c	\
		$(DESTROY)destroy_buttons.c	\
		$(DESTROY)destroy_textures.c	\
		$(DESTROY)destroy_config.c	\
		$(DESTROY)destroy_clock.c	\
		$(DPARSE)parse_image.c		\
		$(DPARSE)tile_list.c

LDFLAGS	=	-lc_graph_prog -lconfig
CFLAGS	+=	-Wall -W -Wextra -I$(INC) -g

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
