/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 20/03/24.
** File description:
** all.c
*/

#include "../../includes/my.h"

struct opt {
    int i;
    char *cp;
    char *buffer;
};

int count_pr(char *str, char *delim)
{
    char *cp = my_strdup(str);
    char *token = strtok(cp, delim);
    int nb = 0;

    while (token != NULL) {
        nb++;
        token = strtok(NULL, delim);
    }
    free(cp);
    return nb;
}

static void assign_prm_arg(int *index, char **arg, char cp)
{
    int ind = *index;

    arg[ind] = malloc(sizeof(char) * 2);
    arg[ind][0] = cp;
    arg[ind][1] = '\0';
    *index += 1;
}

static void assign_prm_arg2(int *index, char **arg, char cp, char cp2)
{
    int ind = *index;

    arg[ind] = malloc(sizeof(char) * 3);
    arg[ind][0] = cp;
    arg[ind][1] = cp2;
    arg[ind][2] = '\0';
    *index += 1;
}

static void assign_arg_in_tab(int *index, char **arg, char *buffer, int *ind)
{
    arg[*index] = my_strdup(buffer);
    *ind = 0;
    *index += 1;
    free(buffer);
}

static int cond(int *index, int *ind, char **arg, struct opt *opti)
{
    if (opti->cp[opti->i + 1] != '\0' && ((opti->cp[opti->i] == '>' &&
    opti->cp[opti->i + 1] == '>'))) {
        assign_arg_in_tab(index, arg, opti->buffer, ind);
        assign_prm_arg2(index, arg, opti->cp[opti->i], opti->cp[opti->i + 1]);
        opti->i++;
        opti->buffer = my_caloc(my_strlen(opti->cp) + 1);
        return 1;
    }
    if (opti->cp[opti->i] == ';' || opti->cp[opti->i] == '>') {
        assign_arg_in_tab(index, arg, opti->buffer, ind);
        assign_prm_arg(index, arg, opti->cp[opti->i]);
        opti->buffer = my_caloc(my_strlen(opti->cp) + 1);
        return 1;
    }
    return 0;
}

static void trie_turn(char *cp, char **arg, int *index)
{
    int ind = 0;
    struct opt opti;

    opti.buffer = my_caloc(my_strlen(cp) + 1);
    opti.i = 0;
    opti.cp = cp;
    for (int i = 0; cp[i] != '\0'; i++) {
        if (i > 0 && cp[i] == ' ' && (cp[i - 1] == ';' || cp[i - 1] == '>'))
            continue;
        opti.i = i;
        if (cond(index, &ind, arg, &opti) == 1) {
            i = opti.i;
            continue;
        }
        opti.buffer[ind] = cp[i];
        ind++;
    }
    assign_arg_in_tab(index, arg, opti.buffer, &ind);
    arg[*index] = NULL;
}

void verfi_space(char **arg)
{
    int j = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        for (j = 0; arg[i][j] != '\0'; j++);
        if (arg[i][j - 1] == ' ')
            arg[i][j - 1] = '\0';
    }
}

char **trie_split(all_t *all)
{
    int nb = count_pr(all->sca, ";|<>\0");
    char *cp = my_strdup(all->sca);
    char **arg = malloc(sizeof(char *) * (nb * 2));
    int index = 0;

    trie_turn(cp, arg, &index);
    verfi_space(arg);
    free(cp);
    return arg;
}
