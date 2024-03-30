/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 21/03/24.
** File description:
** verif_pipe.c
*/

#include "../../../includes/my.h"

int verif_pipe(char **arg)
{
    int nb = 1;

    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i][0] == '|' || arg[i][0] == '<')
            nb++;
    }
    return nb;
}

int my_pipe_len(char **tab, int st)
{
    int nb = 0;

    for (int i = st; tab[i] != NULL; i++) {
        if (tab[i][0] == '|')
            break;
        nb++;
    }
    return nb;
}

int get_pipe_start(char **tab, int turn)
{
    int pos = 0;
    int nb = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (turn == nb) {
            pos = i;
            break;
        }
        if (tab[i][0] == '|')
            nb++;
    }
    return pos;
}

int control_prm(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';' || str[i] == '|' || str[i] == '>' || str[i] == '<')
            return 0;
    }
    return 1;
}
