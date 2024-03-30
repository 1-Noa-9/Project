/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_strcmp.c
*/

#include "../../includes/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int nb = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < nb; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    return 0;
}
