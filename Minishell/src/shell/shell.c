/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 15/02/24.
** File description:
** shell.c
*/

#include "../../includes/my.h"

static void cmd_not_found(char *cp)
{
    write(STDERR_FILENO, cp, my_strlen(cp));
    write(STDERR_FILENO, ": Command not found.\n", 21);
    exit(4);
}

static char *apply_cond(all_t *all)
{
    if (my_strcmp(all->arg[0], "env") == 0 && all->ptr_env == 0) {
        print_list(all->ls_env);
        exit(0);
    }
    return find_path_exist(all);
}

static void apply(all_t *all)
{
    struct stat info;
    char *cmd = NULL;

    built_in(all);
    cmd = apply_cond(all);
    if (cmd == NULL)
        cmd_not_found(all->arg[0]);
    if (my_strcmp(all->arg[0], cmd) != 0) {
        free(all->arg[0]);
        all->arg[0] = my_strdup(cmd);
    }
    lstat(all->arg[0], &info);
    if ((info.st_mode & S_IEXEC) && !S_ISDIR(info.st_mode)) {
        if (execve(all->arg[0], all->arg, all->env) && errno == ENOEXEC)
            write_arch_err(all);
        exit(EXIT_FAILURE);
    }
    write(STDERR_FILENO, all->arg[0], my_strlen(all->arg[0]));
    write(STDERR_FILENO, ": Permission denied.\n", 21);
    exit(EXIT_FAILURE);
}

int wait_child(all_t *all)
{
    int status;

    waitpid(all->child, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 4)
        return 2;
    if (WIFSIGNALED(status) && WCOREDUMP(status)) {
        write(STDERR_FILENO, "Segmentation fault (core dumped)\n", 33);
        return 84;
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
        write(STDERR_FILENO, "Segmentation fault\n", 19);
        return 84;
    }
    return 0;
}

int exebis(all_t *all, int i, int nbpipe, char **cp)
{
    int pipe_from[2];

    all->redirect_ind = 0;
    if (nbpipe > 1 || all->wind != 1)
        cond_one(all, cp, i, pipe_from);
    all->built_ind = 1;
    if (exit_fc(all) == 1)
        return 0;
    built_in(all);
    all->built_ind = 0;
    all->child = fork();
    if (all->child == 0) {
        if (cond_child(nbpipe, pipe_from, i, all) == 1)
            exit(0);
        apply(all);
    } else {
        return parent_fork(all, i, nbpipe, pipe_from);
    }
    return 1;
}

static int exe(all_t *all)
{
    int nbpipe = verif_pipe(all->arg);
    char **cp = NULL;
    int n = 0;
    int nb = all->nb;

    all->pipe = nbpipe;
    if (nbpipe > 1)
        cp = my_tab_dup(all->arg);
    for (int i = 0; i < nbpipe; i++) {
        n = exebis(all, i, nbpipe, cp);
        all->nb = nb;
        if (n == 0)
            continue;
        if (n == 84) {
            return cp_cond(cp, 84);
        } else
            return cp_cond(cp, 0);
    }
    return cp_cond(cp, 0);
}

static void exit_fc_bis(all_t *all)
{
    if (all->exi != 1) {
        my_putstr("exit\n");
        exit(desaloc(all));
    } else
        exit(desaloc(all));
}

int exit_fc(all_t *all)
{
    if (my_strcmp(all->arg[0], "exit") == 0 && all->ext_ind != 1) {
        if (all->arg[1] != NULL && all->arg[1][0] != '\0' &&
            IS_CHAR(all->arg[1][0]) == 0 && my_getnbr(all->arg[1]) == -1) {
            write(STDERR_FILENO, "exit: Expression Syntax.\n", 25);
            return 1;
        }
        if (all->arg[1] != NULL && all->arg[1][0] != '\0' &&
        my_getnbr(all->arg[1]) >= 0) {
            my_putstr("exit\n");
            all->rt = my_getnbr(all->arg[1]);
            exit(desaloc(all));
        } else
            exit_fc_bis(all);
    }
    if (my_strcmp(all->arg[0], "exit") != 0)
        return 0;
    return 1;
}

static int verif_sca(char *str)
{
    int len = my_strlen(str);
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count++;
    }
    if (count == len)
        return 1;
    return 0;
}

int info_trait(all_t *all)
{
    if (all->sca[0] == '\0' || all->sca == NULL || verif_sca(all->sca) == 1)
        return 0;
    if (all->sca != NULL && all->sca[0] != '\0' &&
    my_strlen(all->sca) == 1 && all->sca[0] == '|') {
        write(STDERR_FILENO, "Invalid null command.\n", 22);
        return 0;
    }
    if (all->arg != NULL)
        tbl_free_arg(all->arg, my_tablen(all->arg));
    count_args(all->sca, all);
    assign_path(all);
    return exe(all);
}
