/*
** orCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 18:41:52 2016 Antoine Baché
*/

#include "asm.h"

int	writeOr(int new, t_parsing *tmp, int endian)
{
  return (writeXor(new, tmp, endian));
}

int	orCase(t_data *data, t_parsing *elem, int *offset)
{
  --(*offset);
  return (xorCase(data, elem, offset));
}
