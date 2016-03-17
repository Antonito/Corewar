/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 17:15:33 2016 Antoine Baché
*/

#include "corewar.h"

int	zjmpCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
#ifdef	DEBUG
  write(1, "[Inst] Zjmp\n", 12);
#endif
  new->args[1] = hero->pc;
  new->args[0] = readShort(hero, map, endianness);
  new->time = ZJMP_TIME;
  return (0);
}
