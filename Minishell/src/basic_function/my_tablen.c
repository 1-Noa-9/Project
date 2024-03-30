/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 21/03/24.
** File description:
** my_tablen.c
*/

#include "../../includes/my.h"

int my_tablen(char **tab)
{
    int nb = 0;

    for (int i = 0; tab[i] != NULL; i++)
        nb++;
    return nb;
}
