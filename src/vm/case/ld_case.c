/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 13:21:38 2016 Antoine Baché
*/

#include "corewar.h"

int		ldExec(t_hero *hero, t_instruct *new, unsigned char *map,
		       t_params *params)
{
  char		*tmp;
  int		i;

#ifdef	DEBUG
  write(1, "[Exec] Ld\n", 10);
#endif
  (void)params;
  tmp = (char *)&hero->reg[new->args[1] % REG_SIZE];
  i = -1;
  if (new->type == 0x02)
    new->args[0] %= IDX_MOD;
  while (++i < 4 &&
	 (tmp[i] =
	  map[(hero->loadAddress + new->args[2] +
	       new->args[0] + i) % MEM_SIZE], 1));
  if (new->type == 0x02)
    hero->reg[new->args[1] % REG_SIZE] %= IDX_MOD;
  (hero->reg[new->args[1] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
