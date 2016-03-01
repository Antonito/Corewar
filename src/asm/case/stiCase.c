
/*
** stiCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 01:49:04 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	getIndirectSti(t_data *data, t_parsing *elem, int *offset, int i)
{
  if (data->str[++(*offset)] == ':')
    return (((getLabel(data, elem, offset, i + 1)) ? 1 : 0));
  else if (data->str[*offset] >'0' && data->str[*offset] <= '9')
    return (((getIndiValue(data, elem, offset, i + 1)) ? 1 : 0));
  else
    return (errorSyntax(data->line));
  return (0);
}

int	getRegisterSti(t_data *data, t_parsing *elem, int *offset, int i)
{
  int	tmp;
  char	size[3];

  if (data->str[*offset] != 'r')
    return (errorSyntax(data->line));
  tmp = *offset;
  while (data->str[++tmp] && data->str[tmp] != ',');
  size[2] = 0;
  size[1] = 0;
  if ((size[0] = data->str[*offset + 1]) > '9' || size[0] < '1')
    return (errorSyntax(data->line));
  if (tmp - *offset == 3 && ((size[1] = data->str[*offset + 2]) > '9' ||
			     size[1] < '1'))
    return (errorSyntax(data->line));
  if ((elem->reg[i - 1] = my_getnbr(size)) > 16 || elem->reg[i - 1] < 1 ||
      tmp - *offset > 3)
    return (errorRegister(data->line));
  elem->bytecode |= 64 >> ((i - 1) << 1);
  *offset = tmp;
  printf("STI = %d %d %d\n", elem->reg[0], elem->reg[1], elem->reg[2]);
  return (0);
}

int	stiCase(t_data *data, t_parsing *elem, int *offset)
{
  int	i;

  *offset += 4;
  if (getRegisterSti(data, elem, offset, 1))
    return (1);
  if (data->str[*offset] != ',' || data->str[++(*offset)] != ' ')
    return (errorSyntax(data->line));
  i = -1;
  while (++i < 2)
    if (data->str[++(*offset)] == '%')
      {
	elem->bytecode |= 128 >> ((i + 1) * 2);
	if (getIndirectSti(data, elem, offset, i + 1))
	  return (1);
      }
    else if (data->str[*offset] == 'r')
      {
	if (getRegisterSti(data, elem, offset, i + 2))
	  return (1);
	  ++(*offset);
      }
    else
      return (errorSyntax(data->line));
  return (0);
}
