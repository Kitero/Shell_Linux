/*
** get_next_line2.c for get_next_line2 in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 10:49:16 2017 Guillaume Balestreri
** Last update Mon May 15 17:15:52 2017 tudgwal
*/

#include "my.h"

char    *get_next_line2(const int fd, int a, char *buff, char *line)
{
  int   d;
  int   c;

  c = 0;
  d = 1;
  while ((c = read(fd, buff, READ_SIZE)) > 0 && buff[0] != '\n')
    {
      d = d + 1;
      if (c == -1 || c == 0 || (line = my_re_alloc(line, d)) == NULL)
	return (NULL);
      if (c < READ_SIZE)
	buff[c + 1] = '\0';
      c = 0;
      while (buff[0] != '\n' && c != READ_SIZE)
	{
	  line[a] = buff[0];
	  c = c + 1;
	  a = a + 1;
	}
      line[a] = '\0';
    }
  if (c == 0 && buff[0] != '\n')
    return (NULL);
  return (line);
}
