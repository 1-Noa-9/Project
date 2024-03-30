/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 28/03/24.
** File description:
** write_error.c
*/

#include "../../includes/my.h"

void write_redirect_err(char *cmd)
{
    int ind = 0;

    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == ' ' && ind != 1) {
            ind++;
            write(2, ": ", 2);
            continue;
        }
        if (cmd[i] == ' ' && ind == 1)
            break;
        write(2, &cmd[i], 1);
    }
    write(2, ": input file is output file\n", 28);
}
