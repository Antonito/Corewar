/*
** checkStrTab.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 16:01:08 2016 Antoine Baché
** Last update Fri Mar 11 16:57:36 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools.h"
#include "errors.h"

char	*checkStrTab(char *str)
{
  char	*new;
  int	i;

  if (str && str[0] != ' ' && str[0] != '\t')
    {
      i = 0;
      if (!(new = malloc(sizeof(char) * (my_strlen(str) + 2))))
	return (errorMalloc(), NULL);
      new[0] = '\t';
      while (str && ++i && str[i - 1])
	new[i] = str[i - 1];
      new[my_strlen(str) + 1] = 0;
      free(str);
      return (new);
    }
  return (str);
}
