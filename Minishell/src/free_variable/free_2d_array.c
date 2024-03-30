/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** free_2D_array.c
*/

#include "../../includes/my.h"

void tbl_free_arg(char **tbl, int n)
{
    for (int i = 0; i < n; i++) {
        free(tbl[i]);
    }
    free(tbl);
}
