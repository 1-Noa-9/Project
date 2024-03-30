/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 14/02/24.
** File description:
** find_path.c
*/

#include "../../../includes/my.h"

static int get_n(all_t *all)
{
    int i = 0;

    for (i = 0; all->env[i] != NULL; i++) {
        if (my_strncmp(all->env[i], "PATH", 4) == 0)
            break;
    }
    return i;
}

static char *clean_path(char *line)
{
    int len = my_strlen(line);
    char *str = malloc(sizeof(char) * len + 1);
    int index = 0;

    for (int i = 0; i < len; i++)
        str[i] = '\0';
    for (int i = 5; i < len; i++) {
        str[index] = line[i];
        index++;
    }
    free(line);
    return str;
}

static void take_tok(all_t *all, char *line)
{
    char *token;

    if (line == NULL) {
        all->ptr_env = 1;
        return;
    }
    if (my_strlen(line) <= 5)
        all->ptr_env = 1;
    else
        all->ptr_env = 0;
    line = clean_path(line);
    token = strtok(line, ":");
    while (token != NULL) {
        if (all->pat == NULL)
            push_front(&all->pat, token);
        else
            push_to_back(&all->pat, new_nod(token));
        token = strtok(NULL, ":");
    }
    free(line);
}

void find_path_in_env_list(all_t *all)
{
    char *line = NULL;
    list_t *tmp = all->ls_env;

    while (tmp != NULL) {
        if (my_strncmp(tmp->path, "PATH", 4) == 0) {
            line = my_strdup(tmp->path);
            break;
        }
        tmp = tmp->next;
    }
    take_tok(all, line);
}

void get_path_env(all_t *all)
{
    int i = get_n(all);
    int j = my_strlen(all->env[i]);
    char *line = malloc(sizeof(char) * j);
    char *token;

    j = 0;
    for (int b = 5; all->env[i][b] != '\0'; b++) {
        line[j] = all->env[i][b];
        j++;
    }
    line[j] = '\0';
    token = strtok(line, ":");
    while (token != NULL) {
        if (all->pat == NULL)
            push_front(&all->pat, token);
        else
            push_to_back(&all->pat, new_nod(token));
        token = strtok(NULL, ":");
    }
    free(line);
}

char *find_path_exist(all_t *all)
{
    list_t *temp = all->pat;
    char *cp = NULL;
    char *cmd = my_strcat("/", all->arg[0]);

    while (temp != NULL) {
        cp = my_strcat(temp->path, cmd);
        if (access(cp, X_OK) == 0) {
            free(cmd);
            return my_strdup(cp);
        }
        free(cp);
        temp = temp->next;
    }
    free(cmd);
    if (access(all->arg[0], X_OK) == 0)
        return all->arg[0];
    return NULL;
}

void set_env_list(all_t *all)
{
    for (int i = 0; all->env[i] != NULL; i++) {
        if (all->ls_env == NULL)
            push_front(&all->ls_env, all->env[i]);
        else
            push_to_back(&all->ls_env, new_nod(all->env[i]));
    }
}
