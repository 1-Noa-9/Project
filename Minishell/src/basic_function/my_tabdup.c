/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 21/03/24.
** File description:
** my_tabdup.c
*/

#include "../../includes/my.h"

char **my_tab_dup(char **tab)
{
    char **cp = malloc(sizeof(char *) * (my_tablen(tab) +1));
    int i = 0;

    for (; tab[i] != NULL; i++) {
        cp[i] = my_strdup(tab[i]);
    }
    cp[i] = NULL;
    return cp;
}
