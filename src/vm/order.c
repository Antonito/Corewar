/*
** order.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 05:31:49 2016 Antoine Baché
** Last update Tue Mar 15 14:14:09 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"

/*
** t_hero->id // t_hero->customId
*/
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
		  if (tmp->customId && tmp2->customId)
		    return (write(2, "Prog Number already used\n", 25), 1);
		}
	      tmp2 = tmp2->next;
	    }
	  tmp = tmp->next;
	}
    }
  return (0);
}
