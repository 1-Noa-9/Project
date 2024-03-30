##
## EPITECH PROJECT, 2023
## Make file
## File description:
## file
##

NAME	=	mysh

SRC	=	./src/basic_function/my_putstr.c	\
		./src/basic_function/my_putnbr.c	\
		./src/basic_function/my_strcat.c	\
		./src/basic_function/my_strcmp.c	\
		./src/basic_function/my_strncmp.c	\
		./src/basic_function/my_strrevcmp.c	\
		./src/basic_function/my_strdup.c	\
		./src/basic_function/my_strlen.c	\
		./src/basic_function/my_getnbr.c	\
		./src/basic_function/scan.c	\
		./src/built_in/built_in_cd.c	\
		./src/built_in/built_in_set_env.c	\
		./src/built_in/built_in_unset_env.c	\
		./src/free_variable/desaloc_memory.c	\
		./src/free_variable/free_2d_array.c	\
		./src/linked_list/delete_node.c	\
		./src/linked_list/new_node.c	\
		./src/linked_list/print_list.c	\
		./src/shell/environement/find_path.c	\
		./src/shell/parsing.c	\
		./src/shell/shell.c	\
		./src/main.c	\
		./src/pipe/all.c	\
		./src/basic_function/my_caloc.c	\
		./src/shell/shell_turn.c	\
		./src/basic_function/my_tablen.c	\
		./src/basic_function/my_tabdup.c	\
		./src/shell/pipe_cond/pipe.c	\
		./src/shell/pipe_cond/verif_pipe.c	\
		./src/shell/built_in.c	\
		./src/shell/shell_bis.c	\
		./src/shell/write_error.c


OBJ	=	$(SRC:.c=.o)

CPFLAGS	=	-Werror -Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPFLAGS)

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:
	$(CC) -g3 -o $(NAME) $(SRC) $(CPFLAGS)
