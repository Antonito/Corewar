/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 18:25:25 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		stCase(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
  int		ret;
  t_bytecode	code;

#ifdef	DEBUG
  write(1, "[Inst] St\n", 10);
#endif
  code.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
    % IDX_MOD;
  new->args[0] =
    hero->reg[(((int)map[(hero->loadAddress + hero->pc++) % MEM_SIZE]) - 1)
	      % REG_SIZE] % IDX_MOD;
  code.bytecode <<= 2;
  if (!(ret = getByteCode(&code)))
    {
      new->args[1] = -1;
      new->args[2] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
	% REG_SIZE;
    }
  else if (ret == 1)
    new->args[1] = readInt(hero, map, endianness) % IDX_MOD;
  else if (ret == 2)
    new->args[1] = readShort(hero, map, endianness) % IDX_MOD;
  return (new->time = ST_TIME, 0);
}
