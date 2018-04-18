/*
** my_str_to_tab.c for  in /home/Kitero/delivery/PSU_2016_minishell1
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Thu Jan 19 12:33:40 2017 Theo CLEMENT
** Last update Tue May 16 16:09:48 2017 Theo Clement
*/

#include "my.h"

int	nb_lines(char *str, char item)
{
  int	i;
  int	lines;

  lines = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == item)
	lines++;
      i++;
    }
  return (lines);
}

char	**alloc(char *str, char item)
{
  char	**tab;
  int	i;
  int	k;
  int	lines;

  i = 0;
  k = 0;
  lines = nb_lines(str, item);
  k = my_strlen(str);
  if ((tab = malloc(sizeof(char *) * (lines + 1 + 1))) == NULL)
    exit(84);
  while (i < (lines + 1 + 1))
    {
      if ((tab[i] = malloc(sizeof(char) * k)) == NULL)
	exit (84);
      i++;
    }
  return (tab);
}

char	**extand(char *str, int i, int j, char item)
{
  char	**tab;
  int	k;

  k = 0;
  tab = alloc(str, item);
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == item)
	{
	  tab[k][j] = '\0';
	  j = 0;
	  k++;
	}
      else
	{
	  tab[k][j] = str[i];
	  j++;
	}
      i++;
    }
  tab[k][j] = '\0';
  tab[k + 1] = NULL;
  return (tab);
}

char	**str_to_tab(char *str, char item)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '=')
    i++;
  i++;
  return (extand(str, i, j, item));
}
