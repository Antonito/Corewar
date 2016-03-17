/*
** stiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 16:46:37 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		stiCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		i;
  int		check;
  t_bytecode	byte;

#ifdef	DEBUG
  write(1, "[Inst] Sti\n", 11);
#endif
  i = -1;
  byte.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  while (++i < 3)
    {
      if (!(check = getByteCode(&byte)))
	new->args[i] =
	  hero->reg[((map[(hero->loadAddress + hero->pc++) % MEM_SIZE] -1)
		     % REG_SIZE)]
	  % IDX_MOD;
      else if (i && check == 1)
	new->args[i] = readShort(hero, map, endianness) % IDX_MOD;
      else if (i && i < 2 && check == 2)
	new->args[i] = readShort(hero, map, endianness) % IDX_MOD;
      byte.bytecode <<= 2;
    }
  new->time = STI_TIME;
  return (0);
}
