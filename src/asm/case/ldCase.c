/*
** ldCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sat Mar  5 06:04:48 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	getIndiLd(t_data *data, t_parsing *elem, int *offset)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = (*offset)++;
  elem->bytecode |= 192;
  elem->size += 2;
  if (data->str[*offset] == ':')
    {
      if (getLabel(data, parseLabel(data, offset), elem, 0))
	return (1);
      return (--(*offset), 0);
    }
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if ((i = -1) && !(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] != '-' && (nb[i] < '0' || nb[i] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->value[0] = my_getnbr(nb)) < 0)
    warningIndirection(data->line);
  *offset = tmp;
  return (free(nb), 0);
}

int	getLabelLd(t_data *data, t_parsing *elem, int *offset)
{
  return (getLabel(data, parseLabel(data, offset), elem, 0));
}

int	getDirLd(t_data *data, t_parsing *elem, int *offset)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = (*offset)++;
  elem->size += 4;
  if (data->str[*offset] == ':')
    return (getLabel(data, parseLabel(data, offset), elem, 0));
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] != '-' && (nb[i] < '0' || nb[i] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->value[0] = my_getnbr(nb)) < 0)
    warningTooBig(data->line);
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
  elem->size++;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] < '0' || nb[i] > '9')
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
  if ((*offset += 1) &&
      (data->str[++(*offset)] != ' ' ||
       (data->str[(*offset) + 1] != '%' && data->str[(*offset) + 1] != ':' &&
	(data->str[(*offset) + 1] < '0' || data->str[(*offset) + 1] > '9'))))
    return (errorSyntax(data->line));
  if ((elem->size += 2) &&
      (data->str[(*offset) + 1] == ':' || data->str[(*offset) + 1] == '-' ||
       (data->str[(*offset + 1)] > '0' &&
	data->str[(*offset) + 1] < '9')) &&
      getIndiLd(data, elem, offset))
    return (1);
  else if (data->str[(*offset) + 1] == '%')
    {
      elem->bytecode |= 128;
      if (data->str[++(*offset) + 1] == ':' && getLabelLd(data, elem, offset))
	return (1);
      else if ((data->str[(*offset) + 1] == '-' ||
		(data->str[(*offset) + 1] >= '0' &&
		 data->str[(*offset) + 1] <= '9')) &&
	       getDirLd(data, elem, offset))
	return (1);
    }
  return ((data->str[*offset] != ',' || data->str[++(*offset)] != ' ' ||
	   data->str[++(*offset)] != 'r') ? errorSyntax(data->line) :
	  getRegLd(data, elem, offset));
}
