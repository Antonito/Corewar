/*
** stiWrite.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 23:17:16 2016 Antoine Baché
** Last update Tue Mar  1 15:49:03 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "bytecode.h"

int		writeLd(int new, t_parsing *tmp, int endian)
{
  int		code;
  t_bytecode	byte;

  byte.bytecode = tmp->bytecode;
  code = getByteCode(&byte);
  if (code == 1 && !reverseInt(&tmp->value[0], endian) &&
      write(new, &tmp->value[0], 4) < 0)
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

int		writeSti(int new, t_parsing *tmp, int endian)
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
      if (code == 1 && !reverseShort((short *)&tmp->value[i], endian) &&
	  write(new, &tmp->value[i], 2) < 0)
	return (1);
      if (code == 2)
	return (1);
      byte.bytecode <<= 2;
      ++i;
    }
  return (0);
}
