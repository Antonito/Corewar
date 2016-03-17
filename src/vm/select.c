/*
** select.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:05:21 2016 Antoine Baché
** Last update Thu Mar 17 15:40:46 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"

int		errorExec(t_hero *heros, t_instruct *new, unsigned char *map,
			  int endianness)
{
  (void)heros;
  (void)new;
  (void)map;
  (void)endianness;
  return (1);
}

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

ptrtab		selectorExec(void)
{
  ptrtab	array;

  if ((array = malloc(sizeof(int *) * 17)) == NULL)
    return (NULL);
  array[0] = &errorExec;
  array[1] = &liveExec;
  array[2] = &ldExec;
  array[3] = &stExec;
  array[4] = &addExec;
  array[5] = &subExec;
  array[6] = &andExec;
  array[7] = &orExec;
  array[8] = &xorExec;
  array[9] = &zjmpExec;
  array[10] = &ldiExec;
  array[11] = &stiExec;
  array[12] = &forkExec;
  array[13] = &lldExec;
  array[14] = &lldiExec;
  array[15] = &lforkExec;
  array[16] = &affExec;
  return (array);
}
