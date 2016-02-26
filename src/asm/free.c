/*
** free.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 23:22:18 2016 Antoine Baché
** Last update Fri Feb 26 10:41:55 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"

void		free_elems(t_parsing *elem, char **ins)
{
  int		i;
  t_parsing	*tmp;

  while (elem->next)
    {
      tmp = elem;
      elem = elem->next;
      free(tmp);
    }
  free(elem);
  i = 0;
  while (i < 17)
    free(ins[i++]);
  free(ins);
}
