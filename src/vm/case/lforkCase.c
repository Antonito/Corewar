/*
** lforkCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 18:28:30 2016 Antoine Baché
*/

#include "corewar.h"

int		lforkExec(t_hero *hero, t_instruct *new, unsigned char *map,
			  int endianness)
{
  return (forkExec(hero, new, map, endianness));
}
