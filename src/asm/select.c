/*
** select.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 00:47:20 2016 Antoine Baché
** Last update Mon Feb 29 23:33:53 2016 Antoine Baché
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

int		errorWrite(int fd, t_parsing *tmp)
{
  (void)fd;
  (void)tmp;
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
  array[0] = &write_live;
  array[1] = &write_ld;
  array[2] = &stCase;
  array[3] = &write_add;
  array[4] = &write_sub;
  array[5] = &andCase;
  array[6] = &orCase;
  array[7] = &xorCase;
  array[8] = &write_zjmp;
  array[9] = &ldiCase;
  array[10] = &write_sti;
  array[11] = &write_fork;
  array[12] = &write_lld;
  array[13] = &lldiCase;
  array[14] = &write_lfork;
  array[15] = &affCase;
  array[16] = &errorWrite;
  return (array);
}
