/*
** n.c for Corewar in /CPE_2015_corewar/src/vm/options
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 05:08:44 2016 Antoine Baché
** Last update Sat Mar 12 05:35:18 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"
#include "tools.h"

int	nOption(t_hero *heros, int i, char **av)
{
  if (!(av[i]) || !isNum(av[i]))
    return (write(2, "Invalid prog_number\n", 20), 1);
  if ((heros->id = my_getnbr(av[i])) < 0 || heros->id > (MAX_HERO - 1))
    return (write(2, "Invalid prog_number\n", 20), 1);
  heros->customId = true;
  return (0);
}
