/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 20/03/24.
** File description:
** shell_turn.c
*/

#include "../../includes/my.h"

static int is_pipe(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '|' || str[i] == '<')
            return 1;
    return 0;
}

static void re_write(all_t *all, char **arg, int i)
{
    if (all->wind < 0) {
        close(all->wind);
        all->wind = open(arg[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    }
}

static void verif_redirect(all_t *all, char **arg, int i)
{
    for (; arg[i] != NULL; i++) {
        if (arg[i][0] == ';')
            break;
        if (arg[i][0] == '>' && arg[i][1] != '\0' &&
        arg[i][1] == '>' && arg[i + 1] != NULL) {
            all->wind = open(arg[i + 1], O_RDWR | O_APPEND);
            re_write(all, arg, i);
            break;
        }
        if (arg[i][0] == '>' && arg[i][1] == '\0' && arg[i + 1] != NULL) {
            all->wind = open(arg[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
            break;
        } else {
            all->wind = 1;
        }
    }
}

int super_verif_redirect(char **arg, int i, char *cmd)
{
    if (my_strcmp(arg[i], ">>") == 0) {
        if (arg[i + 1] != NULL &&
            my_strnrevcmp(cmd, arg[i + 1], my_strlen(arg[i + 1]) - 1) == 0) {
            write_redirect_err(cmd);
            return 1;
        }
    }
    return 0;
}

static int cond_bis(all_t *all, char **arg, int *i)
{
    if (is_pipe(all->sca) == 1) {
        if (arg[*i][0] == ';')
            *i += 1;
        *i += 1;
        basic_ex(all);
        return 0;
    }
    if (arg[*i][0] == ';') {
        *i += 2;
        basic_ex(all);
        return 0;
    }
    return 1;
}

static int cond(all_t *all, char **arg, int *i)
{
    int ind = 0;

    if (arg[*i][0] == '>') {
        if (super_verif_redirect(arg, *i, all->sca) == 1) {
            *i += 2;
            ind = 1;
        } else {
            *i += 2;
            basic_ex(all);
        }
        if (arg[*i] == NULL)
            return 4;
        if (ind == 1)
            *i += 2;
        else
            *i += 2;
        return 0;
    }
    return cond_bis(all, arg, i);
}

void verif_prm_turn(all_t *all, char **arg)
{
    int i = 1;

    all->ext_ind = 1;
    while (1) {
        all->sca = my_strdup(arg[i - 1]);
        verif_redirect(all, arg, i);
        if (arg[i] == NULL) {
            basic_ex(all);
            break;
        }
        if (cond(all, arg, &i) == 4)
            break;
    }
    tbl_free_arg(arg, my_tablen(arg));
}

int verif_prm(all_t *all)
{
    char **arg = NULL;

    if (control_prm(all->sca) == 0) {
        arg = trie_split(all);
        free(all->sca);
        verif_prm_turn(all, arg);
        return 1;
    }
    return 0;
}

int my_shell_bis(all_t *all)
{
    while (true) {
        all->sca = my_scan(NULL, all->cp_std, 1);
        if (verif_prm(all) == 1)
            continue;
        all->ext_ind = 0;
        basic_ex(all);
    }
}

int my_shell(all_t *all)
{
    while (true) {
        all->sca = my_scan("$> ", all->cp_std, 0);
        if (verif_prm(all) == 1)
            continue;
        all->ext_ind = 0;
        basic_ex(all);
    }
    return 0;
}
