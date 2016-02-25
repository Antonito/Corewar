/*
** write_indirect.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 20:40:43 2016 Antoine Baché
** Last update Wed Feb 24 22:07:32 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"

int	write_indirect(int new, unsigned char *buff, int fd)
{
  my_bzero(buff, 5);
  if (read(fd, buff, 2) < 0)
    return (1);
  return (0);
}
