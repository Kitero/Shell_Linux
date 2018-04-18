/*
** main.c for main in /home/Cisarius/delivery/PSU_2017_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Tue Jan  3 10:41:57 2017 Guillaume Balestreri
** Last update Fri May 19 12:14:41 2017 tudgwal
*/

#include "my.h"

char	*fusion(char *path, char *line, int b)
{
  int	a;
  char	*path2;

  if (path == NULL ||
      (path2 = malloc((my_strlen(path) + my_strlen(line) + 2))) == NULL)
    return (NULL);
  while (path[b] != '\0')
    {
      path2[b] = path[b];
      b = b + 1;
    }
  path2[b] = '/';
  b = b + 1;
  a = 0;
  while (line[a] == ' ' || line[a] == '\t')
    a = a + 1;
  while (line[a] != ' ' && line[a] != '\0'
	 && line[a] != '\t' && line[a] != ';')
    {
      path2[b] = line[a];
      a = a + 1;
      b = b + 1;
    }
  path2[b] = '\0';
  return (path2);
}

int	my_free_env(char **env, int i)
{
  int	j;

  j = 0;
  while (env[j] != NULL)
    {
      free(env[j]);
      j = j + 1;
    }
  free(env);
  if (i == 2)
    return (0);
  return (i);
}

int	my_main3(char *line, char **env)
{
  int	i;

  i = 0;
  while (cmp(line, "exit") != 0)
    {
      signal(SIGINT, my_signal);
      if (shorten_loop(line, &env, &i))
	return (1);
      my_prompt(env);
      if ((line = get_next_line(0)) == NULL)
	line = "exit\0";
      else
	i = 0;
    }
  return (my_free_env(env, i));
}

int	my_main4(char *line, char **new_env, int i)
{
  line = get_next_line(0);
  while (line != NULL)
    {
      if (shorten_loop(line, &new_env, &i))
	return (1);
      line = get_next_line(0);
    }
  return (my_free_env(new_env, i));
}

int     main(int ac, char __attribute__((unused)) **av, char **env)
{
  char  *line;
  char	**new_env;
  int	i;

  i = 0;
  if (ac < 1)
    return (84);
  line = NULL;
  if ((new_env = my_cp_env(env, 1, &i, 0)) == NULL)
    return (-1);
  if (new_env[0] == NULL)
    new_env = create_basic_env(new_env);
  if ((isatty(0)) == 1)
    i = my_main3(line, new_env);
  else
    i = my_main4(line, new_env, i);
  return (i);
}
