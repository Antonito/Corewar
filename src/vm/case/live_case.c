/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 19:03:42 2016 Antoine Baché
*/

#include "corewar.h"

int	liveExec(t_hero *hero, t_instruct *new, unsigned char *map,
		 t_params *params)
{
#ifdef	DEBUG
  write(1, "[Exec] Live\n", 12);
#endif
  (void)new;
  (void)map;
  ++params->nbrLive;
  playerAlive(hero->id, hero->name);
  if (!params->currentCycle)
    {
      params->lastLive = hero->id;
      params->currentCycle = true;
    }
  if (hero->reg[0] == (unsigned int)new->args[0])
    {
      hero->isAlive = true;
    }
  return (0);
}
