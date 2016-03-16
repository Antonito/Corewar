/*
** andCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 21:49:53 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		andCase(t_hero *hero, t_instruct *new, unsigned char *map,
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
	  hero->reg[(map[hero->loadAddress + hero->pc++] % REG_SIZE)] % IDX_MOD;
      else if (check == 1 && i < 2)
	new->args[i] = readInt(hero, map, endianness) % IDX_MOD;
      else if (check == 2 && i < 2)
	new->args[i] = readShort(hero, map, endianness) % IDX_MOD;
      byte.bytecode <<= 2;
    }
  new->time = AND_TIME;
  return (0);
}
