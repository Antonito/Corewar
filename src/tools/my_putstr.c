/*
** my_putstr.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:07:04 2016 Antoine Baché
** Last update Tue Feb 23 16:07:27 2016 Antoine Baché
*/

#include "tools.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
}
