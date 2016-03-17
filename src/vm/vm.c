/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Thu Mar 17 15:46:44 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "common.h"
#include "endianness.h"

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

int		vm(t_params *data, t_hero *heros, unsigned char *map,
		   t_funcPtr *array)
{
  int		endianness;
  int		i;
  t_hero	*tmp;

  if ((endianness = findEndian()) == UNKNOWN)
    return (write(2, "Unsupported endianness\n", 23), 1);
  while (tmp = heros, i = 0, ++data->totalCycle, ++data->cycle,
	 data->isRunning)
    {
      while (i < data->nbHeros)
	{
	  if (executeOrders(tmp, map, array, endianness))
	    return (1);
	  tmp = tmp->next;
	 if (data->totalCycle == data->nbrCycleDump)
	   return (dumpMem(map));
	 ++i;
	}
      liveCheck(data);
    }
  return (0);
}
