/*
** stCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sat Mar  5 00:08:06 2016 Antoine Baché
*/

#include "asm.h"
#include "bytecode.h"
#include "tools.h"
#include "errors.h"

int	writeSt(int new, t_parsing *tmp, int endian)
{
  int		i;
  int		code;
  t_bytecode	byte;

  i = 0;
  if (write(new, &tmp->reg[i], 1) < 0)
    return (1);
  byte.bytecode = tmp->bytecode;
  byte.bytecode <<= 2;
  code = getByteCode(&byte);
  if (!code && write(new, &tmp->reg[i + 1], 1) < 0)
    return (1);
  if (code == 2 && !reverseShort((short *)&tmp->value[i], endian) &&
      write(new, &tmp->value[i], 2) < 0)
    return (1);
  if (code == 1)
    return (1);
  return (0);
}

int	stCaseInDirect(t_data *data, t_parsing *elem, int *offset)
{
  int	tmp;
  int	i;
  char	*nb;

  elem->bytecode |= 48;
  tmp = *offset;
  elem->size += 2;
  while (data->str[tmp++]);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = -1;
  while ((*offset) + ++i < tmp && (nb[i] = data->str[(*offset + i)]))
    if (nb[i] != '-' && (nb[i] < '0' || nb[i] > '9'))
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[0] = my_getnbr(nb);
  free(nb);
  return (0);
}

int	stCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 2;
  elem->size += 2;
  if (data->str[(*offset)++] != ' ' || data->str[*offset] != 'r')
    return (errorSyntax(data->line));
  if (getRegisterSti(data, elem, offset, 1))
    return (1);
  if (data->str[*offset] != ',' || data->str[++(*offset)] != ' ')
    return (errorSyntax(data->line));
  if (data->str[++(*offset)] == 'r')
    return (getRegisterSti(data, elem, offset, 2));
  else if (data->str[*offset] == '%')
    return (errorSyntax(data->line));
  else if (data->str[*offset] == '-' ||
	   (data->str[*offset] >= '0' && data->str[*offset] <= '9'))
    return (stCaseInDirect(data, elem, offset));
  else
    return (1);
  return (0);
}
