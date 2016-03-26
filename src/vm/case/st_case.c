/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 13:22:06 2016 Antoine Baché
*/

#include "corewar.h"

int		stExec(t_hero *hero, t_instruct *new, unsigned char *map,
		       t_params *params)
{
  int		i;
  char		*tmp;

#ifdef	DEBUG
  write(1, "[Exec] St\n", 10);
#endif
  (void)params;
  if (new->args[1] == -1)
    hero->reg[new->args[2] % REG_SIZE] = new->args[0];
  else
    {
      tmp = (char *)&new->args[0];
      i = -1;
      while (++i < 4 &&
	     (map[(hero->loadAddress + new->args[2] +
		   new->args[1] + i) % MEM_SIZE] =
	      tmp[i] % IDX_MOD, 1));
    }
  return (0);
}
