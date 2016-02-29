/*
** lldCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sun Feb 28 19:55:04 2016 Antoine Baché
*/

#include "asm.h"

int	write_lld(int new, t_parsing *tmp)
{
  return (write_ld(new, tmp));
}

int	lldCase(t_data *data, t_parsing *elem, int *offset)
{
  ++(*offset);
  return (ldCase(data, elem, offset));
}
