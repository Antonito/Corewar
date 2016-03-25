/*
** subCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Fri Mar 25 21:45:03 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int	subExec(t_hero *hero, t_instruct *new, unsigned char *map,
		t_params *params)
{
#ifdef	DEBUG
  write(1, "[Exec] Sub\n", 11);
#endif
  (void)map;
  (void)params;
  hero->reg[new->args[2] % REG_SIZE] = new->args[0] - new->args[1];
  (hero->reg[new->args[2] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
