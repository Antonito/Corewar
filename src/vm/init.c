/*
** init.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 04:18:45 2016 Antoine Baché
** Last update Sat Mar 26 20:01:07 2016 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "corewar.h"
#include "common.h"
#include "errors.h"
#include "tools.h"

int		addHero(t_hero *hero, int nbHero)
{
  t_hero	*new;

  if (!(new = malloc(sizeof(t_hero))))
    return (errorMalloc());
  my_bzero(new, sizeof(t_hero));
  new->id = nbHero;
  new->loadAddress = -1;
  new->name = NULL;
  new->comment = NULL;
  new->pc = 0;
  new->size = 0;
  hero->reg[0] = hero->id;
  new->customId = false;
  new->customAddress = false;
  new->isAlive = false;
  new->carry = false;
  new->inst = NULL;
  new->next = NULL;
  hero->next = new;
  return (0);
}

t_hero		*initHero(t_hero *hero)
{
  if (!(hero = malloc(sizeof(t_hero))))
    return (errorMalloc(), NULL);
  my_bzero(hero, sizeof(t_hero));
  hero->id = 1;
  hero->loadAddress = -1;
  hero->name = NULL;
  hero->comment = NULL;
  hero->pc = 0;
  hero->size = 0;
  hero->customId = false;
  hero->customAddress = false;
  hero->carry = false;
  hero->reg[0] = hero->id;
  hero->isAlive = false;
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
  data->nbrLive = 0;
  data->isRunning = true;
}

void		writeHero(unsigned char *map, t_hero *hero)
{
  unsigned int	i;

  i = -1;
  while (++i < hero->size)
    {
      map[(hero->loadAddress + i) % MEM_SIZE] = hero->data[i];
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
  data->process = data->nbHeros;
#ifdef	DEBUG
  debugInitVm(data, heros);
#endif
  if (vm(data, genLive(heros, data), map, &array))
    return (free(map), free(array.load), free(array.exec),  1);
  return (free(map), free(array.load), free(array.exec), 0);
}
