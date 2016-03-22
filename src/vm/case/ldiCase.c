/*
** ldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 14:52:14 2016 Antoine Baché
*/

#include "corewar.h"

int		ldiExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		i;
  int		s;
  char		*tmp;

#ifdef	DEBUG
  write(1, "[Exec] Ldi\n", 11);
#endif
  (void)endianness;
  i = -1;
  tmp = (char *)&s;
  while (++i < 4 &&
	 (tmp[i] = map[(hero->loadAddress + hero->pc + i) % MEM_SIZE], 1));
  s += new->args[1];
  if (new->type == 0x0a)
    s %= IDX_MOD;
  hero->reg[new->args[2] % REG_SIZE] =
    map[(hero->loadAddress + hero->pc + s) % MEM_SIZE];
  (hero->reg[new->args[2] % REG_SIZE]) ?
    (hero->carry = true) : (hero->carry = false);
  return (0);
}
