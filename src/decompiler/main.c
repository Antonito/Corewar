/*
** main.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:42:15 2016 Antoine Baché
** Last update Tue Feb 23 16:20:04 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"

int	parse(char *str)
{
  if (check_file(str))
    return (1);
  return (0);
}

int	arg_error(void)
{
  write(1, "Usage : ./decompiler [file]\n", 28);
  return (1);
}

int	main(int ac, char **av, char **env)
{
  if (!env)
    {
      write(2, "Missing environnement\n", 22);
      return (1);
    }
  if (ac != 2)
    return (arg_error());
  if (parse(av[1]))
    return (1);
  return (0);
}
