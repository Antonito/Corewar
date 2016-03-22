/*
** findEndian.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  1 14:48:25 2016 Antoine Baché
** Last update Tue Mar  1 14:59:39 2016 Antoine Baché
*/

#include "endianness.h"

int		findEndian(void)
{
  t_endianness	check;

  check.intvalue = 0x01020304;
  if (check.value[0] == 0x01)
    return (BIG_ENDIAN);
  else if (check.value[0] == 0x04)
    return (LITTLE_ENDIAN);
  return (UNKNOWN);
}
