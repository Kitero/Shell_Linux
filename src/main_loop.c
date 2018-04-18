/*
** fonctions.c for  in /home/chad/CPool/PSU_2016_my_ls
** 
** Made by Charles-Adrien Pons
** Login   <chad@epitech.net>
** 
** Started on  Wed Nov  26 22:59:38 2016 Charles-Adrien Pons
** Last update Fri May 19 19:26:52 2017 Guillaume Balestreri
*/

#include "my.h"

char	*my_cut_separator(char *line)
{
  int	a;

  a = 0;
  while (line[a] != '\0' && line[a] != ';')
    a = a + 1;
  if (line[a] == '\0' || line[a + 1] == '\0')
    return (NULL);
  else
    a = a + 1;
  return (&line[a]);
}

int	shorten_loop(char *line, char ***env, int *i)
{
  int	ret;

  ret = 0;
  while (line != NULL && (my_separator(line, *env)) != 2)
    line = my_cut_separator(line);
  if (line != NULL && line[0] != '\0' && (ret = my_check_env(line)) != 0)
    {
      *env = my_mod_env(line, *env, ret, i);
      line = NULL;
    }
  if (line != NULL)
    *i = my_cd(line, *env);
  if (line != NULL && line[0] != '\0' && *i == 2)
    *i = my_check(line, *env);
  return (0);
}
