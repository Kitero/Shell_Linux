/*
** my_exec.c for  in /home/Kitero/delivery/PSU_2016_minishell1
** 
** Made by Theo CLEMENT
** Login   <Kitero@epitech.net>
** 
** Started on  Sun Jan 22 13:30:35 2017 Theo CLEMENT
** Last update Fri Jun  9 15:57:33 2017 Theo Clement
*/

#include "my.h"

void	extand_execute(int i, char **path, char *final, char *buffer)
{
  int	j;
  int	k;

  j = 0;
  k = 0;
  while (path[i][j])
    {
      final[j] = path[i][j];
      j++;
    }
  final[j++] = '/';
  while (buffer[k] && buffer[k] != ' ' && buffer[k] != '\n'
	 && buffer[k] != ';')
    {
      final[j] = buffer[k];
      j++;
      k++;
    }
  final[j] = '\0';
}

int	no_need_path(char *str)
{
  if ((str[0] == '.' && ((str[1] == '.' && str[2] == '/') || str[1] == '/'))
      || str[0] == '/')
    return (1);
  return (0);
}

void	place_index(int i, int *j, char **path)
{
  *j = 0;
  while (path[i][*j])
    *j += 1;
}

char	*path_cmd_exec(char *buffer, char **path)
{
  char	*final;
  int	i;
  int	j;
  int	k;

  i = 0;
  while (path[i] != NULL)
    {
      place_index(i, &j, path);
      k = 0;
      while (buffer[k])
	k++;
      if ((final = malloc(sizeof(char) * (j + k + 2))) == 0)
	exit (84);
      extand_execute(i, path, final, buffer);
      if (access(final, X_OK) == 0)
	return (final);
      i++;
      free (final);
    }
  if (access(buffer, F_OK) == 0)
    return (NULL);
  disp_error_cut(buffer);
  my_putstr(": Command not found.\n");
  return (NULL);
}

void	my_exec(char *buffer, char **envp)
{
  char	**argv;
  char	*str;
  char	**path;

  path = get_path(envp);
  argv = str_to_tab_exec(buffer, ' ');
  if (no_need_path(buffer) == 1)
    check_perm_exec(buffer, argv, envp, NULL);
  if (path == NULL || path[0] == NULL)
    {
      disp_error_cut(buffer);
      my_putstr(": Command not found.\n");
      exit (84);
    }
  str = path_cmd_exec(buffer, path);
  check_perm_exec(NULL, argv, envp, str);
  exit (0);
}
