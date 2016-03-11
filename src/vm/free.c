/*
** free.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 08:12:31 2016 Antoine Baché
** Last update Fri Mar 11 08:46:26 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"

void		freeHero(t_hero *hero)
{
  t_hero	*tmp;

  while (hero)
    {
      free(hero->name);
      free(hero->comment);
      if (hero->data)
	free(hero->data);
      tmp = hero;
      hero = hero->next;
      free(tmp);
    }
}
