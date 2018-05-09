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
DESTROY	=	$(DSRC)destroy/
DMAP	=	$(DSRC)map/
DMAPACT	=	$(DMAP)action/
DSCENE	=	$(DSRC)scene/
DBUTTON	=	$(DSRC)button/
DBUTACT	=	$(DBUTTON)action/
DPLAYER	=	$(DSRC)player/
DTX	=	$(DSRC)texture/
DSTATES	=	$(DSRC)states/
DTOOLS	=	$(DSRC)tools/
DEVENT	=	$(DSTATES)event/
DUPDATE	=	$(DSTATES)update/
DRAW	=	$(DSTATES)draw/
DPARSE	=	$(DINIT)parse/
DTOOLS	=	$(DSRC)tools/

SRC     =	$(DSRC)main.c			\
		$(DSRC)game_loop.c		\
		$(DSTATES)states.c		\
		$(DRAW)draw.c			\
		$(DRAW)draw_scene.c		\
		$(DRAW)draw_player.c		\
		$(DUPDATE)update.c		\
		$(DEVENT)event.c		\
		$(DINIT)init.c			\
		$(DINIT)init_player.c		\
		$(DINIT)init_event.c		\
		$(DINIT)init_window.c		\
		$(DINIT)init_musics.c		\
		$(DINIT)init_scenes.c		\
		$(DINIT)init_map.c		\
		$(DINIT)init_buttons.c		\
		$(DINIT)init_text.c		\
		$(DINIT)init_textures.c		\
		$(DINIT)init_config.c		\
		$(DINIT)init_clock.c		\
		$(DINIT)init_shape.c		\
		$(DINIT)init_laser.c		\
		$(DINIT)init_anim_tiles.c	\
		$(DESTROY)destroy.c		\
		$(DESTROY)destroy_window.c	\
		$(DESTROY)destroy_event.c	\
		$(DESTROY)destroy_scenes.c	\
		$(DESTROY)destroy_buttons.c	\
		$(DESTROY)destroy_textures.c	\
		$(DESTROY)destroy_config.c	\
		$(DESTROY)destroy_text.c	\
		$(DESTROY)destroy_musics.c	\
		$(DPARSE)parse_image.c		\
		$(DSRC)loop_menu.c 		\
		$(DPARSE)tile_list.c		\
		$(DMAP)apply_on_map.c		\
		$(DMAP)get_tile_pos.c		\
		$(DMAP)light_shader.c		\
		$(DMAP)gen_light_shader.c	\
		$(DMAP)update_anim_tiles.c	\
		$(DMAPACT)action_lever.c	\
		$(DMAPACT)action_door.c		\
		$(DMAPACT)action_laser.c	\
		$(DMAPACT)action_laser_captor.c	\
		$(DMAPACT)action_room.c		\
		$(DMAPACT)action_end.c		\
		$(DMAPACT)swap_laser.c		\
		$(DMAPACT)get_tile.c		\
		$(DSCENE)change_scene.c		\
		$(DBUTTON)manage_buttons.c 	\
		$(DBUTTON)get_func_button.c 	\
		$(DBUTACT)button_play.c		\
		$(DBUTACT)button_setting.c	\
		$(DBUTACT)button_credit.c	\
		$(DTOOLS)vec.c			\
		$(DTOOLS)get_rect.c		\
		$(DTOOLS)is_pos_in_rect.c	\
		$(DTOOLS)animate.c		\
		$(DTOOLS)inverse.c		\
		$(DTOOLS)open_first_room.c	\
		$(DTX)get_texture.c		\
		$(DTX)shift_texture_rect.c	\
		$(DTX)wait_delta_frame.c	\
		$(DPLAYER)player_event.c	\
		$(DPLAYER)move_player.c		\
		$(DPLAYER)rotate_player.c

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
