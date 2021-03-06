/*
** forkCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 13:59:21 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int		forkCase(t_hero *hero, t_instruct *new, unsigned char *map,
			 int endianness)
{
#ifdef	DEBUG
  write(1, "[Inst] Fork\n", 12);
#endif
  new->args[0] = readShort(hero, map, endianness) % IDX_MOD;
  new->time = FORK_TIME;
  return (0);
}
