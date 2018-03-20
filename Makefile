##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	src/
INC	=	include
DLIB	=	lib/my/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
SRC     =	$(DSRC)main.c
CFLAGS	+=	-Wall -W -Wextra -I$(INC)
OBJ	=	$(SRC:.c=.o)
NAME	=	my_rpg

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re: fclean all
