/*
** dump.c for Corewar in /CPE_2015_corewar/src/vm/options
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 03:59:57 2016 Antoine Baché
** Last update Sat Mar 26 19:31:57 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "tools.h"

int	dumpOption(char **av, t_params *data)
{
  if (!av[2] || !isNum(av[2]))
    return (write(2, "Invalid nbr_cycle\n", 18), 1);
  if ((data->nbrCycleDump = my_getnbr(av[2])) < 0)
    return (write(2, "Invalid nbr_cycle\n", 18), 1);
  return (0);
}
