/*
** xorCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Wed Mar 16 19:34:59 2016 Antoine Baché
*/

#include "corewar.h"

int	xorCase(t_hero *hero, t_instruct *new, unsigned char *map,
		int endianness)
{
  return (andCase(hero, new, map, endianness));
}
