/*
** fonctions.c for  in /home/chad/CPool/PSU_2016_my_ls
** 
** Made by Charles-Adrien Pons
** Login   <chad@epitech.net>
** 
** Started on  Wed Nov  26 22:59:38 2016 Charles-Adrien Pons
** Last update Sun Nov  28 19:37:13 2016 Charles-Adrien Pons
*/

#include <stdlib.h>
#include <stdarg.h>

int	free_tab_char(char **tab, int ret)
{
  char	**ptr;

  ptr = tab;
  while (*tab)
    free(*(tab++));
  free(ptr);
  return (ret);
}

void		free_all(int nbr, ...)
{
  va_list	ap;

  va_start(ap, nbr);
  while (nbr-- > 0)
    free(va_arg(ap, void *));
  va_end(ap);
}
