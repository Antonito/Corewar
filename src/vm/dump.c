/*
** dump.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 17:15:35 2016 Antoine Baché
** Last update Tue Mar 22 18:29:19 2016 Antoine Baché
*/

#include "common.h"
#include "tools.h"

int	writeMemNb(int nb, bool first)
{
  if (first && nb < 16)
    write(1, "0", 1);
  if (nb < 10)
    my_putchar(nb + 48);
  else if (nb >= 10 && nb < 16)
    my_putchar(nb + 55);
  else
    {
      writeMemNb(nb / 16, false);
      writeMemNb(nb % 16, false);
    }
  return (0);
}

int	dumpMem(unsigned char *map)
{
  int	i;
  int	j;

  i = 0;
  while (j = 0, i < MEM_SIZE)
    {
      if (writeMemNb(i, true) || write(1, "\t:", 2) < 0)
	return (write(2, "Error while writing on stdout\n", 30), 1);
      while (j < 32)
	{
	  if (write(1, " ", 1) < 0)
	    return (write(2, "Error while writing on stdout\n", 30), 1);
	  (i + j < MEM_SIZE) ? writeMemNb(map[(i + j) % MEM_SIZE], true) :
	    write(1, "00", 2);
	  ++j;
	}
      if (write(1, "\n", 1) < 0)
	return (write(2, "Error while writing on stdout\n", 30), 1);
      i += 32;
    }
  return (0);
}
