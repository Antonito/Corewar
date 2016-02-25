/*
** my_write.c for Corewar in /home/bache_a/work/Prog_Elem/CPE_2015_corewar
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 22:19:40 2016 Antoine Baché
** Last update Thu Feb 25 03:13:34 2016 Antoine Baché
*/

#include <unistd.h>

int	my_write(char c, int fd)
{
  return (write(fd, &c, 1));
}

int     my_write_nb(int nb, int i, int fd)
{
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  write(fd, "2147483648", 10);
	  return (0);
	}
      write(fd, "-", 1);
      i++;
      nb = -nb;
    }
  (nb >= 10) ? i += my_write_nb(nb / 10, 1, fd) : 0;
  return (my_write(nb % 10 + 48, fd));
}
