##
## EPITECH PROJECT, 2023
## Make file
## File description:
## file
##

NAME	=	my_hunter

SRC	=	./src/lib_base.c	\
		./src/start.c	\
		./src/background.c	\
		./src/cat_rules.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

CSFFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-audio

RM	=	rm -f

RMTEMP	=	rm -f *~

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFFLAGS) $(CFLAGS)

clean:
	$(RM) src/*.o
	$(RMTEMP)

fclean: clean
	$(RM) $(NAME)
	$(RM) debug

re: fclean all

debug:
	$(CC) -g3 -o debug $(SRC) $(CSFFLAGS) $(CFLAGS)
