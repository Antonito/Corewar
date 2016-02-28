/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sun Feb 28 04:42:05 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"

int	getIndiLd(t_data *data, t_parsing *elem, int *offset)
{
  elem->bytecode |= 127;
  return (0);
}

int	getLabelLd(t_data *data, t_parsing *elem, int *offset)
{
  return (0);
}

int	getDirLd(t_data *data, t_parsing *elem, int *offset)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = (*offset)++;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = 0;
  while ((*offset) + i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] < '0' || nb[i++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[0] = my_getnbr(nb);
  *offset = tmp;
  free(nb);
  return (0);
}

int	getRegLd(t_data *data, t_parsing *elem, int *offset)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = (*offset)++;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = 0;
  while ((*offset) + i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] < '0' || nb[i++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->reg[0] = my_getnbr(nb)) > 16 || elem->reg[0] < 1)
    return (errorRegister(data->line));
  *offset = tmp;
  elem->bytecode |= 64 >> 2;
  free(nb);
  return (0);
}

int	ldCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 1;
  if (data->str[++(*offset)] != ' ' || (data->str[(*offset) + 1] != '%' &&
					(data->str[(*offset) + 1] < '1' ||
					 data->str[(*offset) + 1] > '9')))
    return (errorSyntax(data->line));
  if (data->str[(*offset + 1)] > '0' && data->str[(*offset) + 1] < '9' &&
      getIndiLd(data, elem, offset))
    return (1);
  else if (data->str[(*offset) + 1] == '%')
    {
      elem->bytecode |= 128;
      if (data->str[++(*offset) + 1] == ':' && getLabelLd(data, elem, offset))
	return (1);
      else if (data->str[(*offset) + 1] > '0' &&
	       data->str[(*offset) + 1] <='9' && getDirLd(data, elem, offset))
	return (1);
    }
  if (data->str[*offset] != ',' || data->str[++(*offset)] != ' ' ||
      data->str[++(*offset)] != 'r')
    return (errorSyntax(data->line));
  if (getRegLd(data, elem, offset))
    return (1);
  return (0);
}
