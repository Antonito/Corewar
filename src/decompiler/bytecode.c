/*
** bytecode.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 01:20:14 2016 Antoine Baché
** Last update Thu Feb 25 01:20:50 2016 Antoine Baché
*/

#include "bytecode.h"

int	getByteCode(t_bytecode *byte)
{
  if (!byte->bits.eight && byte->bits.seven)
    return (0);
  else if (byte->bits.eight && !byte->bits.seven)
    return (1);
  else if (byte->bits.eight && byte->bits.seven)
    return (2);
  return (-1);
}
