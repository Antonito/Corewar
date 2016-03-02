/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Wed Mar  2 03:03:32 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	writeZjmp(int new, t_parsing *tmp, int endian)
{
  if (!reverseShort((short *)&tmp->value[0], endian) &&
      write(new, &tmp->value[0], 2) < 0)
    return (1);
  return (0);
}

int	getLabelZjmp(t_data *data, t_parsing *elem, int *offset)
{
  return (0);
}

int	getZjmp(t_data *data, t_parsing *elem, int *offset)
{
  int	tmp;
  int	i;
  char	*nb;

  tmp = (*offset) - 1;
  elem->size += 2;
  while (data->str[++tmp]);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = 0;
  while ((*offset) + i < tmp && (nb[i] = data->str[(*offset + i)]))
    if (nb[i] < '0' || nb[i++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[0] = my_getnbr(nb);
  free(nb);
  return (0);
}

int	zjmpCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 3;
  elem->size++;
  if (data->str[++(*offset)] != ' ' || data->str[++(*offset)] != '%')
    return (errorSyntax(data->line));
  if (data->str[++(*offset)] == ':')
    return (getLabelZjmp(data, elem, offset));
  else if (data->str[*offset] > '0' && data->str[*offset] <= '9')
    return (getZjmp(data, elem, offset));
  else
    return (errorSyntax(data->line));
  return (0);
}