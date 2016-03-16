/*
** select.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:05:21 2016 Antoine Baché
** Last update Wed Mar 16 15:01:43 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"

int		errorInst(t_hero *heros, t_instruct *new, unsigned char *map,
			  int endianness)
{
  (void)heros;
  (void)new;
  (void)map;
  (void)endianness;
  write(2, "Corrupted champion\n", 19);
  return (1);
}

ptrtab		selector(void)
{
  ptrtab	array;

  if ((array = malloc(sizeof(int *) * 17)) == NULL)
    return (NULL);
  array[0] = &errorInst;
  array[1] = &liveCase;
  array[2] = &ldCase;
  array[3] = &stCase;
  array[4] = &addCase;
  array[5] = &subCase;
  array[6] = &andCase;
  array[7] = &orCase;
  array[8] = &xorCase;
  array[9] = &zjmpCase;
  array[10] = &ldiCase;
  array[11] = &stiCase;
  array[12] = &forkCase;
  array[13] = &lldCase;
  array[14] = &lldiCase;
  array[15] = &lforkCase;
  array[16] = &affCase;
  return (array);
}
