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
DLCFG	=	extern_libs/libconfig-1.7.2/

LCFG	=	config
LIBS	=	-L$(DMY) -l$(MY) -L$(DLCFG) -l$(LCFG)

DSRC	=	src/
DINIT	=	$(DSRC)init/
DESTROY	=	$(DSRC)destroy/
DACHIVE	=	$(DSRC)achievement/
DMAP	=	$(DSRC)map/
DTILE	=	$(DSRC)tile/
DTILACT	=	$(DTILE)action/
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
DTOOLS	=	$(DSRC)tools/
DDIAL	=	$(DSRC)dialog/

SRC     =	$(DSRC)main.c			\
		$(DSRC)game_loop.c		\
		$(DSTATES)states.c		\
		$(DRAW)draw.c			\
		$(DRAW)draw_scene.c		\
		$(DRAW)draw_player.c		\
		$(DRAW)draw_achievement.c	\
		$(DUPDATE)update.c		\
		$(DEVENT)event.c		\
		$(DEVENT)event_map.c		\
		$(DEVENT)event_status_menu.c	\
		$(DEVENT)event_menu.c		\
		$(DEVENT)event_dialog.c		\
		$(DINIT)init.c			\
		$(DINIT)init_achievements.c	\
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
		$(DINIT)init_vertex.c		\
		$(DINIT)init_tiles.c		\
		$(DINIT)tile_list.c		\
		$(DESTROY)destroy.c		\
		$(DESTROY)destroy_window.c	\
		$(DESTROY)destroy_event.c	\
		$(DESTROY)destroy_scenes.c	\
		$(DESTROY)destroy_buttons.c	\
		$(DESTROY)destroy_textures.c	\
		$(DESTROY)destroy_config.c	\
		$(DESTROY)destroy_text.c	\
		$(DESTROY)destroy_musics.c	\
		$(DACHIVE)achievement.c		\
		$(DACHIVE)set_achievement.c	\
		$(DMAP)light_shader.c		\
		$(DMAP)gen_light_shader.c	\
		$(DMAP)apply_on_map.c		\
		$(DTILE)get_tile_pos.c		\
		$(DTILE)update_anim_tiles.c	\
		$(DTILE)exec_tile.c		\
		$(DTILACT)action_lever.c	\
		$(DTILACT)action_door.c		\
		$(DTILACT)action_laser.c	\
		$(DTILACT)action_laser_captor.c	\
		$(DTILACT)action_room.c		\
		$(DTILACT)action_end.c		\
		$(DTILACT)action_torch.c	\
		$(DTILACT)action_unlocker.c	\
		$(DTILACT)action_spawn.c	\
		$(DTILACT)get_tile.c		\
		$(DTILACT)rotate_laser.c	\
		$(DTILACT)action_granpalight.c	\
		$(DMAP)player_light.c		\
		$(DSCENE)change_scene.c		\
		$(DSCENE)menu_status.c		\
		$(DBUTTON)manage_buttons.c 	\
		$(DBUTTON)get_func_button.c 	\
		$(DBUTACT)button_play.c		\
		$(DBUTACT)button_setting.c	\
		$(DBUTACT)button_exit.c		\
		$(DBUTACT)button_return.c	\
		$(DBUTACT)button_pause.c	\
		$(DBUTACT)button_volume.c	\
		$(DBUTACT)button_size.c		\
		$(DTOOLS)vec.c			\
		$(DTOOLS)get_rect.c		\
		$(DTOOLS)is_pos_in_rect.c	\
		$(DTOOLS)animate.c		\
		$(DTOOLS)inverse.c		\
		$(DTOOLS)open_first_room.c	\
		$(DTOOLS)wait_delta_frame.c	\
		$(DTOOLS)get_highest_chanel.c	\
		$(DTOOLS)find_setting_by_name.c	\
		$(DTOOLS)particule.c		\
		$(DTX)get_texture.c		\
		$(DTX)shift_texture_rect.c	\
		$(DPLAYER)player_event.c	\
		$(DPLAYER)update_xp.c		\
		$(DPLAYER)move_player.c		\
		$(DEVENT)event_settings.c 	\
		$(DPLAYER)rotate_player.c	\
		$(DDIAL)get_next_dialog.c	\
		$(DDIAL)update_text.c		\
		$(DEVENT)event_pause.c 		\
		$(DPLAYER)inventory.c

LDFLAGS	=	-lc_graph_prog -lconfig -lm
CFLAGS	+=	-Wall -W -Wextra -I$(INC) -g

OBJ	=	$(SRC:.c=.o)
NAME	=	my_rpg

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DMY)
	cd $(DLCFG) && gcc -fPIC -shared lib/*.c -o libconfig.so && cd ../..
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS)

clean:
	make clean -C $(DMY)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DMY)
	rm -f $(NAME)

re: fclean all
