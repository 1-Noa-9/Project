/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** main
*/

#include "../includes/my2.h"

void disp_2(list_p *list, list_p *list_x, struct map_size *size)
{
    while (list != NULL) {
        if (list_x->poso.x == list->poso.x)
            size->nb_wins += 1;
        list = list->next;
    }
}

int disp_list(list_p **head, list_p **head2, struct map_size *size)
{
    list_p *list;
    list_p *list_x = *head2;

    while (list_x != NULL) {
        list = *head;
        disp_2(list, list_x, size);
        list_x = list_x->next;
    }
    return 0;
}

void inti(struct map_size *size)
{
    size->nb_cols = 0;
    size->nb_x = 0;
    size->nb_fail = 0;
    size->nb_o = 0;
    size->nb_wins = 0;
    size->len_line = 0;
    size->posp.x = 0;
    size->len_line2 = 0;
    size->len_line3 = 0;
    size->len_line4 = 0;
    size->posbis.x = 0;
    size->posx.x = 0;
    size->nb_contact = 0;
    size->nb = 0;
}

int mainbis(struct map_size *size, char *map, list_p **head)
{
    int nb = game(size, map, head);

    if (nb == 1) {
        write(2, "GAME OVER\n", 11);
        return 1;
    } else
        my_putstr("Win Games\n");
    return 0;
}

int main(int argc, char *argv[])
{
    struct map_size size;
    list_p **head = malloc(sizeof(list_p));
    char *map;

    inti(&size);
    *head = NULL;
    if (argc == 1)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0) {
        disp_rules();
        return 0;
    }
    if (find_size(argv[1], &size) == 84)
        return 84;
    map = load_file_in_mem(argv[1], head);
    find_pos(&size, map);
    if (mainbis(&size, map, head) == 1)
        return 1;
    return 0;
}
