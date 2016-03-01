/*
** affCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 12:56:32 2016 Antoine Baché
*/

#include "asm.h"
#include "bytecode.h"
#include "tools.h"

int	writeAff(int new, t_parsing *tmp)
{
  int		code;
  t_bytecode	byte;

  byte.bytecode = tmp->bytecode;
  code = getByteCode(&byte);
  if (!code && write(new, &tmp->reg[0], 1) < 0)
    return (1);
  if (code == 2 && !reverseShort((short *)&tmp->value[0]) &&
      write(new, &tmp->value[0], 2) < 0)
    return (1);
  if (code == 1 && !reverseInt(&tmp->value[0]) &&
      write(new, &tmp->value[0], 4) < 0)
    return (1);
  return (0);
}

int	affCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 4;
  if (data->str[*offset] == 'r')
    return (getRegisterSti(data, elem, offset, 1));
  else
    return (errorSyntax(data->line));
  return (0);
}
