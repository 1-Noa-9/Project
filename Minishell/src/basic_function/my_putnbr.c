/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_putnbr.c
*/

#include "../../includes/my.h"

static int putbis(long int nb)
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
