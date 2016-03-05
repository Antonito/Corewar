/*
** ldiCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sat Mar  5 20:01:09 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "bytecode.h"
#include "tools.h"

int	writeLdi(int new, t_parsing *tmp, int endian)
{
  int		i;
  int		code;
  t_bytecode	byte;

  i = 0;
  byte.bytecode = tmp->bytecode;
  while (i < 3)
    {
      code = getByteCode(&byte);
      if (!code && write(new, &tmp->reg[i], 1) < 0)
	return (1);
      if (code == 1 && !reverseShort((short *)&tmp->value[i], endian) &&
	  write(new, &tmp->value[i], 2) < 0)
	return (1);
      if (code == 2 && !reverseShort((short *)&tmp->value[i], endian) &&
	  write(new, &tmp->value[i], 2) < 0)
	return (1);
      byte.bytecode <<= 2;
      ++i;
    }
  return (0);
}

int	getDirLdi(t_data *data, t_parsing *elem, int *offset, int j)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = *offset;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] != '-' && (nb[i] < '0' || nb[i] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->value[j] = my_getnbr(nb)) < 0)
    warningTooBig(data->line);
  *offset = tmp;
  elem->bytecode |= 128 >> (j << 1);
  free(nb);
  return (0);
}

int	checkDirLdi(t_data *data, t_parsing *elem, int *offset, int i)
{
  elem->size += 2;
  if (data->str[++(*offset)] == ':')
    {
      elem->bytecode |= 128 >> (i << 1);
      if (getLabel(data, parseLabel(data, offset), elem, i))
	return (1);
    }
  else if (data->str[*offset] == '-' ||
	   (data->str[*offset] >= '0' && data->str[*offset] <= '9'))
    {
      if (getDirLdi(data, elem, offset, i))
	return (1);
      ++(*offset);
    }
  else
    return (errorSyntax(data->line));
  return (0);
}

int	getIndirLdi(t_data *data, t_parsing *elem, int *offset, int i)
{
  int	j;
  int	tmp;
  char	*nb;

  if (((data->str[*offset] < '0' || data->str[*offset] > '9')) &&
      data->str[*offset] != '-' && data->str[*offset] != ':')
    return (errorSyntax(data->line));
  if ((elem->size += 2) && data->str[*offset] == ':')
    return (getLabel(data, parseLabel(data, offset), elem, i));
  if (data->str[*offset] != '-' && (tmp = (*offset)) &&
      (data->str[*offset] < '0' || data->str[*offset] > '9'))
    return (errorSyntax(data->line));
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if ((j = -1) && !(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  while ((*offset) + ++j < tmp && (nb[j] = data->str[(*offset) + j]))
    if (nb[j] != '-' && (nb[j] < '0' || nb[j] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  if ((elem->value[i] = my_getnbr(nb)) < 0)
    warningIndirection(data->line);
  elem->bytecode |= 192 >> (i << 1);
  *offset = tmp;
  return (free(nb), 0);
}

int	ldiCase(t_data *data, t_parsing *elem, int *offset)
{
  int	i;

  if ((*offset += 2) && (elem->size += 2) && !(i = 0) &&
      data->str[++(*offset)] != ' ')
    return (errorSyntax(data->line));
  while (++i < 4)
    if (data->str[++(*offset)] == 'r')
      {
	if (getRegisterSti(data, elem, offset, i))
	  return (1);
	++(*offset);
      }
    else if (data->str[*offset] == '%' && i < 3)
      {
	if (checkDirLdi(data, elem, offset, i - 1))
	  return (1);
      }
    else if (i < 2)
      {
	if (getIndirLdi(data, elem, offset, i - 1))
	  return (1);
      }
    else
      return (errorSyntax(data->line));
  return (0);
}
