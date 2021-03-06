/*
** ldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 13:57:02 2016 Antoine Baché
*/

#include "corewar.h"

int		ldiExec(t_hero *hero, t_instruct *new, unsigned char *map,
			t_params *params)
{
  int		i;
  int		s;
  char		*tmp;

#ifdef	DEBUG
  write(1, "[Exec] Ldi\n", 11);
#endif
  (void)params;
  i = -1;
  s = 0;
  tmp = (char *)&s;
  while (++i < 2 &&
	 (tmp[i + 2] = map[(hero->loadAddress + new->pcSave + i + new->args[0])
			   % MEM_SIZE], 1));
  s += new->args[1];
  if (new->type == 0x0a)
    s %= IDX_MOD;
  i = -1;
  tmp = (char *)&hero->reg[new->args[2] % REG_SIZE];
  while (++i < 4 && (tmp[i] =
		     map[(hero->loadAddress + new->pcSave + i + s) %
			 MEM_SIZE], 1));
  (hero->reg[new->args[2] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
