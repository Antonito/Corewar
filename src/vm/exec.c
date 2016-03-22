/*
** exec.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 13:59:41 2016 Antoine Baché
** Last update Tue Mar 22 17:48:12 2016 Antoine Baché
*/

#include <stdlib.h>
#include "corewar.h"
#include "errors.h"
#include "tools.h"

/*
** Execution -> Lecture -> Ajout a la liste d'exec -> return (0)
*/
int		readInst(t_hero *heros, unsigned char *map, ptrtab load,
			 int endianness)
{
  t_instruct	*tmp;
  t_instruct	*new;

  if ((!heros->inst || !heros->inst->time) && heros->pc < heros->size)
    {
      if (!(new = malloc(sizeof(t_instruct))))
	return (errorMalloc());
      my_bzero(new, sizeof(t_instruct));
      new->next = NULL;
      new->type = map[(heros->loadAddress + heros->pc++) % MEM_SIZE];
      if (load[new->type % 17](heros, new, map, endianness))
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

void		updateTimer(t_instruct *inst)
{
  t_instruct	*tmp;

  tmp = inst;
  while (tmp)
    {
      (tmp->time > 0) ? --tmp->time : (tmp->time = 0);
      tmp = tmp->next;
    }
}

int		executeInst(t_hero *heros, unsigned char *map,
			    ptrtab exec, int endianness)
{
  t_instruct	*tmp;
  t_instruct	*tmp2;

  tmp = heros->inst;
  while (tmp)
    {
      if (tmp2 = heros->inst, !tmp->time)
	{
	  if (exec[tmp->type % 17](heros, tmp, map, endianness))
	    return (1);
	  while (tmp2 != tmp && ((tmp2 == tmp) ? 0 : tmp2->next != tmp))
	    tmp2 = tmp2->next;
	  if (tmp2 == tmp && (heros->inst = heros->inst->next, free(tmp), 1))
	    tmp = NULL;
	  else if (tmp2->next = tmp->next, free(tmp), 1)
	    tmp = tmp2;
	}
      if (tmp)
	tmp = tmp->next;
    }
  return (0);
}

int		executeOrders(t_hero *heros, unsigned char *map,
			      t_funcPtr *array, int endianness)
{
  if (executeInst(heros, map, array->exec, endianness))
    return (1);
  if (readInst(heros, map, array->load, endianness))
    return (1);
  updateTimer(heros->inst);
  return (0);
}
