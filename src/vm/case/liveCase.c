/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 14:21:01 2016 Antoine Baché
*/

#include "corewar.h"

int	liveCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
  new->bytecode = 0;
  new->args[0] = readInt(hero, map, endianness);
  printf("Live = %d\n", new->args[0]);
  return (0);
}
