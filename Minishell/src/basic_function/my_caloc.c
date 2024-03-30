/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 20/03/24.
** File description:
** my_caloc.c
*/

#include "../../includes/my.h"

char *my_caloc(int size)
{
    char *str = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return str;
}
