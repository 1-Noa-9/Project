/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** delete_node.c
*/

#include "../../includes/my.h"

static void delete_bis(list_t *tmp, list_t *before, list_t *list)
{
    if (tmp != NULL) {
        free(list->path);
        list->path = tmp->path;
        list->next = tmp->next;
    } else {
        free(list->path);
        free(list);
        before->next = NULL;
    }
    free(tmp);
}

static int count_node(list_t **begin)
{
    list_t *count = *begin;
    int nb = 0;

    for (; count != NULL; count = count->next)
        nb++;
    return nb;
}

static void list_nul(list_t **begin, list_t *list)
{
    free(list);
    list = NULL;
    *begin = list;
}

int delete_in_list(list_t **begin, char *ref)
{
    list_t *list = *begin;
    list_t *tmp;
    list_t *before;
    int nb = count_node(begin);

    if (nb == 1) {
        list_nul(begin, list);
        return 0;
    }
    while (list != NULL) {
        if (my_strncmp(list->path, ref, my_strlen_env(ref)) == 0) {
            tmp = list->next;
            delete_bis(tmp, before, list);
            return 0;
        }
        before = list;
        list = list->next;
    }
    return 1;
}
