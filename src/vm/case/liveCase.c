/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 01:33:57 2016 Antoine Baché
*/

#include "corewar.h"

int	liveExec(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
#ifdef	DEBUG
  write(1, "[Exec] Live\n", 12);
#endif
  (void)hero;
  (void)new;
  (void)map;
  (void)endianness;
  return (0);
}
