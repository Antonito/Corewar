/*
** subCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 15:33:13 2016 Antoine Baché
*/

#include "asm.h"

int	writeSub(int new, t_parsing *tmp, int endian)
{
  return (writeAdd(new, tmp, endian));
}

int	subCase(t_data *data, t_parsing *elem, int *offset)
{
  return (addCase(data, elem, offset));
}
