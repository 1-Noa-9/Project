/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put nbr && unsigned nbr
*/

#include "../includes/my.h"

int putbis(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    return putbis(nb);
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
