/*
** subCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Mon Feb 29 23:34:40 2016 Antoine Baché
*/

#include "asm.h"

int	write_sub(int new, t_parsing *tmp)
{
  return (write_add(new, tmp));
}

int	subCase(t_data *data, t_parsing *elem, int *offset)
{
  return (addCase(data, elem, offset));
}
