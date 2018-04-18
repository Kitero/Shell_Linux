/*
** cmp.c for cmp in /home/Cisarius/delivery/PSU_2016_minishell1
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sun Jan 22 10:56:53 2017 Guillaume Balestreri
** Last update Mon May 15 17:17:25 2017 tudgwal
*/

#include "my.h"

int     cmp(char *str, char *str2)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  if (str == NULL || str[i] == '\0')
    return (1);
  while (str[i] == ' ' || str[i] == '\t')
    i = i + 1;
  while (j != 4)
    {
      if (str[i] != str2[j])
	return (1);
      i = i + 1;
      j = j + 1;
    }
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i = i + 1;
    }
  write(1, "exit\n", 5);
  return (0);
}

int     my_strlen(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}

void	my_prompt2(int a, int b, char *buf)
{
  while (b > 1)
    {
      if (buf[a] == '/')
	b = b - 1;
      a = a + 1;
    }
  write(1, &buf[a], my_strlen(&buf[a]));
}

void    my_prompt()
{
  char  buf[1024];
  int   a;
  int   b;

  b = 0;
  a = 0;
  getcwd(buf, 1024);
  while (buf[a] != '\0')
    {
      if (buf[a] == '/')
	b = b + 1;
      a = a + 1;
    }
  if (b <= 2)
    write(1, buf, my_strlen(buf));
  else
    my_prompt2(0, b, buf);
  write(1, "> ", 2);
}
