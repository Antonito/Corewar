/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Wed Mar 23 12:15:16 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "common.h"
#include "endianness.h"

int		liveCheck(t_params *data, t_hero *heros)
{
  int		i;
  int		prev;
  t_hero	*tmp;

  if (i = -1, tmp = heros, data->nbrLive == data->cycleToDie)
    {
      data->nbrLive = 0;
      (data->cycleToDie - 4 > 0) ? (data->cycleToDie -= 4) :
	(data->cycleToDie = 0);
      while (++i < data->process)
	{
	  if (tmp->isAlive)
	    tmp->isAlive = false;
	  else
	    tmp->id = -1;
	  tmp = tmp->next;
	}
    }
  tmp = heros;
  while (++i < data->process)
    {
      tmp->isAlive = false;
      tmp = tmp->next;
    }
  return (0);
}

int		vm(t_params *data, t_hero *heros, unsigned char *map,
		   t_funcPtr *array)
{
  int		i;
  t_hero	*tmp;

  if ((data->endianness = findEndian()) == UNKNOWN)
    return (write(2, "Unsupported endianness\n", 23), 1);
  while (tmp = heros, i = 0, ++data->totalCycle, ++data->cycle,
	 data->isRunning)
    {
      while (i < data->process)
	{
	  if (executeOrders(tmp, map, array, data))
	    return (1);
	  tmp = tmp->next;
	 if (data->totalCycle == data->nbrCycleDump)
	   return (dumpMem(map));
	 ++i;
	}
      liveCheck(data, heros);
    }
  return (0);
}
