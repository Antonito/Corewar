/*
** free.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 18:50:52 2016 Antoine Baché
** Last update Thu Feb 25 03:39:03 2016 Antoine Baché
*/

#include <stdlib.h>
#include "decompiler.h"

int	freeLoadChamp(char **tab, ptrtab ptr)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  free(ptr);
  return (1);
}
