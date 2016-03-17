/*
** stCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 18:52:04 2016 Antoine Baché
*/

#include "corewar.h"

int		stExec(t_hero *hero, t_instruct *new, unsigned char *map,
		       int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] St\n", 10);
#endif
  (void)endianness;
  if (new->args[1] == -1)
    new->args[1] = hero->reg[new->args[2]];
  map[(hero->loadAddress + hero->pc + new->args[0]) % MEM_SIZE] = new->args[1];
  return (0);
}
