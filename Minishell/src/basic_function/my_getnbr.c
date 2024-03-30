/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** my_getnbr.c
*/

#include "../../includes/my.h"
#include <limits.h>

static int should_continue(char const *str, int i, long int *res, int *index)
{
    if (str[i] >= '0' && str[i] <= '9') {
        *res = *res * 10 + (str[i] - '0');
        return 1;
    }
    if (str[i] == '-') {
        *index = *index + 1;
        return 1;
    }
    if (str[i] == '+')
        return 1;
    return 0;
}

static void long_max(long int *res)
{
    long long unsigned int nb = *res;

    if (*res > 2147483647 || *res < -2147483648 || nb == ULLONG_MAX)
        *res = 0;
}

int my_getnbr(char const *str)
{
    long int res = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        if (should_continue(str, i, &res, &index) == 1)
            continue;
        if (str[i + 1] < '0' || str[i + 1] > '9' || str[i + 1] != 0)
            break;
    }
    if ((index % 2) != 0)
        res = res * (-1);
    long_max(&res);
    return res;
}
