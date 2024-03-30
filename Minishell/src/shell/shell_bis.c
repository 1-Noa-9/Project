/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 26/03/24.
** File description:
** shell_bis.c
*/

#include "../../includes/my.h"

int cp_cond(char **cp, int inde)
{
    if (cp != NULL)
        tbl_free_arg(cp, my_tablen(cp));
    return inde;
}

void write_arch_err(all_t *all)
{
    write(STDERR_FILENO, all->arg[0], my_strlen(all->arg[0]));
    write(STDERR_FILENO, ": Exec format error. Wrong Architecture.\n", 41);
}

void basic_ex(all_t *all)
{
    info_trait(all);
    free(all->sca);
}

int parent_fork(all_t *all, int i, int nbpipe, int *pipe_from)
{
    int n = 0;

    cond_parent_one(nbpipe, pipe_from, i, all);
    if (i != nbpipe - 1)
        return 0;
    n = cond_parent_two(nbpipe, pipe_from, all);
    return n;
}
