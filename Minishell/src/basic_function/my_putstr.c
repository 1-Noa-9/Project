/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** basic_function.c
*/

#include "../../includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
