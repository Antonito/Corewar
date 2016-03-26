/*
** order.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 05:31:49 2016 Antoine Baché
** Last update Sat Mar 26 21:15:57 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"

void		getLowest(t_hero *heros)
{
  static int	check = 0;
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = 100000;
  while (tmp)
    {
      if (tmp->id < i && !tmp->customId)
	i = tmp->id;
      tmp = tmp->next;
    }
  if (i != 1 && ++check < 100)
    {
      tmp = heros;
      while (tmp)
	{
	  if (!tmp->customId)
	    tmp->id--;
	  if (tmp->id < i && !tmp->customId)
	    i = tmp->id;
	  tmp = tmp->next;
	}
      getLowest(heros);
    }
}

void		swapHero(t_hero *h1, t_hero *h2)
{
  t_hero	*tmp_next;
  t_hero	tmp;

  if (h1->id != h2->id || h2->customId)
    {
      tmp = *h1;
      *h1 = *h2;
      h1->next = tmp.next;
      tmp_next = h2->next;
      *h2 = tmp;
      h2->next = tmp_next;
    }
  else
    {
      if (!h2->customId)
	++h2->id;
    }
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

  getLowest(heros);
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
