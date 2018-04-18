/*
** my_cd2.c for my_cd2 in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 16:10:24 2017 Guillaume Balestreri
** Last update Sun May 21 16:28:51 2017 Guillaume Balestreri
*/

#include "my.h"

char    *my_home(char **env)
{
  char  *home;
  int   i;
  int   j;

  i = 0;
  j = 5;
  while (env[i] != '\0')
    {
      if (env[i][0] == 'H' && env[i][1] == 'O' &&
	  env[i][2] == 'M' && env[i][3] == 'E' && env[i][4] == '=')
	{
	  if ((home = malloc(my_strlen(env[i]))) == NULL)
	    return (NULL);
	  while (env[i][j] != '\0')
	    {
	      home[j - 5] = env[i][j];
	      j = j + 1;
	    }
	  home[j - 5] = '\0';
	  return (home);
	}
      i = i + 1;
    }
  return (NULL);
}

char	*my_take_oldpwd(char **env)
{
  char	*oldpwd;
  int	i;
  int   j;

  i = 0;
  j = 7;
  while (env[i] != '\0')
    {
      if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D'
	  && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D'
	  && env[i][6] == '=')
	{
	  if ((oldpwd = malloc(my_strlen(env[i]))) == NULL)
	    return (NULL);
	  while (env[i][j] != '\0')
	    {
	      oldpwd[j - 7] = env[i][j];
	      j = j + 1;
	    }
	  oldpwd[j - 7] = '\0';
	  return (oldpwd);
	}
      i = i + 1;
    }
  return (NULL);
}

char 	**my_oldpwd(char **env, int i, int j, int k)
{
  char  *trash;
  char	*result;

  while (env[i] != NULL && (strncmp(env[i], "PWD=", 4)) != 0)
    i++;
  if (env[i] == NULL)
    return (env);
  while (env[i][j] != '\0')
    j++;
  if ((result = malloc(sizeof(char)
		       * (j + strlen("setenv OLDPWD ") + 1))) == NULL)
    return (env);
  j = 4;
  trash = strdup("setenv OLDPWD ");
  while (trash[k] != '\0')
    {
      result[k] = trash[k];
      k++;
    }

  while (env[i][j] != '\0')
    result[k++] = env[i][j++];
  result[k] = '\0';
  free (trash);
  return (my_setenv(result, env, 0, 0));
}

char    **my_pwd(char *buf, char **env)
{
  int   a;
  char  *trash;
  char  *result;

  a = strlen(buf);
  if ((result = malloc(sizeof(char) *
		       (a + strlen("setenv PWD ") + 1))) == NULL)
    return (NULL);
  a = 0;
  env = my_oldpwd(env, 0, 4, 0);
  trash = strdup("setenv PWD ");
  while (trash[a] != '\0')
    {
      result[a] = trash[a];
      a = a + 1;
    }
  a = 0;
  while (buf[a] != '\0')
    {
      result[a + 11] = buf[a];
      a = a + 1;
    }
  result[a + 11] = '\0';
  free (trash);
  return (my_setenv(result, env, 0, 0));
}
