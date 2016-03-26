/*
** stiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 13:26:45 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int		stiExec(t_hero *hero, t_instruct *new, unsigned char *map,
			t_params *params)
{
  int		i;
  char		*tmp;

#ifdef	DEBUG
  write(1, "[Exec] Sti\n", 11);
#endif
  (void)hero;
  (void)params;
  i = -1;
  tmp = (char *)&new->args[0];
  while (++i < 4 &&
	 (map[(new->args[1] + new->args[2] + i) % MEM_SIZE] =
	  tmp[i], 1));
  return (0);
}
