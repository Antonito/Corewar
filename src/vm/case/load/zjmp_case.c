/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 18:43:54 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int	zjmpCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
#ifdef	DEBUG
  write(1, "[Inst] Zjmp\n", 12);
#endif
  new->args[1] = hero->pc % MEM_SIZE;
  new->args[0] = readShort(hero, map, endianness) % MEM_SIZE;
  new->time = ZJMP_TIME;
  return (0);
}
