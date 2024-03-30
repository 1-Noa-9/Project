/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** new_node.c
*/

#include "../../includes/my.h"

list_t *new_nod(char *value)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->next = NULL;
    new_node->path = my_strdup(value);
    return new_node;
}

void push_to_back(list_t **head, list_t *new)
{
    list_t *tmp = *head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

void push_front(list_t **head, char *value)
{
    list_t *new = malloc(sizeof(list_t));

    if (*head == NULL) {
        new->path = my_strdup(value);
        new->next = NULL;
        *head = new;
        return;
    }
    new->path = my_strdup(value);
    new->next = *head;
    *head = new;
    return;
}
