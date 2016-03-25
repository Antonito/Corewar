/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Fri Mar 25 21:17:31 2016 Antoine Baché
*/

#include "corewar.h"

int		stExec(t_hero *hero, t_instruct *new, unsigned char *map,
		       t_params *params)
{
#ifdef	DEBUG
  write(1, "[Exec] St\n", 10);
#endif
  (void)params;
  if (new->args[1] == -1)
    new->args[1] = hero->reg[new->args[2] % REG_SIZE];
  map[(hero->loadAddress + hero->pc + new->args[1]) % MEM_SIZE] = new->args[0];
  return (0);
}
