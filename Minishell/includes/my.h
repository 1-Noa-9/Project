/*
** EPITECH PROJECT, 2024
** Created by noa.vanhamme@epitech.eu on 12/02/24.
** File description:
** my.h
*/

#pragma once

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define IS_CHAR(c) (c <= '/' && c >= ':')

/* Linked list */
typedef struct list_a {
    char *path;
    struct list_a *next;
} list_t;

/* Structure */
typedef struct all_s {
    int cp_std;
    pid_t father;
    pid_t child;
    char *sca;
    char **arg;
    char **env;
    int ptr_env;
    int nb;
    int nl;
    char *old_pwd;
    char *cmd;
    int rt;
    int exi;
    int wind;
    int pipe;
    int redirect_ind;
    int built_ind;
    int ext_ind;
    list_t *ls_env;
    list_t *pat;
} all_t;

// BASICS FUNCTION

/* Print function */
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char *str);

/* Duplicate function */
char *my_strdup(char *src);
char *my_strcat(char *dest, char *src);

/* Compare function */
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strnrevcmp(char const *s1, char const *s2, int n);

/* Count function */
int my_strlen(char const *str);

/* Scan function */
char *my_scan(char *str, int index, int tty);

/* Get number */
int my_getnbr(char const *str);

/* 2D array len */
int my_tablen(char **tab);

/* 2D array dup */
char **my_tab_dup(char **tab);

// LINKED LIST FUNCTION

/* New node function */
list_t *new_nod(char *value);
void push_front(list_t **head, char *value);
void push_to_back(list_t **head, list_t *new);

/* Delete node function */
int delete_in_list(list_t **begin, char *ref);

/* Free node function */
void ls_free(list_t *list);

/* Print node function */
void print_list(list_t *list);

// BUILT_IN FUNCTION

/* Built "cd" */
int cmd_cd(all_t *all);

/* Built "setenv" */
int my_setenv(all_t *all);

/* Built "unsetenv" */
int my_unset_env(all_t *all);

// FREE FUNCTION

/* Principal function */
int desaloc(all_t *all);

/* Free 2D array function */
void tbl_free_arg(char **tbl, int n);

// SHELL FUNCTION

/* Count argument input */
int count_args(char *str, all_t *all);

/* Assign argument in 2D array */
char **assign_arg(char *str, int nb);

/* Get Binari PATH */
void get_path_env(all_t *all);
void assign_path(all_t *all);
void set_env_list(all_t *all);
char *find_path_exist(all_t *all);

/* Len of environement variable */
int my_strlen_env(char *str);

/* Shell function */
int info_trait(all_t *all);
int my_shell(all_t *all);

/* Shell function bis */
int my_shell_bis(all_t *all);

void find_path_in_env_list(all_t *all);
char **trie_split(all_t *all);
char *my_caloc(int size);
void basic_ex(all_t *all);
int control_prm(char *str);

void cond_parent_one(int nbpipe, int *pipe_from, int i, all_t *all);
int cond_child(int nbpipe, int *pipe_from, int i, all_t *all);
void cond_one(all_t *all, char **cp, int i, int *pipe_from);
char **get_pipe_arg(char **tab, int turn);
int get_pipe_start(char **tab, int turn);
int my_pipe_len(char **tab, int st);
int verif_pipe(char **arg);
int control_prm(char *str);
void basic_ex(all_t *all);
int cond_parent_two(int nbpipe, int *pipe_from, all_t *all);
int built_in(all_t *all);
int wait_child(all_t *all);
int cp_cond(char **cp, int inde);
void write_arch_err(all_t *all);
int parent_fork(all_t *all, int i, int nbpipe, int *pipe_from);
void write_redirect_err(char *cmd);
int exit_fc(all_t *all);
