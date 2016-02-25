/*
** write_direct.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 20:30:04 2016 Antoine Baché
** Last update Wed Feb 24 22:35:46 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"

int	write_direct(int new, unsigned char *buff, int fd)
{
  int			tmp;

  my_bzero(buff, 5);
  if (read(fd, buff, 2) < 0)
    return (1);
  tmp = buff[0] * 256 + buff[1];
  if (write(new, "%", 1) < 0 || my_write_nb(tmp, 1, new) < 0)
    return (1);
  return (0);
}
