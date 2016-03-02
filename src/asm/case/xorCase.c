/*
** xorCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Wed Mar  2 07:23:39 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "bytecode.h"
#include "tools.h"

int	writeXor(int new, t_parsing *tmp, int endian)
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
      if (code == 1 && !reverseInt(&tmp->value[i], endian) &&
	  write(new, &tmp->value[i], 4) < 0)
	return (1);
      if (code == 2 && !reverseShort((short *)&tmp->value[i], endian) &&
	  write(new, &tmp->value[i], 2) < 0)
	return (1);
      byte.bytecode <<= 2;
      ++i;
    }
  return (0);
}

int	getDirXor(t_data *data, t_parsing *elem, int *offset, int j)
{
  int	i;
  int	tmp;
  char	*nb;

  tmp = *offset;
  elem->size += 4;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = 0;
  while ((*offset) + i < tmp && (nb[i] = data->str[(*offset) + i]))
    if (nb[i] < '0' || nb[i++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[j] = my_getnbr(nb);
  *offset = tmp;
  elem->bytecode |= 128 >> (i << 1);
  free(nb);
  return (0);
}

int	checkDirXor(t_data *data, t_parsing *elem, int *offset, int i)
{
  elem->size += 2;
  if (data->str[++(*offset)] == ':')
    return (getLabel(data, elem));
  else if (data->str[*offset] >'0' && data->str[*offset] <= '9')
    {
      if (getDirXor(data, elem, offset, i))
	return (1);
    }
  else
    return (errorSyntax(data->line));
  return (0);
}

int	getIndirXor(t_data *data, t_parsing *elem, int *offset, int i)
{
  int	j;
  int	tmp;
  char	*nb;

  if (data->str[*offset] < '0' || data->str[*offset] > '9')
    return (errorSyntax(data->line));
  tmp = (*offset);
  elem->size += 2;
  while (data->str[tmp] && data->str[tmp] != ',' && ++tmp);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  j = 0;
  while ((*offset) + j < tmp && (nb[j] = data->str[(*offset) + j]))
    if (nb[j] < '0' || nb[j++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[i] = my_getnbr(nb);
  elem->bytecode |= 192 >> (i << 1);
  *offset = tmp;
  free(nb);
  return (0);
}

int	xorCase(t_data *data, t_parsing *elem, int *offset)
{
  int	i;

  if ((*offset += 2) && (elem->size += 2) && (i = 0))
    return (1);
  while (++i < 4)
    if (data->str[++(*offset)] == ' ' && data->str[++(*offset)] == 'r')
      {
	if (getRegisterSti(data, elem, offset, i))
	  return (1);
      }
    else if (data->str[(*offset) - 1] == ' ' && data->str[*offset] == '%'
	     && i < 3)
      {
	if (checkDirXor(data, elem, offset, i - 1))
	  return (0);
      }
    else if (data->str[(*offset) - 1] == ' ' && i < 3 &&
	     data->str[*offset] >= '0' && data->str[*offset] <= '9')
      {
	if (getIndirXor(data, elem, offset, i - 1))
	  return (1);
      }
    else
      return (errorSyntax(data->line));
  return (0);
}
