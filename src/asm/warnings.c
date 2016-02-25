/*
** warnings.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:43:01 2016 Antoine Baché
** Last update Thu Feb 25 19:48:27 2016 Antoine Baché
*/

#include "errors.h"
#include "tools.h"

int	warningIndirection(int line)
{
  write(2, "Warning Indirection too far line ", 33);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (-1);
}

int	warningTooBig(int line)
{
  write(2, "Warning Direct too big line ", 28);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (-1);
}
