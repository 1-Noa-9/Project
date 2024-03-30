/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_strncmp.c
*/

#include "../../includes/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 < n || len2 < n) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
