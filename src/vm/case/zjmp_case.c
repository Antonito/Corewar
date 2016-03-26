/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 17:48:46 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int		zjmpExec(t_hero *hero, t_instruct *new, unsigned char *map,
			 t_params *params)
{
  int		sum;

#ifdef	DEBUG
  write(1, "[Exec] Zjmp\n", 12);
#endif
  (void)map;
  (void)params;
  if (hero->carry)
    {
      sum = new->args[0] + new->args[1] - 1;
      if (sum < 0)
	++sum;
      hero->pc = (ABS(sum)) % MEM_SIZE;
    }
  return (0);
}
