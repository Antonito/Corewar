/*
** dump.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 12 17:15:35 2016 Antoine Baché
** Last update Sat Mar 12 17:58:48 2016 Antoine Baché
*/

#include "common.h"
#include "tools.h"

int	writeMem(char nb)
{
  if (nb > 57)
    nb += 7;
  if (write(1, &nb, 1) < 0)
    return (1);
  return (0);
}

int	writeMemNb(int nb, bool first)
{
  if (first && nb < 10)
    write(1, "0", 1);
  (nb >= 10) ? writeMemNb(nb / 16, false) : 4;
  return (writeMem(nb % 16 + 48));
}

int	dumpMem(char *map)
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
	  (i + j < MEM_SIZE) ? writeMemNb(map[i + j], true) :
	    write(1, "00", 2);
	  ++j;
	}
      if (write(1, "\n", 1) < 0)
	return (write(2, "Error while writing on stdout\n", 30), 1);
      i += 32;
    }
  return (0);
}
