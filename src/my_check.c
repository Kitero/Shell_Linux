/*
** my_check.c for my_check in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 12:27:59 2017 Guillaume Balestreri
** Last update Fri Jun  9 15:50:05 2017 Theo Clement
*/

#include "my.h"

int		my_count_path(char **env)
{
  int	b;
  int	i;

  i = 0;
  b = 0;
  while (env[b] != NULL && (env[b][0] != 'P' || env[b][1] != 'A'
	|| env[b][2] != 'T' || env[b][3] != 'H' || env[b][4] != '='))
    {
      b = b + 1;
    }
  while (env[b] != NULL && env[b][i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_clean2(char *line, char *result, int a, int b)
{
  while (line[a] != '\0')
    {
      while (line[a] != '\0' && line[a] != ' ' && line[a] != '\t')
	{
	  result[b] = line[a];
	  b = b + 1;
	  a = a + 1;
	}
      if (line[a] == ' ' || line[a] == '\t')
	{
	  result[b] = ' ';
	  b = b + 1;
	}
      while (line[a] == ' ' || line[a] == '\t')
	{
	  a = a + 1;
	  if (line[a] == ';')
	    result[b - 1] = ';';
	}
    }
  result[b] = '\0';
  return (result);
}

char    *my_clean(char *line)
{
  int   a;
  int   b;
  char  *result;

  a = 0;
  b = 0;
  if ((result = malloc(my_strlen(line) + 1)) == NULL)
    return (NULL);
  while (line[a] != '\0' && (line[a] == ' ' || line[a] == '\t'))
    a = a + 1;
  result = my_clean2(line, result, a, b);
  return (result);
}

void	my_check2(char *line, char *path, char **env)
{
  int	a;
  char	**av;

  a = 1;
  if (line[0] == '/' || line[0] == '.')
    path = my_short(line);
  else
    path = fusion((my_path(env, path, a)), line, 0);
  av = my_cut(line, 0, 0, 0);
  while (path != NULL && (access(path, F_OK)) != 0)
    {
      printf("TEST AVEC : %s\n", path);
      a = a + 1;
      if (access(path, F_OK) == 0)
	execve(path, av, env);
      path = my_path(env, path, a);
      path = (fusion(path, line, 0));
    }
  my_error(line, path);
  free(path);
  exit(1);
}

int		my_check(char *line, char **env)
{
  int           status;
  pid_t         pid;

  if ((fct_echo(line)) == 2)
    return (0);
  pid = 0;
  status = 0;
  line = my_clean(line);
  if ((my_check_pipe(line)))
    return (my_pipe(line, env, pid));
  if ((pid = fork()))
    return ((my_pid1(line, status, env)));
  else
    my_exec(line, env);
  return (0);
}
