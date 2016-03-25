/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Fri Mar 25 20:28:28 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdio.h>
#include "corewar.h"
#include "common.h"
#include "endianness.h"

void		setLiveFalse(t_hero *heros, t_params *data)
{
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = -1;
  while (++i < data->process)
    {
      tmp->isAlive = false;
      tmp = tmp->next;
    }
}

void		checkEndGame(t_hero *heros, t_params *data)
{
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = -1;
  while (++i < data->process)
    if (tmp->id == -1)
      return ;
  write(1, "Draw.\n", 6);
  data->isRunning = false;
}

int		liveCheck(t_params *data, t_hero *heros)
{
  int		i;
  int		prevId;
  t_hero	*tmp;

  if (i = -1, tmp = heros, prevId = 0, data->nbrLive >= data->cycleToDie &&
      !(data->nbrLive = 0) && !(data->cycle = 0))
    {
      (data->cycleToDie - 4 > 0) ? (data->cycleToDie -= 4) :
	(data->cycleToDie = 0);
      while (++i < data->process)
	{
	  if (prevId = tmp->id, tmp->isAlive)
	    {
	      if (tmp->id != prevId)
		playerAlive(tmp->id, tmp->name);
	    }
	  else if (tmp->id != prevId)
	    tmp->id = -1;
	  tmp = tmp->next;
	  checkEndGame(heros, data);
	}
    }
  setLiveFalse(heros, data);
  return (0);
}

int		vm(t_params *data, t_hero *heros, unsigned char *map,
		   t_funcPtr *array)
{
  int		i;
  int		prevLive;
  t_hero	*tmp;

  if ((data->endianness = findEndian()) == UNKNOWN)
    return (write(2, "Unsupported endianness\n", 23), 1);
  prevLive = 0;
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
      if (prevLive == data->nbrLive && data->totalCycle >= data->cycleToDie)
	return (write(1, "Draw.\n", 6), 0);
      prevLive = data->nbrLive;
    }
  return (0);
}
