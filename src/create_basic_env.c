/*
** create_basic_env.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Wed May 17 14:10:57 2017 Theo Clement
** Last update Fri May 19 14:38:00 2017 tudgwal
*/

#include "my.h"

char	**set_path(char **env)
{
  int	i;
  char	**new_env;
  int	path;

  path = 0;
  i = 0;
  while (env[i])
    i++;
  if ((new_env = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (env[i])
    {
      if (strncmp(env[i], "PATH=", 4) == 0)
	path = 1;
      new_env[i] = env[i];
      i++;
    }
  if (!path)
    new_env[i] = alloc_str("PATH=/bin:/sbin");
  new_env[++i] = NULL;
  return (new_env);
}

char	**create_basic_env(char **env)
{
  char	*pwd;

  if ((pwd = malloc(sizeof(char) * 2048)) == NULL)
    return (NULL);
  if (getcwd(pwd, 2048) == NULL)
    {
      perror("Error, can't take the path\n");
      exit (84);
    }
  env = my_pwd(pwd, env);
  env = my_oldpwd(env, 0, 0, 0);
  env = set_path(env);
  return (env);
}
