/*
** getargs.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 13:34:43 2016 Antoine Baché
** Last update Fri Feb 26 15:00:05 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "errors.h"

int	getArgs(t_data *data, char *str, t_parsing *elem, int offset)
{
  if (data->list[elem->function](data, str, elem, &offset))
    return (1);
  return (0);
}
