/*
** addCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 22:04:52 2016 Lucas Troncy
*/

#include "corewar.h"

int	addCase(t_hero *hero, t_instruct *new, unsigned char *map,
		int endianness)
{
  (void)endianness;
  int		i;
  int		ret;
  t_bytecode	code;

  i = -1;
  code.bytecode = (char)map[hero->loadAddress + hero->pc++] % IDX_MOD;
  while (++1 < 3)
    {
      ret = getByteCode(&code);
      if (ret == 0)
	new->args[i] = hero->reg[(((int)map[hero->loadAddress +
				  hero->pc++]) -1)% REG_SIZE] % IDX_MOD;
      code.bytecode <<= 2;
    }
  new->time = ADD_TIME;
  return (0);
}
