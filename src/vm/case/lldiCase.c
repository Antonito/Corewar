/*
** lldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 00:19:48 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int	lldiCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
  int		i;
  int		check;
  t_bytecode	byte;

  i = -1;
  byte.bytecode = (char)map[hero->loadAddress + hero->pc++];
  while (++i < 3)
    {
      if (!(check = getByteCode(&byte)))
	new->args[i] =
	  hero->reg[((map[hero->loadAddress + hero->pc++] -1) % REG_SIZE)];
      else if (i < 2 && check == 1)
	new->args[i] = readShort(hero, map, endianness);
      else if (!i && check == 2)
	new->args[i] = readShort(hero, map, endianness);
      byte.bytecode <<= 2;
    }
  new->time = LDI_TIME;
  return (0);
}
