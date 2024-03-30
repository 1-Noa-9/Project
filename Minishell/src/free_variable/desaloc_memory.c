/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 14/02/24.
** File description:
** desaloc_memoru.c
*/

#include "../../includes/my.h"

void ls_free(list_t *list)
{
    list_t *begin = list;
    list_t *before;

    while (begin != NULL) {
        before = begin;
        begin = begin->next;
        free(before->path);
        free(before);
    }
}

int desaloc(all_t *all)
{
    int rt = all->rt;

    ls_free(all->pat);
    ls_free(all->ls_env);
    if (all->arg != NULL)
        tbl_free_arg(all->arg, all->nb);
    free(all->sca);
    if (all->old_pwd != NULL)
        free(all->old_pwd);
    free(all);
    return rt;
}
