/*
** my_strcat.c for  in /home/Kitero/delivery/PSU/PSU_2016_minishell2
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Fri Mar 31 13:42:40 2017 Theo Clement
** Last update Fri Apr  7 15:17:02 2017 Theo Clement
*/

#include "my.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*new;
  int	size_1;
  int	size_2;
  int	i;
  int	j;

  i = 0;
  j = 0;
  size_1 = my_strlen(str1);
  size_2 = my_strlen(str2);
  if ((new = malloc(sizeof(char) * (size_1 + size_2 + 1))) == 0)
    exit (84);
  while (str1[j])
    {
      new[j] = str1[j];
      j++;
    }
  while (str2[i])
    {
      new[j] = str2[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}
