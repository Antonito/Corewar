/*
** lldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 23:31:16 2016 Antoine Baché
*/

#include "corewar.h"

int	lldiExec(t_hero *hero, t_instruct *new, unsigned char *map,
		 t_params *params)
{
  return (ldiExec(hero, new, map, params));
}
