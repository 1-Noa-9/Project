/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** parsing.c
*/

#include "../../includes/my.h"

int count_args(char *str, all_t *all)
{
    char *cp = my_strdup(str);
    char *token = strtok(cp, " ");

    all->nb = 0;
    while (token != NULL) {
        all->nb++;
        token = strtok(NULL, " ");
    }
    free(cp);
    return 0;
}

void assign_path(all_t *all)
{
    char *cp = my_strdup(all->sca);
    char *token;
    int i = 0;

    all->arg = malloc(sizeof(char *) * (all->nb + 1));
    token = strtok(cp, " \t");
    while (token != NULL) {
        all->arg[i] = my_strdup(token);
        i++;
        token = strtok(NULL, " \t");
    }
    all->arg[i] = NULL;
    free(cp);
}
