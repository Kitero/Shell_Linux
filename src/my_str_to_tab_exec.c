/*
** my_str_to_tab_exec.c for  in /home/Kitero/delivery/PSU_2016_minishell1
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Thu Jan 19 12:33:40 2017 Theo CLEMENT
** Last update Fri May 19 11:32:26 2017 Theo Clement
*/

#include "my.h"

int	nb_lines_exec(char *str, char item)
{
  int	i;
  int	lines;

  lines = 0;
  i = 0;
  while (str[i] && str[i] != '|' && str[i] != ';')
    {
      if (str[i] == item)
	{
	  lines++;
	  while (str[i] == item)
	    i++;
	  i--;
	}
      i++;
    }
  return (lines);
}

char	**alloc_exec(char *str, char item)
{
  char	**tab;
  int	i;
  int	k;
  int	lines;

  i = 0;
  k = 0;
  lines = nb_lines_exec(str, item);
  k = my_strlen(str);
  if ((tab = malloc(sizeof(char *) * (lines + 2))) == NULL)
    exit(84);
  while (i < (lines + 1))
    {
      if ((tab[i] = malloc(sizeof(char) * (k + 1))) == NULL)
	exit (84);
      i++;
    }
  return (tab);
}

char	**extand_exec(char *str, int i, int j, char item)
{
  char	**tab;
  int	k;

  k = 0;
  tab = alloc_exec(str, item);
  while (str[i] != '\0' && str[i] != '\n' && str[i] != '|' && str[i] != ';')
    {
      if (str[i] == item)
	{
	  tab[k++][j] = '\0';
	  j = 0;
	  while (str[i] == item)
	    i++;
	  i--;
	}
      else
	{
	  tab[k][j] = str[i];
	  j++;
	}
      i++;
    }
  tab[k][j] = '\0';
  tab[++k] = NULL;
  return (tab);
}

char	**str_to_tab_exec(char *str, char item)
{
  int	i;
  int	j;
  char	**tab;

  i = 0;
  j = 0;
  tab = extand_exec(str, i, j, item);
  tab = check_null_value(tab);
  return (tab);
}
