/*
** my_putstr.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Tue May 16 14:02:20 2017 Theo Clement
** Last update Tue May 16 14:02:48 2017 Theo Clement
*/

#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
