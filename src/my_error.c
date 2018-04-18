/*
** my_error.c for my_error in /home/Cisarius/delivery/PSU_2016_minishell2
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Apr  9 19:54:23 2017 Guillaume Balestreri
** Last update Fri Jun  9 15:46:07 2017 Theo Clement
*/

#include "my.h"

void    my_error(char *line, char *path)
{
  if (open(line, O_RDONLY) == -1)
    {
      write(2, line, my_strlen_space(line));
      write(2, ": Command not found.\n", 21);
    }
  else if ((access(path, X_OK)) == -1)
    {
      write(2, line, my_strlen_space(line));
      write(2, ": Permission denied.\n", 21);
    }
  else
    perror(NULL);
}

char    **malloc_av(char **av, int a, int b, char *line)
{
  if (line[a + 1] != ';')
    if ((av[b] = malloc(my_strlen(line))) == NULL)
      return (NULL);
  return (av);
}

int     my_pid1(char *line, int status, char **env)
{
  int   a;

  wait(&status);
  if (status == 139)
    {
      write (1, "Segmentation fault", 18);
      if (WCOREDUMP(status))
	write (1, " (core dumped)", 14);
      write (1, "\n", 1);
    }
  else if (status != 0)
    status = 1;
  a = my_point(line);
  if (line[a] == ';')
    {
      while (line[a] == ';')
	a = a + 1;
      status = main2((&line[a]), env);
      a = my_point(&line[a]);
    }
  return (status);
}
