/*
** addCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 15:30:32 2016 Antoine Baché
*/

#include <unistd.h>
#include "asm.h"

int	writeAdd(int new, t_parsing *tmp, int endian)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (write(new, &tmp->reg[i], 1) < 0)
	return (1);
      ++i;
    }
  return (0);
}

int	addCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 4;
  elem->bytecode = 84;
  if (getRegisterSti(data, elem, offset, 1) || !(*offset += 2) ||
      getRegisterSti(data, elem, offset, 2) || !(*offset += 2) ||
      getRegisterSti(data, elem, offset, 3))
    return (1);
  return (0);
}
