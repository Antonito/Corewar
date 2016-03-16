/*
** subCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 21:58:30 2016 Lucas Troncy
*/

#include "corewar.h"

int	subCase(t_hero *hero, t_instruct *new, unsigned char *map,
		int endianness)
{
  addCase(hero, new, map, endianness);
  new->time = SUB_TIME;
  return (0);
}
