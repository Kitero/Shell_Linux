/*
** alloc_str.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Tue May 16 14:06:20 2017 Theo Clement
** Last update Tue May 16 14:06:25 2017 Theo Clement
*/

#include "my.h"

char	*alloc_str(char *str1)
{
  char	*str;
  int	i;

  i = 0;
  while (str1[i])
    i++;
  if ((str = malloc(sizeof(char) * (i + 1))) == 0)
    exit (84);
  i = 0;
  while (str1[i])
    {
      str[i] = str1[i];
      i++;
    }
  return (str);
}

char	*alloc_to(char *buffer, char item)
{
  char	*str;
  int	i;

  i = 0;
  while (buffer[i] != item && buffer[i])
    i++;
  if ((str = malloc(sizeof(char) * (i + 2))) == 0)
    exit (84);
  i = 0;
  while (buffer[i] != item && buffer[i])
    {
      str[i] = buffer[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	*alloc_after(char *buffer, char item)
{
  char	*str;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (buffer[i] != item && buffer[i])
    i++;
  i++;
  j = i;
  while (buffer[j])
    j++;
  if ((str = malloc(sizeof(char) * (j + 2))) == 0)
    exit (84);
  j = 0;
  while (buffer[i])
    {
      str[j] = buffer[i];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}

char	*alloc_env_var(char *buffer)
{
  char	*var;
  char	*final;
  char	*stock;
  int	i;

  i = 7;
  while (buffer[i] == ' ')
    i++;
  var = alloc_to(&buffer[i], ' ');
  while (buffer[i] != ' ' && buffer[i])
    i++;
  while (buffer[i] == ' ')
    i++;
  stock = alloc_to(&buffer[i], ' ');
  final = my_strcat(var, my_strcat("=", stock));
  return (final);
}
