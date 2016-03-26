/*
** lldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 01:10:59 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int	lldiCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
  t_bytecode	bytecode;
  int		i;
  int		check;

  bytecode.bytecode = new->bytecode =
    map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  i = -1;
  while (++i < 2)
    {
      if (!(check = getByteCode(&bytecode)))
	new->args[i] =
	  hero->reg[(map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
		    % REG_SIZE];
      else if (check == 1)
	new->args[i] = readInt(hero, map, endianness);
      else if (i < 1 && check == 2)
	new->args[i] = readShort(hero, map, endianness);
      bytecode.bytecode <<= 2;
    }
  new->args[2] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
    % REG_SIZE;
  return (new->time = LLDI_TIME, 0);
}
