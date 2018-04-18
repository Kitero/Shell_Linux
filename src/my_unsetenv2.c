/*
** my_unsetenv2.c for  in /home/tudgwal/delivery/PSU_2016_42sh/src
** 
** Made by tudgwal
** Login   <tudgwal@epitech.net>
** 
** Started on  Wed May 17 14:32:22 2017 tudgwal
** Last update Fri May 19 12:07:22 2017 tudgwal
*/

#include "my.h"

int     fct_env(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    {
      my_putstr(env[i++]);
      write(1, "\n", 1);
    }
  return (0);
}

int	fct_echo(char *s)
{
  int	i;

  i = 4;
  if (strncmp(s, "echo", 4) != 0)
    return (0);
  s = my_clean(s);
  while (s[i++] != '\0')
    write(1, &s[i], 1);
  write(1, "\n", 1);
  return (2);
}
