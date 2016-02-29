/*
** lforkCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sun Feb 28 19:58:26 2016 Antoine Baché
*/

#include "asm.h"

int	write_lfork(int new, t_parsing *tmp)
{
  return (write_fork(new, tmp));
}

int	lforkCase(t_data *data, t_parsing *elem, int *offset)
{
  ++(*offset);
  return (forkCase(data, elem, offset));
}
