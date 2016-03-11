/*
** init.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 04:18:45 2016 Antoine Baché
** Last update Fri Mar 11 14:48:23 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"
#include "common.h"
#include "errors.h"

int		addHero(t_hero *hero)
{
  t_hero	*new;

  if (!(new = malloc(sizeof(t_hero))))
    return (errorMalloc());
  new->id = hero->id + 1;
  new->loadAddress = -1;
  new->name = NULL;
  new->comment = NULL;
  new->pc = 0;
  new->isAlive = true;
  new->next = NULL;
  hero->next = new;
  return (0);
}

t_hero		*initHero(t_hero *hero)
{
  if (!(hero = malloc(sizeof(t_hero))))
    return (errorMalloc(), NULL);
  hero->id = 1;
  hero->loadAddress = -1;
  hero->name = NULL;
  hero->comment = NULL;
  hero->pc = 0;
  hero->isAlive = true;
  hero->next = NULL;
  return (hero);
}

void		initParams(t_params *data)
{
  data->cycle = 0;
  data->totalCycle = 0;
  data->cycleToDie = CYCLE_TO_DIE;
  data->process = 0;
  data->nbHeros = 0;
  data->nbrCycleDump = -1;
  data->isRunning = true;
}

int		initVm(t_params *data, t_hero *heros)
{
  char		*map;

  /* Penser a trier les heros */
  if (!(map = malloc(sizeof(char) * MEM_SIZE)))
    return (errorMalloc());
  my_bzero(map, MEM_SIZE);
  /* Penser a placer les champions */
  if (vm(data, hero, map))
#ifdef	DEBUG
    debugInitVm(data, heros);
#endif
  return (0);
}
