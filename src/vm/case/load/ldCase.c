/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 17:40:20 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		ldCase(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
  int		ret;
  t_bytecode	code;

#ifdef	DEBUG
  write(1, "[Inst] Ld\n", 10);
#endif
  code.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
    % IDX_MOD;
  ret = getByteCode(&code);
  if (ret == 0)
    new->args[0] = hero->reg[((map[(hero->loadAddress + hero->pc++)
				   % MEM_SIZE]) - 1) % REG_SIZE] % IDX_MOD;
  else if (ret == 1)
    new->args[0] = readInt(hero, map, endianness) % IDX_MOD;
  else if (ret == 2)
    new->args[0] = readShort(hero, map, endianness) % IDX_MOD;
  new->args[1] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
    % REG_SIZE;
  new->time = LD_TIME;
  return (0);
}
