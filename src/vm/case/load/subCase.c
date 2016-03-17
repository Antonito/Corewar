/*
** subCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 01:42:35 2016 Antoine Baché
*/

#include "corewar.h"

int	subCase(t_hero *hero, t_instruct *new, unsigned char *map,
		int endianness)
{
#ifdef	DEBUG
  write(1, "[Inst] Sub\n", 11);
#endif
  addCase(hero, new, map, endianness);
  new->time = SUB_TIME;
  return (0);
}
