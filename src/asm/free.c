/*
** free.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 23:22:18 2016 Antoine Baché
** Last update Sun Feb 28 04:52:06 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"

void		free_elems(t_data *data)
{
  int		i;
  t_parsing	*tmp;

  while (data->elem->next)
    {
      tmp = data->elem;
      data->elem = data->elem->next;
      free(tmp);
    }
  free(data->elem);
  i = 0;
  while (i < 17)
    free(data->ins[i++]);
  free(data->ins);
  free(data->list);
}
