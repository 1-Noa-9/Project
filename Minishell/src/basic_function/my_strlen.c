/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_strlen.c
*/

#include "../../includes/my.h"

int my_strlen(char const *str)
{
    int n = 0;

    for (; str[n] != '\0'; n++);
    return n;
}
