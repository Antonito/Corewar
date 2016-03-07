/*
** warnings.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:43:01 2016 Antoine Baché
** Last update Mon Mar  7 14:20:48 2016 Antoine Baché
*/

#include "errors.h"
#include "tools.h"

int	warningIndirection(int line)
{
  write(2, "Warning ", 8);
  write(2, "Indirection too far line ", 25);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (-1);
}

int	warningTooBig(int line)
{
  write(2, "Warning ", 8);
  write(2, "Direct too big line ", 20);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (-1);
}
