/*
** affCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 17:02:56 2016 Antoine Baché
*/

#include "corewar.h"

int		affExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  char		c;

#ifdef	DEBUG
  write(1, "[Exec] Aff\n", 11);
#endif
  (void)map;
  (void)endianness;
  c = new->args[0] % 256;
  return (write(1, &c, 1));
}
