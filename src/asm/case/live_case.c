/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sat Mar  5 20:25:18 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	writeLive(int new, t_parsing *tmp, int endian)
{
  if (!reverseInt(&tmp->value[0], endian) && write(new, &tmp->value[0], 4) < 0)
    return (1);
  return (0);
}

int	getLive(t_data *data, t_parsing *elem, int *offset)
{
  int	tmp;
  int	i;
  char	*nb;

  tmp = (*offset) - 1;
  elem->size += 4;
  while (data->str[++tmp]);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset + i)]))
    if (nb[i] != '-' && (nb[i] < '0' || nb[i] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->value[0] = my_getnbr(nb)) < 0)
    warningTooBig(data->line);
  free(nb);
  return (0);
}

int	liveCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 3;
  elem->size++;
  if (data->str[++(*offset)] != ' ' || data->str[++(*offset)] != '%')
    return (errorSyntax(data->line));
  if (data->str[++(*offset)] == ':')
    return (getLabel(data, parseLabel(data, offset), elem, 0));
  else if (data->str[*offset] == '-' ||
	   (data->str[*offset] >= '0' && data->str[*offset] <= '9'))
    return (getLive(data, elem, offset));
  else
    return (errorSyntax(data->line));
  return (0);
}
