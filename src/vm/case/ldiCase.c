/*
** ldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Fri Mar 18 17:15:49 2016 Antoine Baché
*/

#include "corewar.h"

int		ldiExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		i;
  int		s;
  char		*tmp;

#ifdef	DEBUG
  write(1, "[Exec] Ldi\n", 11);
#endif
  (void)hero;
  (void)new;
  (void)map;
  (void)endianness;
  (void)tmp;
  (void)i;
  (void)s;
  (hero->reg[new->args[2]]) ? (hero->carry = true) : (hero->carry = false);
  return (0);
}
