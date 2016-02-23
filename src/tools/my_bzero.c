/*
** my_bzero.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:05:22 2016 Antoine Baché
** Last update Tue Feb 23 16:05:28 2016 Antoine Baché
*/

void		my_bzero(void *content, int size)
{
  unsigned char	*addr;

  addr = content;
  while (size--)
    addr[size] = 0;
}
