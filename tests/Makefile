##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DROOT	=	../
DLIB	=	$(ROOT)lib/my/
DSRC	=	$(ROOT)src/
DSRC_UT	=	./
INC	=	$(DLIB)

SRC	=	$(DSRC)f.c

SRC_UT	=	$(DSRC_UT)tests_f.c

LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
CFLAGS	+=	-Wall -W -Wextra --coverage -I$(INC)
LDFLAGS	=	-lcriterion -lgcov
NAME	=	units

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run: re
	./$(NAME)
	gcov *.gcno
