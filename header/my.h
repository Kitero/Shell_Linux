/*
** my.h for my.h in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Thu Jan  5 12:41:01 2017 Guillaume Balestreri
** Last update Sun May 21 15:09:09 2017 Guillaume Balestreri
*/

#ifndef MY_H_
# define MY_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.h"

void	check_perm_exec(char *, char **, char **, char *);
void	my_error(char *, char *);
void	disp_error_cut(char *);
void	my_show(char *, char **);
void	my_prompt();
void	my_check2(char *, char *, char **);
void	my_signal();
void	free_tab_char(char **, int);
void	my_exec(char *, char **);
void	my_putstr(char *);
int	check_perm(char *);
int	shorten_loop(char *, char ***, int *);
int	my_separator(char *, char **);
int	my_get_c(char *, int);
int	my_separator(char *, char **);
int	my_cd(char *, char **);
int	my_check_pipe(char *);
int	my_pipe(char *, char **, pid_t);
int	my_point(char *);
int	my_free_env(char **, int);
int	my_check_env(char *);
int	my_pid1(char *, int, char **);
int	my_check_setenv(char *, char **);
int	cmp(char *, char *);
int	my_strlen(char *);
int	main2(char *, char **);
int	my_strlen_space(char *);
int	my_check(char *, char **);
int	fct_env(char **);
int	fct_echo(char *);
char	*my_cut_separator(char *);
char	*strcopy(char *, char *);
char	*my_re_alloc(char *, int);
char	*my_clean(char *);
char	*my_path(char **, char *, int);
char	*alloc_str(char *);
char	*my_take_oldpwd(char **);
char	*my_home(char **);
char	*get_next_line2(const int, int, char *, char *);
char	*get_next_line(const int);
char	*fusion(char *, char *, int);
char	*my_short(char *);
char	*my_strcat(char *, char *);
char	*alloc_to(char *, char);
char    *create_good_cmd(char *);
char    *create_good_cmd(char *);
char	*my_cut_separator(char *);
char	**my_setenv(char *, char **, int, int);
char	**my_mod_env(char *, char **, int, int *);
char	**my_modif_env(char **, int, char *);
char	**my_new_env(char *, char **);
char	**my_cut(char *, int, int, int);
char	**my_cp_env(char **, int, int *, int);
char	**malloc_av(char **, int, int, char *);
char	**my_pwd(char *, char **);
char	**my_unsetenv(char *, char **);
char	**str_to_tab(char *, char);
char	**get_path(char **);
char	**str_to_tab_exec(char *, char);
char	**create_basic_env(char **);
char 	**my_oldpwd(char **, int, int, int);
char	**check_null_value(char **);

#endif
