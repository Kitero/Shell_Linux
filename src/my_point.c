/*
** my_point.c for my_point in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 12:22:57 2017 Guillaume Balestreri
** Last update Fri May 19 18:49:39 2017 Guillaume Balestreri
*/

#include "my.h"

int     my_point(char *line)
{
  int   i;

  i = 0;
  while (line[i] != '\0')
    {
      i = i + 1;
      if (line[i] == ';')
	return (i);
    }
  return (i);
}

char    *my_short(char *line)
{
  int   a;
  char  *result;

  a = 0;
  if ((result = malloc(my_strlen(line))) == NULL)
    return (NULL);
  while (line[a] != ' ' && line[a] != '\0' && line[a] != ';')
    {
      result[a] = line[a];
      a = a + 1;
    }
  result[a] = '\0';
  return (result);
}

char    *my_cut_point(char *line)
{
  int   a;
  char  *result;

  a = 0;
  if ((result = malloc((my_strlen(line) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (line[a] != '\0' && line[a] != ';')
    {
      result[a] = line[a];
      a = a + 1;
    }
  result[a] = '\0';
  return (result);
}

void    my_signal()
{
  char  **env;

  env = NULL;
  write(1, "\n", 1);
  my_prompt(env);
  return ;
}

int    main2(char *line, char **env)
{
  int	i;

  while ((my_separator(line, env)) != 2)
    line = my_cut_separator(line);
  if (line != NULL && line[0] != '\0' && (my_check_env(line)) != 0)
    {
      env = my_mod_env(my_cut_point(line), env, my_check_env(line), &i);
      if (env == NULL)
	return (1);
      while (line[i] != '\0' && line[i] != ';')
	i = i + 1;
      i = main2(&line[i], env);
      line = NULL;
    }
  if (line != NULL)
    i = my_cd(line, env);
  if (line != NULL && line[0] != '\0' && i == 2)
    i = my_check(line, env);
  if (i == -1 && line == NULL)
    return (1);
  return (i);
}

int     my_strlen_space(char *line)
{
  int   i;

  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
    i = i + 1;
  return (i);
}
