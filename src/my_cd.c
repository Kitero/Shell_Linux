/*
** my_cd.c for my_cd in /home/Cisarius/delivery/PSU_2017_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Tue Jan  3 11:17:06 2017 Guillaume Balestreri
** Last update Sun May 21 14:59:17 2017 tudgwal
*/

#include "my.h"

char	*my_good_cd(char *line, int a, int b)
{
  char	*result;

  if ((result = malloc(my_point(line) + 2)) == NULL)
    return (NULL);
  while (line[a] == ' ' || line[a] == '\t')
    a = a + 1;
  result[b] = 'c';
  b = b + 1;
  result[b] = 'd';
  b = b + 1;
  result[b] = ' ';
  b = b + 1;
  a = a + 2;
  while (line[a] == ' ' || line[a] == '\t')
    a = a + 1;
  while (line[a] != ' ' && line[a] != '\t'
	 && line[a] != '\0' && line[a] != ';')
    {
      result[b] = line[a];
      a = a + 1;
      b = b + 1;
    }
  result[b] = '\0';
  return (result);
}

int	my_cd2(char *line2, char **env)
{
  char	buf[1024];

  if ((chdir(&line2[3]) == -1))
    {
      write(1, &line2[3], my_strlen(&line2[3]));
      write(1, ": Not a directory.\n", 19);
      return (1);
    }
  else
    {
      getcwd(buf, 1024);
      write(1, "Directory: ", 11);
      write(1, buf, my_strlen(buf));
      write(1, "\n", 1);
      env = my_pwd(buf, env);
      return (0);
    }
  return (1);
}

int	my_cd3(char *line, int a, char **env)
{
  char	*home;
  char	*oldpwd;
  int	i;

  i = 0;
  while ((line[a] != '\0' && line[a] == ' ')
  	 || (line[a] != '\0' && line[a] == '\t'))
    a = a + 1;
  line = my_good_cd(line, 0, 0);
  if (line[i] == 'c' && line[i + 1] == 'd' && line[i + 3] == '\0')
    {
      home = my_home(env);
      chdir(home);
      return (-1);
    }
  if (line[i] == 'c' && line[i + 1] == 'd'
      && line[i + 3] == '-' && line[i + 4] == '\0')
    {
      oldpwd = my_take_oldpwd(env);
      chdir(oldpwd);
      return (-1);
    }
  return (a);
}

int	re_cd(char *line, char *line2, char **env)
{
  int	a;
  int	i;

  if ((line2 = my_good_cd(line, 0, 0)) == NULL)
    return (0);
  i = my_cd2(line2, env);
  a = my_point(line);
  if (line[a] == ';')
    {
      while (line[a] == ';')
	a = a + 1;
      main2((&line[a]), env);
    }
  return (i);
}

int	my_cd(char *line, char **env)
{
  char	*line2;
  char	buf[1024];
  int	a;

  a = 0;
  if (line == NULL)
    return (0);
  while (line[a] == ' ' || line[a] == '\t')
    a = a + 1;
  if (line[a] != 'c' || line[a + 1] != 'd')
    return (2);
  if ((line2 = malloc(my_strlen(line))) == NULL)
    return (84);
  if ((a = my_cd3(line, 0, env)) == -1)
    {
      getcwd(buf, 1024);
      env = my_pwd(buf, env);
      return (0);
    }
  else if (strncmp(line, "cd", 2) == 0)
    return (re_cd(line, line2, env));
  return (2);
}
