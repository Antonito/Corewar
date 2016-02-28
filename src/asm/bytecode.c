/*
** bytecode.c for Corewar in /home/bache_a/work/Prog_Elem/CPE_2015_corewar
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 23:29:26 2016 Antoine Baché
** Last update Sat Feb 27 23:29:27 2016 Antoine Baché
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
