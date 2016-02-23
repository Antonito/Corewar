/*
** my_strncat.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:09:05 2016 Antoine Baché
** Last update Tue Feb 23 16:09:11 2016 Antoine Baché
*/

#include "tools.h"

char	*my_strncat(char *dest, char *src, int n)
{
  int	count;
  int	len;

  count  = 0;
  len = my_strlen(dest);
  while (src[count] != '\0' && count < n)
    {
      dest[len] = src[count];
      len++;
      count++;
    }
  dest[len] = '\0';
  return (dest);
}
