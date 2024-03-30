/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 14/02/24.
** File description:
** built_in_unset_env.c
*/

#include "../../includes/my.h"

int my_unset_env(all_t *all)
{
    char *value;

    if (all->nb < 2) {
        if (all->built_ind != 0)
            write(STDERR_FILENO, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    for (int i = 1; i < all->nb; i++) {
        value = my_strdup(all->arg[i]);
        if (delete_in_list(&all->ls_env, value) == 0) {
            free(value);
        }
    }
    return 0;
}
