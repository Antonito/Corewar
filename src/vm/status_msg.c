/*
** statusMsg.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar 10 14:07:58 2016 Antoine Baché
** Last update Sat Mar 26 18:28:38 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"

int		playerAlive(int nb, char *name)
{
  if (write(1, "le joueur ", 10) < 0 ||
      my_write_nb(nb, 1, 1) < 0 ||
      write(1, " (", 2) < 0 ||
      write(1, name, my_strlen(name)) < 0 ||
      write(1, ") est en vie\n", 13) < 0)
    return (1);
  return (0);
}

int	playerWins(int nb, char *name)
{
  if (write(1, "le joueur ", 10) < 0 ||
      my_write_nb(nb, 1, 1) < 0 ||
      write(1, " (", 2) < 0 ||
      write(1, name, my_strlen(name)) < 0 ||
      write(1, ") a gagn", 8) < 0 ||
      write(1, "e", 1) < 0 ||
      write(1, "\n", 1) < 0)
    return (1);
  return (0);
}
