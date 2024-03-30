/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_strdup.c
*/

#include "../../includes/my.h"

char *my_strdup(char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i;

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
