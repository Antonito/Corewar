/*
** lforkCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 23 12:21:32 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"
#include "errors.h"

int		lforkExec(t_hero *hero, t_instruct *new, unsigned char *map,
			  t_params *params)
{
  t_hero	*newHero;

#ifdef	DEBUG
  write(1, "[Exec] LFork\n", 13);
#endif
  (void)map;
  if (!(newHero = malloc(sizeof(t_hero))))
    return (errorMalloc());
  my_bzero(newHero, sizeof(t_hero));
  newHero->id = hero->id;
  newHero->loadAddress = hero->loadAddress;
  newHero->name = hero->name;
  newHero->comment = hero->comment;
  newHero->pc = (hero->loadAddress + hero->pc + new->args[0]);
  newHero->size = hero->size;
  newHero->customId = hero->customId;
  newHero->customAddress = hero->customAddress;
  newHero->isAlive = hero->isAlive;
  newHero->carry = hero->carry;
  newHero->inst = NULL;
  newHero->next = hero->next;
  hero->next = newHero;
  ++params->process;
  cpyReg(hero, newHero);
  return (0);
}
