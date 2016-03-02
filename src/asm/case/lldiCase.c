/*
** lldiCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Wed Mar  2 07:16:30 2016 Antoine Baché
*/

#include "asm.h"

int	writeLldi(int new, t_parsing *tmp, int endian)
{
  return (writeLdi(new, tmp, endian));
}

int	lldiCase(t_data *data, t_parsing *elem, int *offset)
{
  return (ldiCase(data, elem, offset));
}
