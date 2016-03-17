/*
** main.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 14:38:58 2016 Antoine Baché
** Last update Thu Mar 17 15:58:31 2016 Antoine Baché
*/

#include <unistd.h>
#include "corewar.h"

int	main(int ac, char **av, char **env)
{
  if (!env || check_args(ac, av))
    {
#ifdef	DEBUG
      write(1, "Status: KO\n", 11);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Status: OK\n", 11);
#endif
  return (0);
}
