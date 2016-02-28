/*
** stiWrite.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 23:17:16 2016 Antoine Baché
** Last update Sun Feb 28 05:03:03 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "bytecode.h"

int		write_ld(int new, t_parsing *tmp)
{
  int		code;
  t_bytecode	byte;
  int		nb;

  byte.bytecode = tmp->bytecode;
  code = getByteCode(&byte);
  nb = 0;
  nb |= (tmp->value[0] & 0xFF000000) >> 24;
  nb |= (tmp->value[0] & 0x00FF0000) >> 8;
  nb |= (tmp->value[0] & 0x0000FF00) << 8;
  nb |= (tmp->value[0] & 0x000000FF) << 24;
  if (code == 1 &&
      write(new, &nb, 4) < 0)
    return (1);
  if (code == 2)
    {
      printf("LD Write indirect\n");
      return (1);
    }
  if (write(new, &tmp->reg[0], 1) < 0)
    return (1);
  return (0);
}

int		write_sti(int new, t_parsing *tmp)
{
  int		i;
  int		code;
  t_bytecode	byte;

  i = 0;
  byte.bytecode = tmp->bytecode;
  while (i < 3)
    {
      code = getByteCode(&byte);
      if (!code && write(new, &tmp->reg[i], 1) < 0)
	return (1);
      if (code == 1 && !reverseShort((short *)&tmp->value[i]) &&
	  write(new, &tmp->value[i], 2) < 0)
	return (1);
      if (code == 2)
	return (1);
      byte.bytecode <<= 2;
      ++i;
    }
  return (0);
}
