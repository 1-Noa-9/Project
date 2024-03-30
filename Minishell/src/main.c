/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** main.c
*/

#include "../includes/my.h"

static void initialize(all_t *all, char **env)
{
    all->father = getpid();
    all->child = 1;
    all->sca = NULL;
    all->arg = NULL;
    all->env = env;
    all->pat = NULL;
    all->cmd = NULL;
    all->ls_env = NULL;
    all->nb = 0;
    all->ptr_env = 0;
    all->rt = 0;
    all->nl = 0;
    all->exi = 0;
    get_path_env(all);
    set_env_list(all);
    all->old_pwd = NULL;
    all->cp_std = dup(STDIN_FILENO);
    all->wind = 1;
    all->redirect_ind = 0;
    all->pipe = 0;
}

int main(int ac, char **av, char **env)
{
    all_t *all = malloc(sizeof(all_t));

    (void)av;
    if (ac != 1)
        return 84;
    initialize(all, env);
    all->built_ind = 0;
    all->ext_ind = 0;
    if (isatty(0) == 0) {
        all->exi = 1;
        my_shell_bis(all);
        return desaloc(all);
    }
    my_shell(all);
    desaloc(all);
    return 0;
}
