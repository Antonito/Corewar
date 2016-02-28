/*
** stiWrite.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 23:17:16 2016 Antoine Baché
** Last update Sun Feb 28 02:43:51 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "bytecode.h"

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
