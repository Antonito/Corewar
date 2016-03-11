/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Fri Mar 11 14:54:50 2016 Antoine Baché
*/

#include "corewar.h"
#include "common.h"

int	vm(t_params *data, t_hero *heros, char *map)
{
  while (++totalCyle, ++cycle, data->isRunning)
    {
      if (cycle == CYCLE_TO_DIE)
	{
	  cycle = 0;
	  /* Check si heros envoient 'live' */
	}
    }
  return (0);
}
