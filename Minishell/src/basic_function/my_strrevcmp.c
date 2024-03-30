/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 28/03/24.
** File description:
** my_strrevcmp.c
*/

#include "../../includes/my.h"

int my_strnrevcmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1) - 1;
    int len2 = len1 - n;

    if (len2 <= 0)
        return 84;
    for (int i = len1; i != len2; i--) {
        if (s1[i] != s2[i - len2])
            return s1[i] - s2[i - len2];
    }
    return 0;
}
