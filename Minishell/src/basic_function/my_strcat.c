/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_strcat.c
*/

#include "../../includes/my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *copy = malloc(sizeof(char) * (dest_len + src_len) + 1);

    for (int i = 0; i < dest_len; i++)
        copy[i] = dest[i];
    for (j = 0; j < src_len; j++)
        copy[dest_len + j] = src[j];
    copy[dest_len + j] = '\0';
    return copy;
}
