/*
** addCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 02:19:39 2016 Antoine Baché
*/

#include "corewar.h"

int		addExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] Add\n", 11);
#endif
  (void)map;
  (void)endianness;
  hero->reg[new->args[2] % REG_SIZE] = new->args[0] + new->args[1];
  (hero->reg[new->args[2] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
