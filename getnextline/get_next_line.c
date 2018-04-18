/*
** get_next_line.c for get_next_line in /home/Cisarius/delivery/CPE_2017_getnextline
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Mon Jan  2 12:03:17 2017 Guillaume Balestreri
** Last update Mon May 15 17:15:41 2017 tudgwal
*/

#include "my.h"

char	*strcopy(char *line, char *line2)
{
  int	a;

  a = 0;
  while (line[a])
    {
      line2[a] = line[a];
      a = a + 1;
    }
  line2[a] = '\0';
  return (line2);
}

char	*my_re_alloc(char *line, int d)
{
  char	*line2;
  int	a;

  a = 0;
  while (line[a] != '\0')
    a = a + 1;
  line2 = malloc(a + 1);
  if (line2 == NULL)
    return (NULL);
  line2 = strcopy(line, line2);
  free(line);
  line = malloc((READ_SIZE * d) + 1);
  if (line == NULL)
    return (NULL);
  line = strcopy(line2, line);
  free(line2);
  return (line);
}

int		my_get_c(char *buff, int c)
{
  while (buff[c] != '\n' && c != READ_SIZE && buff[c] != '\0')
    c = c + 1;
  c = c + 1;
  return (c);
}

char		*get_next_line(const int fd)
{
  static char	*buff;
  char		*line;
  int		a;

  a = 0;
  if ((line = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
 if ((buff = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
 line[0] = '\0';
 buff[0] = '\0';
 return (line = (get_next_line2(fd, a, buff, line)));
}
