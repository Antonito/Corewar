/*
** xorCase.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 01:03:06 2016 Antoine Baché
** Last update Thu Feb 25 13:56:46 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"
#include "tools.h"

int	xorIndirect(t_read *data)
{
  int	tmp;

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 2) < 0)
    return (1);
  tmp = data->buff[0] * 256 + data->buff[1];
  if (my_write_nb(tmp, 1, data->new) < 0)
    return (1);
  return (0);
}

int	xorDirect(t_read *data)
{
  int	tmp;

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 4) < 0)
    return (1);
  tmp = data->buff[0] * 256 * 256 * 256 +
    data->buff[1] * 256 * 256 + data->buff[2] * 256 + data->buff[3];
  if (write(data->new, "%", 1) < 0 ||
      my_write_nb(tmp, 1, data->new) < 0)
    return (1);
  return (0);
}

int		xorRegister(t_read *data)
{
  unsigned char	str[3];

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 1) < 0)
    return (1);
  if (data->buff[0] < 1 || data->buff[0] > 16)
    return (1);
  my_bzero(&str, 3);
  if (data->buff[0] <= 9)
    str[0] = data->buff[0] + '0';
  else
    {
      str[0] = '1';
      str[1] = (data->buff[0] - 10) + '0';
    }
  if (write(data->new, "r", 1) < 0 ||
      write(data->new, str, my_strlen((char *)str)) < 0)
    return (1);
  return (0);
}

int	xorCase(t_read *data)
{
  int	code;
  int	i;

  my_bzero(data->buff, 5);
  if (read(data->fd, data->buff, 1) < 0 ||
      write(data->new, data->inst[7], my_strlen(data->inst[7])) < 0)
    return (1);
  data->byte.bytecode = data->buff[0];
  i = -1;
  while (++i < 4)
    {
      code = getByteCode(&data->byte);
      my_bzero(data->buff, 5);
      if (!code && xorRegister(data))
	return (1);
      if (code == 1 && xorDirect(data))
	return (1);
      if (code == 2 && xorIndirect(data))
	return (1);
      if (code != -1 && i != 2 && write(data->new, ", ", 2) < 0)
	return (1);
      data->byte.bytecode <<= 2;
    }
  return (0);
}