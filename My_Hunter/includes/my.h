/*
** EPITECH PROJECT, 2023
** Header
** File description:
** Hunter
*/

#pragma once
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
void initialization(struct va *disp, sfVideoMode mode, struct mouse *move);
void initialization_duck(struct move *duck, sfIntRect *duck1, struct va *disp);
void render_back(struct va *disp, struct mouse *move, struct move *duck);
void destroy(struct va *disp, struct mouse *move, struct move *duck);
void render_duck(struct move *duck, sfIntRect *duck1);
void cat_rules(struct va *disp);
void render_cat(struct va *disp);
void clock_duck(sfIntRect *duck1, struct move *duck);
