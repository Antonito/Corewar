/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 19:29:30 2016 Antoine Baché
*/

#include "corewar.h"

int	zjmpExec(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] Zjmp\n", 12);
#endif
  (void)map;
  (void)endianness;
  if (hero->carry)
    hero->pc = (new->args[1] + new->args[0]) % MEM_SIZE;
  return (0);
}
