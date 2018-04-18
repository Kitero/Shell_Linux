/*
** mod_env.c for mod_env in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Fri Jan 20 12:02:35 2017 Guillaume Balestreri
** Last update Sun May 21 14:54:20 2017 Guillaume Balestreri
*/

#include "my.h"

char	**my_setenv(char *line, char **env, int i, int j)
{
  int	a;

  a = 7;
  if (my_check_setenv(line, env) == 1)
    return (NULL);
  while (env[i] != NULL)
    {
      while (env[i][j] != '=' && env[i][j] == line[a])
	{
	  j = j + 1;
	  a = a + 1;
	}
      if ((line[a] == '\0' && env[i][j] == '=')
	  || (env[i][j] == '=' && line[a] == ' '))
	{
	  env = my_modif_env(env, i, line);
	  return (env);
	}
      a = 7;
      i = i + 1;
      j = 0;
    }
  env = my_new_env(line, env);
  return (env);
}

char	**my_mod_env(char *line, char **env, int i, int *returned)
{
  int	a;
  char	**tmp;

  tmp = NULL;
  line = my_clean(line);
  if (i == 1)
    my_show(line, env);
  else if (i == 2)
    tmp = my_setenv(line, env, 0, 0);
  else if (i == 3)
    tmp = my_unsetenv(line, env);
  a = my_point(line);
  if (line[a] == ';')
    {
      while (line[a] == ';')
	a = a + 1;
      main2((&line[a]), env);
      a = my_point(&line[a]);
    }
  if (tmp != NULL)
    return (tmp);
  *returned = 1;
  return (env);
}
