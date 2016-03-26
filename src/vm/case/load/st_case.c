/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 13:19:42 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int		stCase(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
  t_bytecode	byte;
  int		check;

  new->args[2] = hero->pc;
  byte.bytecode = new->bytecode =
    map[(hero->loadAddress + hero->pc++) % MEM_SIZE] % IDX_MOD;
  new->args[0] =
    hero->reg[(map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
	      % REG_SIZE] % IDX_MOD;
  byte.bytecode <<= 2;
  check = getByteCode(&byte);
  if (!check)
    {
      new->args[1] = -1;
      new->args[2] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
		      - 1)% REG_SIZE;
    }
  else
    {
      new->args[1] = readShort(hero, map, endianness) % IDX_MOD;
    }
  return (new->time = ST_TIME, 0);
}
