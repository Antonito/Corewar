/*
** value.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:43:21 2016 Antoine Baché
** Last update Wed Mar 16 15:46:38 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int	readInt(t_hero *hero, unsigned char *map, int endianness)
{
  int	i;
  int	value_nb;
  char	*tmp;

  i = -1;
  tmp = (char *)&value_nb;
  while (++i < 4 &&
	 (tmp[i] = map[hero->loadAddress + hero->pc + i]) > -1);
  hero->pc += 4;
  reverseInt(&value_nb, endianness);
  return (value_nb);
}

short	readShort(t_hero *hero, unsigned char *map, int endianness)
{
  int	i;
  short	value_nb;
  char	*tmp;

  i = -1;
  tmp = (char *)&value_nb;
  while (++i < 2 &&
	 (tmp[i] = map[hero->loadAddress + hero->pc + i]) > -1);
  hero->pc += 2;
  reverseShort(&value_nb, endianness);
  return (value_nb);
}
