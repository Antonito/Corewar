/*
** forkCase.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 01:03:06 2016 Antoine Baché
** Last update Thu Feb 25 03:32:20 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"
#include "tools.h"

int	forkCase(t_read *data)
{
  int	tmp;

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 2) < 0 ||
      write(data->new, data->inst[11], my_strlen((char *)data->inst[11])) < 0)
    return (1);
  tmp = data->buff[0] * 256 + data->buff[1];
  if (write(data->new, "%", 1) < 0 ||
      my_write_nb(tmp, 1, data->new) < 0)
    return (1);
  return (0);
}
