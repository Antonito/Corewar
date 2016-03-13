/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Sun Mar 13 04:59:24 2016 Antoine Baché
*/

#include "corewar.h"
#include "common.h"

int		executeOrders(t_hero *heros, unsigned char *map)
{
  return (0);
}

int		liveCheck(t_params *data)
{
  if (data->cycle == data->cycleToDie)
    {
      data->cycle = 0;
      (data->cycleToDie - 4 > 0) ? (data->cycleToDie -= 4) :
	(data->cycleToDie = 0);
    }
  return (0);
}

int		vm(t_params *data, t_hero *heros, unsigned char *map)
{
  int		i;
  t_hero	*tmp;
;
  while (tmp = heros, i = 0, ++data->totalCycle, ++data->cycle,
	 data->isRunning)
    {
      while (i < data->nbHeros)
	{
	  executeOrders(tmp, map);
	  tmp = tmp->next;
	  if (data->totalCycle == data->nbrCycleDump)
	    return (dumpMem(map));
	  ++i;
	}
      liveCheck(data);
    }
  return (0);
}
