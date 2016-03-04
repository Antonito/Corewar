/*
** getargs.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 13:34:43 2016 Antoine Baché
** Last update Fri Mar  4 02:42:28 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "errors.h"

int	getArgs(t_data *data, t_parsing *elem, int offset)
{
  if (data->list[(int)elem->function](data, elem, &offset))
    return (1);;
  return (0);
}
