/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Fri Mar 25 21:25:58 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int		stCase(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
  t_bytecode	byte;
  int		check;

  byte.bytecode = new->bytecode =
    map[(hero->loadAddress + hero->pc++) % MEM_SIZE] % IDX_MOD;
  new->args[0] =
    hero->reg[(map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
	      % REG_SIZE] % IDX_MOD;
  printf("St: r%d\n", map[hero->loadAddress + hero->pc - 1]);
  byte.bytecode = byte.bytecode << 2;
  check = getByteCode(&byte);
  printf("bytecode = %x\n", (unsigned char)byte.bytecode);
  printf("check = %d\n", check);
  if (!check)
    {
      new->args[1] = -1;
      new->args[2] = map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
	% REG_SIZE;
      printf("St2: r%d\n", new->args[2]);
    }
  else
    {
      new->args[1] = readShort(hero, map, endianness) % IDX_MOD;
      printf("St [%d] [%d]\n", new->args[0], new->args[1]);
    }
  printf("\n\n");
  return (new->time = ST_TIME, 0);
}
