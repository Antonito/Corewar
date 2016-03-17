/*
** exec.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 13:59:41 2016 Antoine Baché
** Last update Thu Mar 17 12:19:38 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"
#include "errors.h"
#include "tools.h"

/*
** Execution -> Lecture -> Ajout a la liste d'exec -> return (0)
*/
int		readInst(t_hero *heros, unsigned char *map, ptrtab array,
			 int endianness)
{
  t_instruct	*tmp;
  t_instruct	*new;

  if (heros->pc != heros->size)
    {
      if (!(new = malloc(sizeof(t_instruct))))
	return (errorMalloc());
      my_bzero(new, sizeof(t_instruct));
      new->next = NULL;
      new->type = map[heros->loadAddress + heros->pc++];
      if (array[new->type % 17](heros, new, map, endianness))
	return (1);
      tmp = heros->inst;
      while (tmp && tmp->next)
	tmp = tmp->next;
      if (!tmp)
	heros->inst = new;
      else
	tmp->next = new;
    }
  return (0);
}

int		executeOrders(t_hero *heros, unsigned char *map, ptrtab array,
			      int endianness)
{
  /* Execute */
  if (readInst(heros, map, array, endianness))
    return (1);
  /* Baisser timer a ce moment */
  return (0);
}
