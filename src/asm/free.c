/*
** free.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 23:22:18 2016 Antoine Baché
** Last update Thu Feb 25 23:26:11 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"

void		free_elems(t_parsing *elem)
{
  t_parsing	*tmp;

  while (elem->next)
    {
      tmp = elem;
      elem = elem->next;
      free(tmp);
    }
  free(elem);
}
