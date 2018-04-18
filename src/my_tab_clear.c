/*
** my_tab_clear.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Wed May 17 16:13:47 2017 Theo Clement
** Last update Wed May 17 17:02:15 2017 Theo Clement
*/

#include "my.h"

char	**check_null_value(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == '\0')
	{
	  j = i;
	  while (tab[j])
	    {
	      tab[j] = tab[j + 1];
	      j++;
	    }
	}
      i++;
    }
  return (tab);
}
