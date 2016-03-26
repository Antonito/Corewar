/*
** addCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 01:12:41 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		addCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  (void)endianness;
  new->bytecode = ++hero->pc;
  new->args[0] = hero->reg[(map[(hero->loadAddress + hero->pc++)
				% MEM_SIZE] - 1) % REG_SIZE] % IDX_MOD;
  new->args[1] = hero->reg[(map[(hero->loadAddress + hero->pc++)
				% MEM_SIZE] - 1) % REG_SIZE] % IDX_MOD;
  new->args[2] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
    % REG_SIZE;
  new->time = ADD_TIME;
  return (0);
}
