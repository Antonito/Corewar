/*
** my_strndup.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:10:17 2016 Antoine Baché
** Last update Sun Mar 27 18:14:35 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools.h"

char	*my_strndup(const char *src, int n)
{
  char	*dest;
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  my_bzero(dest, n + 1);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(const char *src)
{
  char	*dest;
  int	i;
  int	n;

  i = 0;
  n = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
