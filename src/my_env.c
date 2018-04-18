/*
** my_env.c for my_env in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 17:46:04 2017 Guillaume Balestreri
** Last update Fri May 19 12:07:39 2017 Theo Clement
*/

#include "my.h"

char	**my_cp_env(char **env, int a, int *i, int j)
{
  char	**new_env;

  while (env[*i] != NULL)
    *i = *i+ 1;
  if ((new_env = malloc(sizeof(char *) * (*i + a))) == NULL)
    return (NULL);
  *i = 0;
  while (env[*i] != NULL)
    {
      if ((new_env[*i] = malloc(my_strlen(env[*i]) + 1)) == NULL)
	return (NULL);
      while (env[*i][j] != '\0')
	{
	  new_env[*i][j] = env[*i][j];
	  j = j + 1;
	}
      new_env[*i][j] = '\0';
      j = 0;
      *i = *i+ 1;
    }
  new_env[*i] = NULL;
  return (new_env);
}

int	my_check_env2(char *comp, char *line, int i)
{
  comp = "setenv\0";
  while (comp[i] == line[i])
    {
      i = i + 1;
      if (comp[i] == '\0')
	return (2);
    }
  i = 0;
  comp = "unsetenv\0";
  while (comp[i] == line[i])
    {
      i = i + 1;
      if (comp[i] == '\0')
	return (3);
    }
  return (0);
}

int     my_check_env(char *line)
{
  int   i;
  char  *comp;

  i = 0;
  if ((comp = malloc(10)) == NULL)
    return (0);
  comp = "env\0";
  line = my_clean(line);
  while (comp[i] == line[i])
    {
      i = i + 1;
      if (comp[i] == '\0')
	return (1);
    }
  return (my_check_env2(comp, line, 0));
}

void    my_show(char *line, char **env)
{
  int   a;

  a = 3;
  while (line[a] != '\0' && line[a] != ';')
    {
      if (line[a] != ' ' && line[a] != '\t')
	{
	  my_check(line, env);
	  return ;
	}
      a = a + 1;
    }
  a = 0;
  while (env[a] != NULL)
    {
      if (env[a][0] != '\0')
	{
	  write(1, env[a], my_strlen(env[a]));
	  write(1, "\n", 1);
	}
      a = a + 1;
    }
}
