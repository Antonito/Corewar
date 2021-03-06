/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 01:03:06 2016 Antoine Baché
** Last update Thu Feb 25 03:19:42 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"
#include "tools.h"

int	liveCase(t_read *data)
{
  int	tmp;

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 4) < 0 ||
      write(data->new, data->inst[0], my_strlen(data->inst[0])) < 0)
    return (1);
  tmp = data->buff[0] * 256 * 256 * 256 +
    data->buff[1] * 256 * 256 + data->buff[2] * 256 + data->buff[3];
  if (write(data->new, "%", 1) < 0 ||
      my_write_nb(tmp, 1, data->new) < 0)
    return (1);
  return (0);
}
