/*
** reverse_byte.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Feb 28 00:42:07 2016 Antoine Baché
** Last update Tue Mar 22 13:47:24 2016 Antoine Baché
*/

#include "endianness.h"

int		reverseInt(int *nb, int endian)
{
  int		tmp;

  if (endian == LITTLE_ENDIAN)
    {
      tmp = 0;
      tmp |= (*nb & 0xFF000000) >> 24;
      tmp |= (*nb & 0x00FF0000) >> 8;
      tmp |= (*nb & 0x0000FF00) << 8;
      tmp |= (*nb & 0x000000FF) << 24;
      *nb = tmp;
    }
  return (0);
}

unsigned int	reverseUInt(int *nb, int endian)
{
  unsigned int	tmp;

  if (endian == LITTLE_ENDIAN)
    {
      tmp = 0;
      tmp |= (*nb & 0xFF000000) >> 24;
      tmp |= (*nb & 0x00FF0000) >> 8;
      tmp |= (*nb & 0x0000FF00) << 8;
      tmp |= (*nb & 0x000000FF) << 24;
      *nb = tmp;
    }
  return (0);
}

short		reverseShort(unsigned short *nb, int endian)
{
  short		tmp;

  if (endian == LITTLE_ENDIAN)
    {
      tmp = 0;
      tmp |= (*nb & 0xF000) >> 8;
      tmp |= (*nb & 0x0F00) >> 8;
      tmp |= (*nb & 0x00F0) << 8;
      tmp |= (*nb & 0x000F) << 8;
      *nb = tmp;
    }
  return (0);
}

unsigned short		reverseUShort(unsigned short *nb, int endian)
{
  unsigned short	tmp;

  if (endian == LITTLE_ENDIAN)
    {
      tmp = 0;
      tmp |= (*nb & 0xF000) >> 8;
      tmp |= (*nb & 0x0F00) >> 8;
      tmp |= (*nb & 0x00F0) << 8;
      tmp |= (*nb & 0x000F) << 8;
      *nb = tmp;
    }
  return (0);
}
