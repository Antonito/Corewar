/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Fri Mar 11 15:09:33 2016 Antoine Baché
*/

#include "corewar.h"
#include "common.h"

int	vm(t_params *data, t_hero *heros, char *map)
{
  (void)heros;
  (void)map;
  while (++data->totalCycle, ++data->cycle, data->isRunning)
    {
      if (data->cycle == CYCLE_TO_DIE)
	{
	  data->cycle = 0;
	  /* Check si heros envoient 'live' */
	}
    }
  return (0);
}
