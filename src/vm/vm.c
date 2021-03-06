/*
** vm.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 14:49:02 2016 Antoine Baché
** Last update Sat Mar 26 19:26:38 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdio.h>
#include "corewar.h"
#include "common.h"
#include "endianness.h"
#include "tools.h"

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

void		findWinner(t_hero *heros, t_params *data)
{
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = -1;
  while (++i < data->process)
    {
      if (tmp->id > 0 && ABS(tmp->id) == data->lastLive)
	{
	  playerWins(tmp->id, tmp->name);
	  return ;
	}
      tmp = tmp->next;
    }
  write(1, "Draw.\n", 6);
}

void		checkEndGame(t_hero *heros, t_params *data)
{
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = -1;
  while (++i < data->process)
    if (tmp->id < 0)
      return ;
  if (data->nbHeros == 1)
    write(1, "Draw.\n", 6);
  else
    findWinner(heros, data);
  data->isRunning = false;
}

int		liveCheck(t_params *data, t_hero *heros)
{
  int		i;
  int		prevId;
  t_hero	*tmp;

  if (i = -1, tmp = heros, prevId = 0,
      (data->nbrLive >= data->cycleToDie ||
       (data->cycle >> 4) == data->cycleToDie) &&
      !(data->nbrLive = 0) && !(data->cycle = 0))
    {
      (data->cycleToDie - 4 > 0) ? (data->cycleToDie -= 4) :
	(data->cycleToDie = 0);
      while (++i < data->process && data->isRunning)
	{
	  if (prevId = tmp->id, tmp->isAlive)
	    {
	      if (tmp->id != prevId && (data->lastLive = tmp->id) > -2)
		playerAlive(tmp->id, tmp->name);
	    }
	  else if (tmp->id != prevId)
	    tmp->id = -tmp->id;
	  tmp = tmp->next;
	  checkEndGame(heros, data);
	}
    }
  return (setLiveFalse(heros, data), 0);
}

int		vm(t_params *data, t_hero *heros, unsigned char *map,
		   t_funcPtr *array)
{
  int		i;
  t_hero	*tmp;

  if (data->nbHeros == 1)
    return (write(1, "Draw.\n", 6), 0);
  if ((data->endianness = findEndian()) == UNKNOWN)
    return (write(2, "Unsupported endianness\n", 23), 1);
  while (tmp = heros, i = 0, ++data->totalCycle, ++data->cycle,
	 data->currentCycle = false, data->isRunning)
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
