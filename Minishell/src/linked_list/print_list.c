/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** list.c
*/

#include "../../includes/my.h"

void print_list(list_t *list)
{
    while (list != NULL) {
        my_putstr(list->path);
        my_putchar('\n');
        list = list->next;
    }
}
