/*
** my_seperator.c for my_seperator in /home/Cisarius/delivery/PSU_2016_42sh/src
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Fri May 19 15:17:06 2017 Guillaume Balestreri
** Last update Fri May 19 19:53:21 2017 Guillaume Balestreri
*/

#include "my.h"

char	*cut_separ1(char *line)
{
  int   a;
  char  *result;

  a = 0;
  if ((result = malloc(my_strlen(line))) == NULL)
    return (NULL);
  while (line[a + 1] != '\0' && (line[a] != '|' && line[a + 1] != '|') &&
	 (line[a] != '&' && line[a + 1] != '&') && line[a] != ';')
    {
      result[a] = line[a];
      a = a + 1;
    }
  result[a] = '\0';
  return (result);
}

char	*cut_separ2(char *line)
{
  int   a;
  int	i;
  char  *result;

  a = 0;
  i = 0;
  if ((result = malloc(my_strlen(line))) == NULL)
    return (NULL);
  while (line[a + 1] != '\0' && (line[a] != '|' && line[a + 1] != '|') &&
	 (line[a] != '&' && line[a + 1] != '&') && line[a] != ';')
      a = a + 1;
  a = a + 3;
  while (line[a + 1] != '\0' && (line[a] != '|' && line[a + 1] != '|') &&
	 (line[a] != '&' && line[a + 1] != '&') && line[a] != ';')
    {
      result[i] = line[a];
      a = a + 1;
      i = i + 1;
    }
  result[i] = line[a];
  result[i + 1] = '\0';
  return (result);
}

int	my_sepa_and(char *line, char **env)
{
  int	i;

  shorten_loop(cut_separ1(line), &env, &i);
  if (i == 0)
    shorten_loop(cut_separ2(line), &env, &i);  
  return (i);
}

int	my_sepa_or(char *line, char **env)
{
  int	i;

  shorten_loop(cut_separ1(line), &env, &i);
  if (i != 0)
    shorten_loop(cut_separ2(line), &env, &i);  
  return (i);
}

int	my_separator(char *line, char **env)
{
  int	i;

  i = 0;
  if (line == NULL)
    return (2);
  while (line[i] != '\0' && line[i + 1] != '\0' && line[i] != ';'
	 && line[i] != '|' && (line[i] != '&' && line[i + 1] != '&'))
    i = i + 1;
  i = i + 1;
  if (line[i] == '&')
    return (my_sepa_and(line, env));
  if (line[i] == '|')
    {
      return (my_sepa_or(line, env));
    }
  return (2);
}
