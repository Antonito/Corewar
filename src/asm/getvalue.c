/*
** getvalue.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 06:31:20 2016 Antoine Baché
** Last update Fri Mar  4 17:35:18 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	getDirValue(t_data *data, t_parsing *elem, int *offset, int id)
{
  int	tmp;
  int	i;
  char	*nb;

  tmp = (*offset) - 1;
  while (data->str[++tmp] && data->str[tmp] != ',' && data->str[tmp] != '\n')
    if (data->str[tmp] != '-' &&
	(data->str[tmp] < '0' || data->str[tmp] > '9'))
      return (errorSyntax(data->line));
  if (data->str[tmp] != 0 && data->str[tmp] != ',' && data->str[tmp] != '\n')
    return (errorSyntax(data->line));
  if (!(nb = malloc(sizeof(char *) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while (++i < (tmp - (*offset)))
    nb[i] = data->str[(*offset) + i];
  nb[(tmp - *offset)] = 0;
  elem->value[id - 1] = my_getnbr(nb);
  *offset = ++tmp;
  free(nb);
  return (0);
}
