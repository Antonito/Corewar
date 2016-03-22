/*
** stiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 16:52:53 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int		stiExec(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] Sti\n", 11);
#endif
  (void)hero;
  (void)endianness;
  dprintf(2, "Args[1] = %d\n", new->args[1]);
  dprintf(2, "Args[2] = %d\n", new->args[2]);
  map[ABS((new->args[1] + new->args[2])) % MEM_SIZE] = new->args[0] % 256;
  return (0);
}
