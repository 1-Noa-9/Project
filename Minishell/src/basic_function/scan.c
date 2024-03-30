/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** scan.c
*/

#include "../../includes/my.h"

char *ext(void)
{
    char *buff = malloc(sizeof(char) * 5);

    buff[0] = 'e';
    buff[1] = 'x';
    buff[2] = 'i';
    buff[3] = 't';
    buff[4] = '\0';
    return buff;
}

int scan_bis(char *scan, ssize_t btread, int ind)
{
    if (btread > 0) {
        if (scan[btread - 1] == '\n' || ind == 1)
            return 0;
        else
            return 1;
    }
    return 1;
}

void scan_verif(char *scan)
{
    int i = 0;

    for (i = 0; scan[i] != '\0'; i++) {
        if (scan[i] == '\t')
            scan[i] = ' ';
        if (scan[i] == '\n')
            scan[i] = '\0';
    }
}

char *my_scan_bis(char *str)
{
    char *scan = NULL;
    size_t len = 0;
    ssize_t read;

    if (str != NULL)
        my_putstr(str);
    while (1) {
        read = getline(&scan, &len, stdin);
        if (read > 0)
            break;
        if (read == -1)
            return ext();
    }
    for (int i = 0; scan[i] != '\0'; i++) {
        if (scan[i] == '\t')
            scan[i] = ' ';
        if (scan[i] == '\n')
            scan[i] = '\0';
    }
    return scan;
}

char *my_scan(char *str, int index, int tty)
{
    char scan[32000];
    ssize_t btread;
    char *buff = NULL;

    if (str != NULL)
        my_putstr(str);
    if (tty == 1)
        return my_scan_bis(NULL);
    while (1) {
        btread = read(index, scan, sizeof(scan));
        if (scan_bis(scan, btread, tty) == 0)
            break;
        return ext();
    }
    scan[btread] = '\0';
    scan_verif(scan);
    buff = my_strdup(scan);
    return buff;
}
