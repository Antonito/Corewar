/*
** a.c for Corewar in /CPE_2015_corewar/src/vm/options
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 05:08:44 2016 Antoine Baché
** Last update Tue Mar 22 19:42:03 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "common.h"
#include "tools.h"

int	aOption(t_hero *heros, int i, char **av)
{
  int	tmp;

  if (!(av[i]) || !isNum(av[i]))
    return (write(2, "Invalid load_address\n", 21), 1);
  if ((tmp = my_getnbr(av[i])) < 0)
    return (write(2, "Invalid load_address\n", 21), 1);
  heros->loadAddress = tmp % MEM_SIZE;
  heros->customAddress = true;
  return (0);
}
