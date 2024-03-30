/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 14/02/24.
** File description:
** built-in-cd.c
*/

#include "../../includes/my.h"

static char *set_wd(char *old)
{
    int s = 0;
    int index = 0;
    char *pwd = malloc(sizeof(char) * my_strlen(old) + 1);

    for (int i = 0; old[i] != '\0'; i++) {
        if (old[i] == '=') {
            s++;
            continue;
        }
        if (s != 0) {
            pwd[index] = old[i];
            index++;
        }
    }
    pwd[index] = '\0';
    return pwd;
}

static int modify_pwd(list_t **ls_env, all_t *all)
{
    list_t *tmp = *ls_env;
    char *pwd = malloc(sizeof(char) * 3200);

    chdir(all->arg[1]);
    while (tmp != NULL) {
        if (my_strncmp(tmp->path, "PWD", 3) == 0) {
            free(all->old_pwd);
            all->old_pwd = set_wd(tmp->path);
            free(tmp->path);
            getcwd(pwd, 3200);
            tmp->path = my_strcat("PWD=", pwd);
            free(pwd);
            return 0;
        }
        tmp = tmp->next;
    }
    free(pwd);
    return 1;
}

static char *find_home(list_t *ls_env)
{
    list_t *tmp = ls_env;

    while (tmp != NULL) {
        if (my_strncmp(tmp->path, "HOME", 4) == 0)
            return set_wd(tmp->path);
        tmp = tmp->next;
    }
    return NULL;
}

static int cd_home(all_t *all)
{
    char *tmp;

    if (all->nb == 1) {
        modify_pwd(&all->ls_env, all);
        tmp = find_home(all->ls_env);
        chdir(tmp);
        free(tmp);
        return 0;
    }
    return 1;
}

void print_err(char *buff)
{
    write(STDERR_FILENO, buff, my_strlen(buff));
    write(STDERR_FILENO, ": Not a directory.\n", 19);
    free(buff);
}

static int cd_stat(all_t *all, struct stat *info, char *buff)
{
    if (lstat(buff, info) != 0) {
        if (all->built_ind != 0) {
            write(STDERR_FILENO, buff, my_strlen(buff));
            write(STDERR_FILENO, ": No such file or directory.\n", 29);
        }
        free(buff);
        return 1;
    }
    if (!S_ISDIR(info->st_mode) && all->built_ind != 0)
        print_err(buff);
    return 0;
}

int cd_neg(all_t *all)
{
    if (all->nb == 2 && my_strcmp(all->arg[1], "-") == 0 &&
        all->old_pwd != NULL) {
        chdir(all->old_pwd);
        modify_pwd(&all->ls_env, all);
        return 0;
    }
    return 1;
}

int cd_neg_g(all_t *all)
{
    if (all->nb == 2 && my_strcmp(all->arg[1], "-") == 0 &&
        all->old_pwd == NULL) {
        if (all->built_ind != 0)
            write(STDERR_FILENO, ": No such file or directory.\n", 29);
        return 0;
    }
    return 1;
}

int cmd_cd_bis(all_t *all, char *buff, char *buff2, struct stat *info)
{
    if (all->arg[1][my_strlen(all->arg[1]) - 1] != '/') {
        buff = my_strcat(all->arg[1], "/");
        buff2 = my_strdup(all->arg[1]);
        free(all->arg[1]);
        all->arg[1] = my_strdup(buff);
        free(buff);
    }
    if (cd_stat(all, info, buff2) == 1)
        return 1;
    return 0;
}

int cmd_cd(all_t *all)
{
    struct stat info;
    char *buff = NULL;
    char *buff2 = NULL;

    if (cd_home(all) == 0)
        return 0;
    if (cd_neg(all) == 0)
        return 0;
    if (cd_neg_g(all) == 0) {
        return 0;
    } else {
        if (cmd_cd_bis(all, buff, buff2, &info) == 1)
            return 1;
        else
            return modify_pwd(&all->ls_env, all);
    }
    return 0;
}
