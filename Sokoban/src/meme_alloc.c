/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** alloc
*/

#include "../includes/my2.h"

static void len_line(struct nb *all, char *map, struct map_size *size)
{
    size->len_line = 0;
    size->len_line2 = 0;
    size->len_line3 = 0;
    size->len_line4 = 0;
    for (int i = all->nb4; map[i] != '\n'; i++) {
        size->len_line4++;
    }
    size->len_line4++;
    for (int i = all->nb1; map[i] != '\n'; i++) {
        size->len_line++;
    }
    size->len_line++;
    for (int i = all->nb2; map[i] != '\n'; i++) {
        size->len_line2++;
    }
    size->len_line2++;
    for (int i = all->nb3; map[i] != '\n'; i++) {
        size->len_line3++;
    }
    size->len_line3++;
}

static void find_nb4(struct map_size *size, char *map, struct nb *all)
{
    all->nb = 0;
    for (int i = size->posp.x; map[i] != '\0'; i++) {
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
    for (int i = size->posp.x; i != 0; i--) {
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

void find_pos(struct map_size *size, char *map)
{
    struct nb all;

    all.nb1 = 0;
    all.nb2 = 0;
    all.nb3 = 0;
    all.nb4 = 0;
    all.nb = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P') {
            size->posp.x = i;
            break;
        }
    }
    find_nb(size, map, &all);
    len_line(&all, map, size);
}

int count_o_x_verif(char *buffer, struct map_size *size)
{
    for (int i = 0; i < size->full; i++) {
        size->nb_cols++;
        if (buffer[i] == 'X')
            size->nb_x++;
        if (buffer[i] == 'O')
            size->nb_o++;
        if (!(buffer[i] == 'O' || buffer[i] == 'X' || buffer[i] == ' ' ||
        buffer[i] == '#' || buffer[i] == 'P' || buffer[i] == '\n' ||
        buffer[i] == '\0'))
            return 84;
    }
    if (size->nb_o != size->nb_x)
        return 84;
    return 0;
}

int find_size(char const *file, struct map_size *size)
{
    struct stat path;
    int fd = open(file, O_RDONLY);
    char *buffer;

    size->full = 0;
    if (fd < 0)
        return 84;
    if (stat(file, &path) != 0 || path.st_size == 0)
        return 84;
    if (!S_ISREG(path.st_mode))
        return 84;
    buffer = malloc(sizeof(char) * (path.st_size));
    size->full = (path.st_size);
    read(fd, buffer, path.st_size);
    if (count_o_x_verif(buffer, size) == 84)
        return 84;
    close(fd);
    free(buffer);
    return 0;
}

void push_to_list(list_p **head, int x)
{
    list_p *new_pos = malloc(sizeof(list_p));

    new_pos->poso.x = x;
    new_pos->next = (*head);
    *head = new_pos;
}

char *load_file_in_mem(char const *filepath, list_p **head)
{
    struct stat *path = malloc(sizeof(struct stat));
    char *buffer;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, path);
    buffer = malloc(sizeof(char *) * (path->st_blksize * path->st_blocks));
    read(fd, buffer, (path->st_blksize * path->st_blocks));
    for (int i = 0; i < path->st_size; i++) {
        if (buffer[i] == 'O')
            push_to_list(head, i);
    }
    close(fd);
    return buffer;
}
