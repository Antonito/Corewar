/*
** affCase.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 01:03:06 2016 Antoine Baché
** Last update Thu Feb 25 03:35:39 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"
#include "tools.h"

int		affRegister(t_read *data)
{
  unsigned char	str[3];

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 2) < 0)
    return (1);
  if (data->buff[0] != 64 || data->buff[1] < 1 || data->buff[1] > 16)
    return (1);
  my_bzero(&str, 3);
  if (data->buff[1] <= 9)
    str[0] = data->buff[1] + '0';
  else
    {
      str[0] = '1';
      str[1] = (data->buff[1] - 10) + '0';
    }
  if (write(data->new, "r", 1) < 0 ||
      write(data->new, str, my_strlen((char *)str)) < 0)
    return (1);
  return (0);
}

int	affCase(t_read *data)
{
  my_bzero(data->buff, 5);
  if (write(data->new, data->inst[15], my_strlen(data->inst[15])) < 0 ||
      affRegister(data))
    return (1);
  return (0);
}
