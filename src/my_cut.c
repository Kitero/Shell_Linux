/*
** my_cut.c for my_cut in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 11:10:23 2017 Guillaume Balestreri
** Last update Fri May 19 14:53:42 2017 tudgwal
*/

#include "my.h"

char	**my_cut2(char **av, int b, int c)
{
  av[b][c] = '\0';
  b = b + 1;
  av[b] = NULL;
  if (b == 0 && c == 0)
    return (NULL);
  return (av);
}

char    **my_cut(char *line, int a, int b, int c)
{
  char  **av;

  if ((av = malloc(sizeof(char *) * (my_strlen(line) + 1))) == NULL ||
      (av[b] = malloc(my_strlen(line) + 1)) == NULL)
    return (NULL);
  while (line[a] != '\0' && line[a] != ';'
	 && line[a + 1] != '\0' && line[a] != '|')
    {
      while (line[a] != '\0' && line[a] != ' '
	     && line[a] != ';' && line[a] != '|')
	{
	  av[b][c] = line[a];
	  a = a + 1;
	  c = c + 1;
	}
      if (line[a] == ' ' && line[a + 1] != '\0' && line[a + 1] != '|')
	{
	  a = a + 1;
	  av[b][c] = '\0';
	  c = 0;
	  b = b + 1;
	  av = malloc_av(av, a, b, line);
	}
    }
  return (my_cut2(av, b, c));
}

char	*my_path2(char **env, char *path, int b)
{
  int	c;
  int	d;

  c = 0;
  d = 0;
  while (env[b][c] != '=')
    c = c + 1;
  c = c + 1;
  while (env[b][c] != ':')
    {
      path[d] = env[b][c];
      d = d + 1;
      c = c + 1;
    }
  path[d] = '\0';
  return (path);
}

char		*my_path3(char **env, char *path, int b, int a)
{
  int	c;
  int	e;
  int	d;

  c = 0;
  e = 0;
  d = 0;
  while ((d + 1) != a)
    {
      while (env[b][c] != ':' && env[b][c] != '\0')
	c = c + 1;
      if (env[b][c] == '\0' || env[b][c + 1] == '\0')
	return (NULL);
      d = d + 1;
      c = c + 1;
    }
  while (env[b][c] != ':' && env[b][c] != '\0')
    {
      path[e] = env[b][c];
      e = e + 1;
      c = c + 1;
    }
  path[e] = '\0';
  return (path);
}

char            *my_path(char **env, char *path, int a)
{
  int           b;

  b = 0;
  a = a + 1;
  if (env == NULL)
    return (NULL);
  while (env[b] != '\0' && (env[b][0] != 'P' || env[b][1] != 'A'
	|| env[b][2] != 'T' || env[b][3] != 'H' || env[b][4] != '='))
    b = b + 1;
  if (env[b] == '\0')
    return (NULL);
  if (a == 1)
    return (my_path2(env, path, b));
  else
    path = my_path3(env, path, b, a);
  return (path);
}
