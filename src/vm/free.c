/*
** free.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 08:12:31 2016 Antoine Baché
** Last update Thu Mar 17 12:22:12 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"

void		freeInst(t_instruct *inst)
{
  t_instruct	*tmp;

  while (inst)
    {
      tmp = inst;
      inst = inst->next;
      free(tmp);
    }
}

void		freeHero(t_hero *hero, int nbHero)
{
  int		i;
  t_hero	*tmp;

  i = 0;
  while (i < nbHero)
    {
      if (hero->name)
	free(hero->name);
      if (hero->comment)
	free(hero->comment);
      if (hero->data)
	free(hero->data);
      freeInst(hero->inst);
      tmp = hero;
      hero = hero->next;
      free(tmp);
      tmp = NULL;
      i++;
    }
}
