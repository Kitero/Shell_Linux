/*
** my_check_perm.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Sat May 20 12:55:50 2017 Theo Clement
** Last update Sun May 21 13:50:17 2017 Theo Clement
*/

#include "my.h"

int		check_perm(char *str)
{
  struct stat	sb;

  if (stat(str, &sb) >= 0 && sb.st_mode > 0)
    {
      if ((sb.st_mode & S_IXUSR))
	return (1);
      else
	return (2);
    }
  return (0);
}

void	check_perm_exec(char *buffer, char **argv, char **envp, char *str)
{
  int	returned;

  returned = 0;
  if (buffer == NULL && str)
    returned = check_perm(str);
  else if (str == NULL && buffer)
    returned = check_perm(buffer);
  if (returned == 1)
    {
      if (buffer == NULL && str)
	if (execve(str, argv, envp) == -1)
	  exit (84);
      if (str == NULL && buffer)
	if (execve(buffer, argv, envp) == -1)
	  exit (84);
    }
  else if (returned == 2)
    {
      disp_error_cut(buffer);
      my_putstr(": Permission denied.\n");
      exit (1);
    }
  exit (1);
}

void	disp_error_cut(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] && buffer[i] != ';' && buffer[i] != '|' && buffer[i] != '&' && buffer[i] != '<' && buffer[i] != '>')
    {
      write(1, &buffer[i], 1);
      i++;
    }
}
