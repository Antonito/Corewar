/*
** writeUsage.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar 10 13:54:35 2016 Antoine Baché
** Last update Thu Mar 10 13:59:41 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"

int	writeUsage(char *str)
{
  if (write(2, "Usage: ", 7) < 0 ||
      write(2, str, my_strlen(str)) < 0 ||
      write(2, " [-dump nbr_cycle] [[-n prog_number]", 36)< 0 ||
      write(2, " [-a load_address] prog_name] ...\n", 34) < 0)
    return (1);
  return (0);
}
