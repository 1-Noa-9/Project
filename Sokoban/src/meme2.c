/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** basi function
*/

#include "../includes/my2.h"

static void len_line(struct nb *all, char *map, struct map_size *size)
{
    size->len_line5 = 0;
    size->len_line6 = 0;
    size->len_line7 = 0;
    size->len_line8 = 0;
    for (int i = all->nb4; map[i] != '\n'; i++) {
        size->len_line8++;
    }
    size->len_line8++;
    for (int i = all->nb1; map[i] != '\n'; i++) {
        size->len_line5++;
    }
    size->len_line5++;
    for (int i = all->nb2; map[i] != '\n'; i++) {
        size->len_line6++;
    }
    size->len_line6++;
    for (int i = all->nb3; map[i] != '\n'; i++) {
        size->len_line7++;
    }
    size->len_line7++;
}

static void find_nb4(struct map_size *size, char *map, struct nb *all)
{
    all->nb = 0;
    for (int i = size->posx.x; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            all->nb++;
        if (all->nb == 1) {
            all->nb4 = i + 1;
            break;
        }
    }
}

static void find_nb(struct map_size *size, char *map, struct nb *all)
{
    for (int i = size->posx.x; i != 0; i--) {
        if (map[i] == '\n' && all->nb1 == 0) {
            all->nb1 = i + 1;
        }
        if (map[i] == '\n')
            all->nb++;
        if (map[i] == '\n' && all->nb1 != 0 && all->nb == 2) {
            all->nb2 = i + 1;
        }
        if (map[i] == '\n' && all->nb2 != 0 && all->nb == 3) {
            all->nb3 = i + 1;
            break;
        }
    }
    find_nb4(size, map, all);
}

void find_posx(struct map_size *size, char *map, int posx)
{
    struct nb all;

    all.nb1 = 0;
    all.nb2 = 0;
    all.nb3 = 0;
    all.nb4 = 0;
    all.nb = 0;
    size->posx.x = posx;
    find_nb(size, map, &all);
    len_line(&all, map, size);
}
