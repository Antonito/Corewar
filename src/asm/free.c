/*
** free.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 23:22:18 2016 Antoine Baché
** Last update Fri Mar  4 02:20:59 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"

void		free_elems(t_data *data)
{
  int		i;
  t_parsing	*tmp;
  t_label	*tmp2;

  while (data->elem->next)
    {
      tmp = data->elem;
      data->elem = data->elem->next;
      free(tmp);
    }
  free(data->elem);
  while (data->label->next)
    {
      tmp2 = data->label;
      data->label = data->label->next;
      free(tmp2->label);
      free(tmp2);
    }
  free(data->label->label);
  free(data->label);
  i = 0;
  while (i < 17)
    free(data->ins[i++]);
  free(data->ins);
  free(data->list);
}
