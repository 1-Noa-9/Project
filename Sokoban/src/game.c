/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** main
*/

#include "../includes/my2.h"

static void load_map(char *map, struct map_size *size)
{
    for (int i = 0; i < size->full; i++) {
        printw("%c", map[i]);
    }
}

void find_xbis2(struct map_size *size, list_p *cmp)
{
    while (cmp != NULL) {
        find_posx(size, size->map, cmp->poso.x);
        if ((((size->map[cmp->poso.x- size->len_line6] == '#' ||
        size->map[cmp->poso.x - size->len_line6] == 'X') &&
        (size->map[cmp->poso.x + 1] == '#' || size->map[cmp->poso.x + 1] == 'X'
        )) || ((size->map[cmp->poso.x- size->len_line6] == '#' ||
        size->map[cmp->poso.x- size->len_line6] == 'X') &&
        (size->map[cmp->poso.x - 1] == '#' || size->map[cmp->poso.x- 1] == 'X'
        )) || ((size->map[cmp->poso.x + size->len_line5] == '#' ||
        size->map[cmp->poso.x + size->len_line5] == 'X') &&
        (size->map[cmp->poso.x - 1] == '#' || size->map[cmp->poso.x - 1] == 'X'
        )) || ((size->map[cmp->poso.x + size->len_line5] == '#' ||
        size->map[cmp->poso.x + size->len_line5] == 'X') &&
        (size->map[cmp->poso.x + 1] == '#' || size->map[cmp->poso.x + 1] == 'X'
        )))) {
            size->nb_fail += 1;
        }
        cmp = cmp->next;
    }
}

int find_x(struct map_size *size, list_p **head)
{
    pos_t *pos = malloc(sizeof(pos));
    list_p **head2 = malloc(sizeof(list_p));

    *head2 = NULL;
    size->nb_wins = 0;
    size->posx.x = 0;
    size->nb_fail = 0;
    for (int j = 0; j < size->nb_cols; j++)
        if (size->map[j] == 'X')
            push_to_list(head2, j);
    find_xbis2(size, *head2);
    disp_list(head, head2, size);
    free(*head2);
    *head2 = malloc(sizeof(list_p *));
    *head2 = NULL;
    if (size->nb_wins == size->nb_o)
        return 3;
    if (size->nb_fail == size->nb_x)
        return 1;
    return 0;
}

static void conditional_bis(int key, struct map_size *size, char *map)
{
    if (key == KEY_LEFT && !(map[size->posp.x - 1] == '#')) {
        if (conditional_move_box4(size, map) == 1)
            return;
        map[size->posp.x] = ' ';
        map[size->posp.x - 1] = 'P';
    }
    if (key == KEY_DOWN && !(map[size->posp.x + size->len_line] == '#')) {
        if (conditional_move_box2(size, map) == 1)
            return;
        map[size->posp.x] = ' ';
        map[size->posp.x + size->len_line] = 'P';
    }
    find_pos(size, map);
}

static void conditional_move(int key, struct map_size *size, char *map)
{
    if (key == KEY_UP && !(map[size->posp.x - size->len_line2] == '#')) {
        if (conditional_move_box1(size, map) == 1)
            return;
        map[size->posp.x] = ' ';
        map[size->posp.x - size->len_line2] = 'P';
    }
    if (key == KEY_RIGHT && !(map[size->posp.x + 1] == '#')) {
        if (conditional_move_box3(size, map) == 1)
            return;
        map[size->posp.x] = ' ';
        map[size->posp.x + 1] = 'P';
    }
    conditional_bis(key, size, map);
}

int move_on(struct map_size *size, char *map, list_p **head)
{
    while (size->nb != 3 || size->nb != 1) {
        size->nb = find_x(size, head);
        if (size->nb == 1) {
            getch();
            endwin();
            exit(1);
        }
        if (size->nb == 3) {
            getch();
            return 3;
        }
        size->key = getch();
        conditional_move(size->key, size, map);
        clear();
        conditional_printo(head, map);
        load_map(map, size);
        refresh();
    }
    return 0;
}

int game(struct map_size *size, char *map, list_p **head)
{
    int nb = 0;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    load_map(map, size);
    size->map = map;
    refresh();
    nb = move_on(size, map, head);
    if (nb == 3) {
        endwin();
        return 0;
    }
    endwin();
    return 0;
}
