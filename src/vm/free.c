/*
** free.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 08:12:31 2016 Antoine Baché
** Last update Sat Mar 12 19:05:13 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"

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
      tmp = hero;
      hero = hero->next;
      free(tmp);
      tmp = NULL;
      i++;
    }
}
