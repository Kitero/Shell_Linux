/*
** my_new_env.c for my_new_env in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 18:03:26 2017 Guillaume Balestreri
** Last update Sun May 21 15:01:47 2017 Guillaume Balestreri
*/

#include "my.h"

int	my_check_setenv2(char *line, int a)
{
  a = 0;
  if (line[a] == ' ')
    {
      a = a + 1;
      while (line[a] != '\0')
	{
	  if (line[a] == ' ')
	    {
	      write(2, "setenv: Too many arguments\n", 27);
	      return (1);
	    }
	  a = a + 1;
	}
    }
  return (0);
}

int     my_check_setenv(char *line, char **env)
{
  int   a;

  a = 7;
  while (line[a] != ' ' && line[a] != '\0')
    {
      if (line[a] < '1' || (line[a] < 'A' && line[a] > '9')
	  || (line[a] < 'a' && line[a] > 'Z'
	      && line[a] != '_') || line[a] > 'z')
	{
	  write(2, "setenv: Variable name must ", 27);
	  write(2, "contain alphanumeric characters.\n", 33);
	  return (1);
	}
      a = a + 1;
    }
  if (a == 7 || a == 8)
    {
      fct_env(env);
      return (1);
    }
  return (my_check_setenv2(line, a));
}

char	**my_new_env2(char *line, char **env, int i, int a)
{
  int	j;

  j = 0;
  while (line[a] != '\0' && line[a] != ' ')
    {
      env[i][j] = line[a];
      a = a + 1;
      j = j + 1;
    }
  env[i][j] = '=';
  j = j + 1;
  while (line[a] != '\0')
    {
      while (line[a] == ' ')
	a = a + 1;
      env[i][j] = line[a];
      j = j + 1;
      a = a + 1;
    }
  env[i][j] = '\0';
   return (env);
}

char    **my_new_env(char *line, char **env)
{
  int   i;
  int   a;
  char	**new_env;

  i = 0;
  a = 7;
  if ((new_env = my_cp_env(env, 2, &i, 0)) == NULL)
    return (NULL);
  free_tab_char(env, 0);
  while (line[a] != '\0')
    a = a + 1;
  if ((new_env[i] = malloc(a + 1)) == NULL)
    return (NULL);
  a = 7;
  new_env = (my_new_env2(line, new_env, i, a));
  new_env[i + 1] = NULL;
  return (new_env);
}

char	**my_modif_env(char **env, int i, char *line)
{
  int	j;

  j = 0;
  while (line[j] != 0)
    j++;
  free(env[i]);
  if ((env[i] = malloc((j - 6))) == NULL)
    return (NULL);
  j = 7;
  return (my_new_env2(line, env, i, j));
}
