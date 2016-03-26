/*
** affCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 01:12:50 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		affCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  (void)endianness;
  new->bytecode = map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  new->args[0] = map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1;
  new->args[0] %= REG_SIZE;
  new->time = AFF_TIME;
  return (0);
}
