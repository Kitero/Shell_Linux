/*
** get_path.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Tue May 16 13:58:18 2017 Theo Clement
** Last update Tue May 16 14:16:13 2017 Theo Clement
*/

#include "my.h"

char	**get_path(char **envp)
{
  int	j;

  j = 0;
  if (envp[0] == NULL)
    return (NULL);
  while (envp[j])
    {
      if (envp[j][0] == 'P' && envp[j][1] == 'A'
	  && envp[j][2] == 'T' && envp[j][3] == 'H')
	return (str_to_tab(envp[j], ':'));
      j++;
    }
  return (NULL);
}
