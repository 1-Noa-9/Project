/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** move box
*/

#include "../includes/my2.h"

int conditional_move_box4(struct map_size *size, char *map)
{
    if (map[size->posp.x - 1] == 'X') {
        if (map[size->posp.x - 2] == '#' || map[size->posp.x - 2] == 'X')
            return 1;
        map[size->posp.x] = ' ';
        map[size->posp.x - 2] = 'X';
        size->nb_contact++;
    }
    return 0;
}

int conditional_move_box3(struct map_size *size, char *map)
{
    if (map[size->posp.x + 1] == 'X') {
        if (map[size->posp.x + 2] == '#' || map[size->posp.x + 2] == 'X')
            return 1;
        map[size->posp.x] = ' ';
        map[size->posp.x + 2] = 'X';
        size->nb_contact++;
    }
    return 0;
}

int conditional_move_box2(struct map_size *size, char *map)
{
    if (map[size->posp.x + size->len_line] == 'X') {
        if (map[size->posp.x + (size->len_line4 + size->len_line)] == '#' ||
        map[size->posp.x + (size->len_line4 + size->len_line)] == 'X')
            return 1;
        map[size->posp.x] = ' ';
        map[size->posp.x + (size->len_line4 + size->len_line)] = 'X';
        size->nb_contact++;
    }
    return 0;
}

int conditional_move_box1(struct map_size *size, char *map)
{
    if (map[size->posp.x - size->len_line2] == 'X') {
        if (map[size->posp.x - (size->len_line3 + size->len_line2)] == '#' ||
        map[size->posp.x - (size->len_line3 + size->len_line2)] == 'X')
            return 1;
        map[size->posp.x] = ' ';
        map[size->posp.x - (size->len_line3 + size->len_line2)] = 'X';
        size->nb_contact++;
    }
    return 0;
}

void conditional_printo(list_p **head, char *map)
{
    list_p *temp = *head;

    while (temp != NULL) {
        if (map[temp->poso.x] != 'P' && map[temp->poso.x] != 'X')
            map[temp->poso.x] = 'O';
        temp = temp->next;
    }
}
