/*
1;4204;0c** select.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 00:47:20 2016 Antoine Baché
** Last update Wed Mar  2 07:16:00 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"

int		errorInst(t_data *data, t_parsing *elem, int *offset)
{
  (void)data;
  (void)elem;
  (void)offset;
  return (1);
}

int		errorWrite(int fd, t_parsing *tmp, int endian)
{
  (void)fd;
  (void)tmp;
  (void)endian;
  return (0);
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

writetab       	selector_write(void)
{
  writetab	array;

  if ((array = malloc(sizeof(int *) * 17)) == NULL)
    return (NULL);
  array[0] = &writeLive;
  array[1] = &writeLd;
  array[2] = &writeSt;
  array[3] = &writeAdd;
  array[4] = &writeSub;
  array[5] = &writeAnd;
  array[6] = &writeOr;
  array[7] = &writeXor;
  array[8] = &writeZjmp;
  array[9] = &writeLdi;
  array[10] = &writeSti;
  array[11] = &writeFork;
  array[12] = &writeLld;
  array[13] = &writeLldi;
  array[14] = &writeLfork;
  array[15] = &writeAff;
  array[16] = &errorWrite;
  return (array);
}
