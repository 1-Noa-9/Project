/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 13/02/24.
** File description:
** env.c
*/

#include "../../includes/my.h"

static char *set_two(char *value)
{
    int i = 0;
    char *tmp = NULL;

    for (; value[i] != '\0'; i++) {
        if (value[i] == '=')
            return value;
    }
    tmp = my_strcat(value, "=");
    return tmp;
}

static char *set_three(char *s1, char *s2)
{
    int i = 0;
    char *tmp = NULL;
    char *tmp2 = NULL;

    for (; s1[i] != '\0'; i++) {
        if (s1[i] == '=') {
            tmp = my_strcat(s1, s2);
            return tmp;
        }
    }
    tmp = my_strcat(s1, "=");
    tmp2 = my_strcat(tmp, s2);
    free(tmp);
    return tmp2;
}

char *set(all_t *all)
{
    if (all->nb == 2)
        return set_two(all->arg[1]);
    if (all->nb == 3)
        return set_three(all->arg[1], all->arg[2]);
    return NULL;
}

int my_strlen_env(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '=')
            break;
    return i;
}

list_t *new_nod_bis(all_t *all)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->next = NULL;
    new_node->path = set(all);
    return new_node;
}

static void update_path(all_t *all)
{
    if ((all->nb == 2 || all->nb == 3) &&
        my_strncmp(all->arg[1], "PATH", 4) == 0) {
        ls_free(all->pat);
        all->pat = NULL;
        find_path_in_env_list(all);
    }
}

int set_env_bis(all_t *all, list_t **ls_env)
{
    list_t *tmp = *ls_env;

    while (tmp != NULL) {
        if (my_strncmp(tmp->path, all->arg[1], my_strlen_env(all->arg[1]))
            == 0) {
            free(tmp->path);
            tmp->path = set(all);
            update_path(all);
            return 0;
        }
        tmp = tmp->next;
    }
    push_to_back(&all->ls_env, new_nod_bis(all));
    update_path(all);
    return 1;
}

static int alpha_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] <= 'z' && str[i] >= 'a') ||
            (str[i] <= 'Z' && str[i] >= 'A') ||
            (str[i] <= '9' && str[i] >= '0') || str[i] == '_')
            continue;
        else
            return 1;
    }
    return 0;
}

int my_setenv(all_t *all)
{
    if (all->nb == 1) {
        if (all->built_ind != 1)
            print_list(all->ls_env);
        return 1;
    }
    if (all->nb > 3) {
        if (all->built_ind != 0)
            write(STDERR_FILENO, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    if (alpha_num(all->arg[1]) == 1) {
        if (all->built_ind != 0) {
            write(2, "setenv: Variable name ", 22);
            write(2, "must contain alphanumeric characters.\n", 38);
        }
        return 1;
    }
    set_env_bis(all, &all->ls_env);
    return 0;
}
