/*
** lldCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 16:45:07 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		lldCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		ret;
  int		i;
  t_bytecode	code;

#ifdef	DEBUG
  write(1, "[Inst] Lld\n", 11);
#endif
  i = -1;
  code.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  while (i++ < 2)
    {
      ret = getByteCode(&code);
      if (ret == 0)
	new->args[i] =
	  hero->reg[(((int)map[(hero->loadAddress + hero->pc++) % MEM_SIZE]) -1)
		    % REG_SIZE];
      else if (ret == 1 && i != 1)
	new->args[i] = readInt(hero, map, endianness);
      else if (ret == 2 && i != 1)
	new->args[i] = readShort(hero, map, endianness);
      code.bytecode <<= 2;
    }
  new->time = LLD_TIME;
  return (0);
}
