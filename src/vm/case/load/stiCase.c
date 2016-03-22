/*
** stiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 17:00:59 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int		stiCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		i;
  int		check;
  t_bytecode	byte;

#ifdef	DEBUG
  write(1, "[Inst] Sti\n", 11);
#endif
  byte.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  i = 0;
  new->args[0] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
    % REG_SIZE;
  while (byte.bytecode <<= 2, ++i < 3)
    if (!(check = getByteCode(&byte)))
      new->args[i] =
	hero->reg[((map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
		   % REG_SIZE)] % IDX_MOD;
    else if (check == 1 || check == 2)
      new->args[i] = readShort(hero, map, endianness) % IDX_MOD;
    else
      new->args[i] = 0;
  return (new->time = STI_TIME, 0);
}
