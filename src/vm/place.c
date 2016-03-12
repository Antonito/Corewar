/*
** place.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 05:50:51 2016 Antoine Baché
** Last update Sat Mar 12 17:34:37 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "common.h"

int		calcSize(t_hero *heros)
{
  int		size;
  t_hero	*tmp;

  tmp = heros;
  size = 0;
  while (tmp->next)
    {
      size += tmp->size;
      tmp = tmp->next;
    }
  size += tmp->size;
  return (size);
}

int		checkOverlap(t_hero *heros)
{
  t_hero	*tmp;
  t_hero	*tmp2;
  int		start;
  int		end;

  tmp = heros;
  while (tmp && (tmp2 = tmp->next))
    {
      start = tmp->loadAddress;
      end = start + tmp->size;
      while (tmp2)
	{
	  if (tmp2->loadAddress >= start && tmp2->loadAddress <= end)
	    return (write(2, "Overlap detected\n", 17), 1);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return (0);
}

int		placeHeros(t_hero *heros, int nbHeros)
{
  t_hero	*tmp;
  int		offset;
  int		totalSize;
  int		loop;

  totalSize = calcSize(heros);
  if (totalSize && nbHeros > MEM_SIZE / totalSize)
    return (write(2, "Not enough space to place heros\n", 32), 1);
  offset = MEM_SIZE / nbHeros;
  tmp = heros;
  loop = 0;
  while (tmp)
    {
      if (tmp->customAddress == false)
	tmp->loadAddress = offset * loop;
      tmp->loadAddress = tmp->loadAddress % MEM_SIZE;
      tmp = tmp->next;
      ++loop;
    }
  return (checkOverlap(heros));
}
