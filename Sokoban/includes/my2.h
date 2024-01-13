/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** HEADER
*/

#pragma once
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pos_s {
    int x;
} pos_t;

typedef struct list {
    pos_t poso;
    struct list *next;
} list_p;

struct map_size {
    int nb_cols;
    int nb;
    int len_line;
    int len_line2;
    int len_line3;
    int len_line4;
    int len_line5;
    int len_line6;
    int len_line7;
    int len_line8;
    int nb_o;
    int nb_x;
    int nb_fail;
    int nb_wins;
    pos_t posp;
    pos_t posx;
    pos_t posbis;
    int full;
    int nb_contact;
    int key;
    char *map;
};

struct nb {
    int nb;
    int nb1;
    int nb2;
    int nb3;
    int nb4;
};

struct size {
    int nb_cols;
    int i;
};

// meme alloc
void disp_rules(void);
int find_size(char const *file, struct map_size *size);
char *load_file_in_mem(char const *filepath, list_p **head);
// game
void find_pos(struct map_size *size, char *map);
int game(struct map_size *size, char *map, list_p **head);
void conditional_printo(list_p **head, char *map);
// basic
int my_putstr(char const *str);
// move box
int conditional_move_box1(struct map_size *size, char *map);
int conditional_move_box2(struct map_size *size, char *map);
int conditional_move_box3(struct map_size *size, char *map);
int conditional_move_box4(struct map_size *size, char *map);

int disp_list(list_p **head, list_p **head2, struct map_size *size);
void push_to_list(list_p **head, int x);
int my_strcmp(char const *s1, char const *s2);
void find_posx(struct map_size *size, char *map, int posx);
