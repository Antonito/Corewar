/*
** reverse_byte.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Feb 28 00:42:07 2016 Antoine Baché
** Last update Sun Feb 28 15:47:47 2016 Antoine Baché
*/

int	reverseChar(char *nb)
{
  char	tmp;

  tmp = 0;
  tmp |= (*nb & 0xF0) >> 4;
  tmp |= (*nb & 0x0F) << 4;
  *nb = tmp;
  return (0);
}

int	reverseInt(int *nb)
{
  int	tmp;

  tmp = 0;
  tmp |= (*nb & 0xFF000000) >> 24;
  tmp |= (*nb & 0x00FF0000) >> 8;
  tmp |= (*nb & 0x0000FF00) << 8;
  tmp |= (*nb & 0x000000FF) << 24;
  *nb = tmp;
  return (0);
}

int	reverseShort(short *nb)
{
  short	tmp;

  tmp = 0;
  tmp |= (*nb & 0xF000) >> 8;
  tmp |= (*nb & 0x0F00) >> 8;
  tmp |= (*nb & 0x00F0) << 8;
  tmp |= (*nb & 0x000F) << 8;
  *nb = tmp;
  return (0);
}
