/*
** lforkCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 15:34:07 2016 Antoine Baché
*/

#include "asm.h"

int	writeLfork(int new, t_parsing *tmp, int endian)
{
  return (writeFork(new, tmp, endian));
}

int	lforkCase(t_data *data, t_parsing *elem, int *offset)
{
  ++(*offset);
  return (forkCase(data, elem, offset));
}
