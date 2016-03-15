/*
** order.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 05:31:49 2016 Antoine Baché
** Last update Tue Mar 15 15:19:29 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"

void		swapHero(t_hero *h1, t_hero *h2)
{
  t_hero	*tmp_next;
  t_hero	tmp;

  tmp = *h1;
  *h1 = *h2;
  h1->next = tmp.next;
  tmp_next = h2->next;
  *h2 = tmp;
  h2->next = tmp_next;
}

bool		isOrdered(t_hero *heros)
{
  t_hero	*tmp;
  t_hero	*tmp2;

  tmp = heros;
  while (tmp && (tmp2 = tmp->next))
    {
      while (tmp2)
	{
	  if (tmp->id >= tmp2->id)
	    return (false);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return (true);
}

int		orderHeros(t_hero *heros)
{
  t_hero	*tmp;
  t_hero	*tmp2;

  while (!isOrdered(heros) && (tmp = heros))
    {
      while (tmp && (tmp2 = tmp->next))
	{
	  while (tmp2)
	    {
	      if (tmp->id >= tmp2->id)
		{
		  if (tmp->id == tmp2->id && tmp->customId && tmp2->customId)
		    return (write(2, "Prog Number already used\n", 25), 1);
		  swapHero(tmp, tmp2);
		}
	      tmp2 = tmp2->next;
	    }
	  tmp = tmp->next;
	}
    }
  return (0);
}
