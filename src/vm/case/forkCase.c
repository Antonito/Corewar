/*
** forkCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 22:16:58 2016 Lucas Troncy
*/

#include "corewar.h"

int	forkCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
  int		ret;
  int		i;
  t_bytecode	code;

  i = -1;
  code.bytecode = (char)map[hero->loadAddress + hero->pc++] % IDX_MOD;
  while (i++ < 1)
    {
      ret = getByteCode(&code);
      if (ret == 1)
	new->args[i] = readShort(hero, map, endiannes) % IDX_MOD;
      code.bytecode <<= 2;
    }
  new->time = FORK_TIME;
  return (0);
}
