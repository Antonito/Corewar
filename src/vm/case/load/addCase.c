/*
** addCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 16:36:37 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		addCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		i;
  int		ret;
  t_bytecode	code;

#ifdef	DEBUG
  write(1, "[Inst] Add\n", 11);
#endif
  i = -1;
  (void)endianness;
  code.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
    % IDX_MOD;
  while (++i < 3)
    {
      ret = getByteCode(&code);
      if (ret == 0 && i < 2)
	new->args[i] =
	  hero->reg[(((int)map[(hero->loadAddress + hero->pc++) % MEM_SIZE])
		     - 1) % REG_SIZE] % IDX_MOD;
      if (!ret && i == 2)
	new->args[i] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
	  % REG_SIZE;
      code.bytecode <<= 2;
    }
  new->time = ADD_TIME;
  return (0);
}
