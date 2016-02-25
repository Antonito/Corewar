/*
** free.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 18:50:52 2016 Antoine Baché
** Last update Wed Feb 24 18:54:09 2016 Antoine Baché
*/

#include <stdlib.h>

int	freeLoadChamp(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  return (1);
}
