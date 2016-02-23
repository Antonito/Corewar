/*
** main.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:31:55 2016 Antoine Baché
** Last update Tue Feb 23 11:32:57 2016 Antoine Baché
*/

#include <unistd.h>

int	main(int ac, char **av, char **env)
{
  if (!*env)
    {
      write(2, "Missing environnement\n", 22);
      return (1);
    }
  return (0);
}
