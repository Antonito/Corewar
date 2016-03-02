/*
** xorCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Wed Mar  2 03:03:25 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"

int	writeXor(int new, t_parsing *tmp, int endian)
{
  if (write(new, &tmp->reg[0], 1) < 0 || write(new, &tmp->reg[1], 1) < 0 ||
      write(new, &tmp->reg[2], 1) < 0)
    return (1);
  return (0);
}

int	xorCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 3;
  elem->size += 2;
  if (data->str[*offset] != ' ' || data->str[++(*offset)] != 'r')
    return (errorSyntax(data->line));
  if (getRegisterSti(data, elem, offset, 1))
    return (1);
  if (data->str[*offset] != ',' || data->str[++(*offset)] != ' ' ||
      data->str[++(*offset)] != 'r')
    return (errorSyntax(data->line));
  if (getRegisterSti(data, elem, offset, 2))
    return (1);
  if (data->str[*offset] != ',' || data->str[++(*offset)] != ' ' ||
      data->str[++(*offset)] != 'r')
    return (errorSyntax(data->line));
  return (getRegisterSti(data, elem, offset, 3));
}
