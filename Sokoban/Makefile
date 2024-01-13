##
## EPITECH PROJECT, 2023
## Make file
## File description:
## file
##

NAME	=	my_sokoban

SRCS	=	src/main.c	\
			src/meme_alloc.c	\
			src/basic_function.c	\
			src/game.c	\
			src/move_box.c	\
			src/meme2.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

RM	=	rm -f

RMTEMP	=	rm -f *~

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

all: $(NAME)

clean:
	$(RM) src/*.o
	$(RMTEMP)

fclean: clean
	$(RM) $(NAME)
	$(RM) debug

re: fclean all

debug:
	$(CC) -g3 -o debug $(OBJ) $(CFLAGS) -lncurses -g
