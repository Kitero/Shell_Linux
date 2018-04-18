/*
** my_redirections.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Tue May 16 14:50:40 2017 Theo Clement
** Last update Sat May 20 10:32:47 2017 Theo Clement
*/

#include "my.h"

static int	free_stuff(int *redirect, char **tab)
{
  free(redirect);
  return (free_tab_char(tab, -2));
}

int	redirect(char *line, char ***env)
{
  int	i;
  int	ret;
  int	*redirect;
  char	**tab;
  char	***tab_o_tabs;

  if (!(tab = my_str_to_wordtab(line)) || !(i = count(tab))
      || !(redirect = malloc((1 + i) * sizeof(int)))
      || !(tab_o_tabs = sep_tab(tab, i, redirect, 0)))
    return ((!tab ? -2 : (i == 0 || !redirect) ?
	     free_tab_char(tab,i == 0 ?  -1 : -2) : free_stuff(redirect, tab)));
  i = 0;
  while (redirect[i] != -1)
    if (redirect[i] < 4)
      ret = parse_redirect(redirect[i], tab_o_tabs);
    else if (redirect == 4)
      ret = my_check(str, *env)
    else
      shorten_loop(str, env, &ret);
  return (ret);
}
