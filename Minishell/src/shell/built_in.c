/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 22/03/24.
** File description:
** built_in.c
*/

#include "../../includes/my.h"

int built_in(all_t *all)
{
    all->nb = my_tablen(all->arg);
    if (my_strcmp(all->arg[0], "cd") == 0) {
        cmd_cd(all);
        if (all->built_ind == 0)
            exit(0);
        return 1;
    }
    if (my_strcmp(all->arg[0], "setenv") == 0) {
        my_setenv(all);
        if (all->built_ind == 0)
            exit(0);
        return 1;
    }
    if (my_strcmp(all->arg[0], "unsetenv") == 0) {
        my_unset_env(all);
        if (all->built_ind == 0)
            exit(0);
        return 1;
    }
    return 0;
}
