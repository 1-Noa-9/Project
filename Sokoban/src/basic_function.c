/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** basi function
*/

#include "../includes/my2.h"

int my_strlen(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        n++;
    }
    return n;
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    return 0;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0 ;str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

void disp_rules(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap     file representing the ");
    my_putstr("warehouse map, containing '#' for walls,\n");
    my_putstr("\t\t'P' for the player, 'X' for ");
    my_putstr("boxes and 'O' for storage locations.\n");
}
