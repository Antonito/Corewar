/*
** check_args.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 14:43:06 2016 Antoine Baché
** Last update Thu Mar 10 14:01:46 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int	check_args(int ac, char **av)
{
  if (ac < 2 || !my_strncmp("-dump", av[1], 6))
    return (writeUsage(av[0]), 1);
  return (0);
}
