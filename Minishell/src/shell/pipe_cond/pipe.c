/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 21/03/24.
** File description:
** pipe.c
*/

#include "../../../includes/my.h"

char **get_pipe_arg(char **tab, int turn)
{
    int index = 0;
    int st = get_pipe_start(tab, turn);
    char **arg = malloc(sizeof(char *) * (my_pipe_len(tab, st) + 1));

    for (int i = st; tab[i] != NULL; i++) {
        if (i == (my_pipe_len(tab, st) + st))
            break;
        arg[index] = my_strdup(tab[i]);
        index++;
    }
    arg[index] = NULL;
    return arg;
}

static int is_redirect(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i][0] == '<')
            return 1;
    }
    return 0;
}

static void remove_index(char **arg, int i)
{
    int j = 0;
    char *buf = NULL;

    for (j = i; arg[j] != NULL; j++) {
        if (arg[j + 1] != NULL) {
            free(arg[j]);
            buf = my_strdup(arg[j + 1]);
            arg[j] = my_strdup(buf);
            free(buf);
        } else
            break;
    }
    free(arg[j]);
    arg[j] = NULL;
}

static void replace_arg(char **arg)
{
    int i = 0;

    for (; arg[i] != NULL; i++) {
        if (arg[i][0] == '<')
            break;
    }
    remove_index(arg, i);
    remove_index(arg, i);
}

static void remove_arg(char **cp, int i)
{
    free(cp[i]);
    free(cp[i + 1]);
    cp[i] = NULL;
}

static char **get_redirect_arg(char **cp, all_t *all)
{
    char **arg = NULL;
    int i = 0;
    int ind = 0;

    for (; cp[i] != NULL; i++)
        if (cp[i][0] == '<' && cp[i + 1] != NULL) {
            ind = 1;
            break;
        }
    if (ind == 1) {
        arg = malloc(sizeof(char *) * 2);
        arg[0] = my_strdup(cp[i + 1]);
        arg[1] = NULL;
        if (my_tablen(cp) > i)
            replace_arg(cp);
        else
            remove_arg(cp, i);
        all->redirect_ind = 1;
    }
    return arg;
}

void cond_one(all_t *all, char **cp, int i, int *pipe_from)
{
    if (all->wind != 1 || all->pipe > 1)
        pipe(pipe_from);
    if (all->pipe > 1) {
        if (all->arg != NULL)
            tbl_free_arg(all->arg, my_tablen(all->arg));
        if (cp != NULL && is_redirect(cp) == 0)
            all->arg = get_pipe_arg(cp, i);
        if (cp != NULL && is_redirect(cp) == 1)
            all->arg = get_redirect_arg(cp, all);
    }
}

int cond_child(int nbpipe, int *pipe_from, int i, all_t *all)
{
    char *buff = NULL;
    int fd = 0;
    ssize_t btread = 0;

    if ((nbpipe > 1 && i != nbpipe - 1) || all->wind != 1) {
        close(pipe_from[0]);
        dup2(pipe_from[1], STDOUT_FILENO);
        close(pipe_from[1]);
        if (all->redirect_ind == 1) {
            buff = malloc(sizeof(char) * 62000);
            fd = open(all->arg[0], O_RDONLY);
            btread = read(fd, buff, 62000);
            write(STDOUT_FILENO, buff, btread);
            free(buff);
            close(fd);
            return 1;
        }
    }
    return 0;
}

void cond_parent_one(int nbpipe, int *pipe_from, int i, all_t *all)
{
    if ((nbpipe > 1 && i != nbpipe - 1) ||
    (all->wind != 1 && i != nbpipe - 1)) {
        close(pipe_from[1]);
        dup2(pipe_from[0], STDIN_FILENO);
    } else if (nbpipe > 1 || all->wind != 1) {
        close(pipe_from[1]);
    }
}

int cond_parent_two(int nbpipe, int *pipe_from, all_t *all)
{
    char *buffer;
    ssize_t bytes_read = 0;
    int n = 0;

    if (nbpipe > 1 || all->wind != 1) {
        buffer = malloc(sizeof(char) * 62000);
        bytes_read = read(pipe_from[0], buffer, 62000);
        write(all->wind, buffer, bytes_read);
        close(pipe_from[0]);
        free(buffer);
        if (all->wind != 1) {
            close(all->wind);
            all->wind = 1;
        }
    }
    n = wait_child(all);
    return n;
}
