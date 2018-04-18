/*
** my_unsetenv.c for  in /home/tudgwal/delivery/PSU_2016_42sh/src
** 
** Made by tudgwal
** Login   <tudgwal@epitech.net>
** 
** Started on  Wed May 17 14:16:54 2017 tudgwal
** Last update Sun May 21 13:47:38 2017 tudgwal
*/

#include "my.h"

char    **fct_parstr(char **av, char *s, int nbr)
{
  int   i;
  int   j;
  int   k;
  int   l;

  i = 0;
  j = 0;
  k = 0;
  l = 0;
  while (i < nbr)
    {
      while (s[k + 1] != ' ' && s[k + 1] != 0)
	k++;
      if ((av[i] = malloc(sizeof(char) * (k + 2 - j))) == NULL)
	return (NULL);
      while (j < k + 1)
	av[i][l++] = s[j++];
      av[i][l] = 0;
      i++;
      j++;
      k++;
      l = 0;
    }
  av[i] = NULL;
  return (av);
}

int     count_env(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    i++;
  return (i);
}

char    **fct_str(char *s, char **str)
{
  int	i;
  int   j;

  i = 0;
  j = 1;
  while (s[i++] != 0)
    {
      if (s[i] == ' ' && s[i + 1] != ' ')
	j++;
    }
  if ((str = malloc(sizeof(char *) * (j + 1))) == NULL)
    return (NULL);
  str = fct_parstr(str, s, j);
  return (str);
}

char    **fct_unenvx(char **env, int j)
{
  if (j == -1)
    return (env);
  if (env[j + 1] != NULL)
    {
      while (env[j++] != NULL)
	env[j] = env[j + 1];
    }
  else
    env[j] = NULL;
  return (env);
}

char	**my_unsetenv(char *line, char **env)
{
  int   i;
  int   j;
  char  **str;

  i = 0;
  j = -1;
  str = NULL;
  str = fct_str(line, str);
  if (count_env(str) != 2)
    {
      write(1, "unsetenv: Too few arguments.", 31);
      return (env);
    }
  while (env[i] != NULL)
    {
      if (strncmp(str[1], env[i], (strlen(str[1]) - 1)) == 0)
	j = i;
      i++;
    }
  env = fct_unenvx(env, j);
  return (env);
}
