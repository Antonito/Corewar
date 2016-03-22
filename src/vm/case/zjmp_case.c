/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 23:41:03 2016 Antoine Baché
*/

#include "corewar.h"
#ifdef	DEBUG
# include "tools.h"
#endif

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
#ifdef	DEBUG
      write(1, "Jumping to address ", 19);
      my_write_nb(hero->pc, 1, 1);
      write(1, "\n", 1);
#endif
    }
  return (0);
}
