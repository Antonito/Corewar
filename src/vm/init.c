/*
** init.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 04:18:45 2016 Antoine Baché
** Last update Tue Mar 22 03:33:52 2016 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "corewar.h"
#include "common.h"
#include "errors.h"
#include "tools.h"

int		addHero(t_hero *hero)
{
  t_hero	*new;

  if (!(new = malloc(sizeof(t_hero))) || !(memset(new, 0, sizeof(t_hero))))
    return (errorMalloc());
  new->id = hero->id + 1;
  new->loadAddress = -1;
  new->name = NULL;
  new->comment = NULL;
  new->pc = 0;
  new->size = 0;
  new->customId = false;
  new->customAddress = false;
  new->isAlive = true;
  new->carry = false;
  new->inst = NULL;
  new->next = NULL;
  hero->next = new;
  return (0);
}

t_hero		*initHero(t_hero *hero)
{
  if (!(hero = malloc(sizeof(t_hero))) || !(memset(hero, 0, sizeof(t_hero))))
    return (errorMalloc(), NULL);
  hero->id = 1;
  hero->loadAddress = -1;
  hero->name = NULL;
  hero->comment = NULL;
  hero->pc = 0;
  hero->size = 0;
  hero->customId = false;
  hero->customAddress = false;
  hero->carry = false;
  hero->isAlive = true;
  hero->inst = NULL;
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

void		writeHero(unsigned char *map, t_hero *hero)
{
  int		i;

  i = -1;
  while (++i < hero->size)
    {
      map[hero->loadAddress + i] = hero->data[i];
    }
}

int		initVm(t_params *data, t_hero *heros)
{
  t_hero	*tmp;
  unsigned char	*map;
  t_funcPtr	array;

  if (orderHeros(heros) || placeHeros(heros, data->nbHeros))
    return (1);
  if (!(map = malloc(sizeof(char) * MEM_SIZE)) ||
      !(array.load = selector()) || !(array.exec = selectorExec()))
    return (errorMalloc());
  my_bzero(map, MEM_SIZE);
  tmp = heros;
  writeHero(map, tmp);
  while (tmp->next)
    {
      tmp = tmp->next;
      writeHero(map, tmp);
    }
  tmp->next = heros;
#ifdef	DEBUG
  debugInitVm(data, heros);
#endif
  if (vm(data, heros, map, &array))
    return (free(map), free(array.load), free(array.exec),  1);
  return (free(map), free(array.load), free(array.exec), 0);
}
