/*
** errors.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar 10 14:03:37 2016 Antoine Baché
** Last update Thu Mar 10 14:13:09 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"

int	errorFileName(char *name)
{
  write(2, name, my_strlen(name));
  write(2, " is not a corewar executable\n", 29);
  return (1);
}

int	errorUsed(int progNb)
{
  write(2, "prog number ", 12);
  my_write_nb(progNg, 1, 2);
  write(2, " already used\n", 14);
  return (1);
}
