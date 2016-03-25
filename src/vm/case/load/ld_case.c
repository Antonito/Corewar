/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Fri Mar 25 21:03:58 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int		ldCase(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
  int		tmp;
  t_bytecode	byte;

  new->bytecode = byte.bytecode =
    map[(hero->loadAddress + hero->pc++) % MEM_SIZE] % IDX_MOD;
  tmp = getByteCode(&byte);
  if (tmp == 1)
    new->args[0] = readInt(hero, map, endianness) % IDX_MOD;
  else if (tmp == 2)
    new->args[0] = readShort(hero, map, endianness) % IDX_MOD;
  new->args[1] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE]  - 1)
    % REG_SIZE;
  new->time - LD_TIME;
  return (0);
}
