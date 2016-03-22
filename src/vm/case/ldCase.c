/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 23:41:24 2016 Antoine Baché
*/

#include "corewar.h"

int		ldExec(t_hero *hero, t_instruct *new, unsigned char *map,
		       t_params *params)
{
#ifdef	DEBUG
  write(1, "[Exec] Ld\n", 10);
#endif
  (void)map;
  (void)params;
  hero->reg[new->args[1] % REG_SIZE] = new->args[0];
  if (new->type == 0x02)
    hero->reg[new->args[1] % REG_SIZE] %= IDX_MOD;
  (hero->reg[new->args[1] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
