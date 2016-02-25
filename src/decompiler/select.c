/*
** select.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 00:47:20 2016 Antoine Baché
** Last update Thu Feb 25 01:41:05 2016 Antoine Baché
*/

#include <stdlib.h>
#include "decompiler.h"

int		errorInst(t_read *data)
{
  (void)data;
  return (1);
}

ptrtab		selector(void)
{
  ptrtab	array;

  if ((array = malloc(sizeof(int *) * 17)) == NULL)
    return (NULL);
  array[0] = &liveCase;
  array[1] = &ldCase;
  array[2] = &stCase;
  array[3] = &addCase;
  array[4] = &subCase;
  array[5] = &andCase;
  array[6] = &orCase;
  array[7] = &xorCase;
  array[8] = &zjmpCase;
  array[9] = &ldiCase;
  array[10] = &stiCase;
  array[11] = &forkCase;
  array[12] = &lldCase;
  array[13] = &lldiCase;
  array[14] = &lforkCase;
  array[15] = &affCase;
  array[16] = &errorInst;
  return (array);
}
