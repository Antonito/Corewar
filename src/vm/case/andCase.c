/*
** andCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 16:53:48 2016 Antoine Baché
*/

#include "corewar.h"

int		andExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] And\n", 11);
#endif
  (void)map;
  (void)endianness;
  hero->reg[new->args[2]] = new->args[0] & new->args[1];
  hero->carry = true;
  return (0);
}
