/*
** epurLast.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar  4 16:57:40 2016 Antoine Baché
** Last update Fri Mar  4 18:27:30 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools.h"

char	*addSpaces(char *str)
{
  int	i;
  int	j;
  int	spaces;
  char	*new;

  i = -1;
  spaces = 0;
  while (str && str[++i])
    if (str[i] == ',' && (str[i + 1] != ' ' && str[i + 1] != '\t'))
      ++spaces;
  if (!spaces)
    return (str);
  if (!(new = malloc(sizeof(char) * (my_strlen(str) + 1 + spaces))))
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i])
    {
      if (i > 0 && str[i - 1] == ',' && str[i] != ' ' && str[i] != '\t')
	new[j++] = ' ';
      new[j++] = str[i];
    }
  new[my_strlen(str) + spaces] = '\0';
  free(str);
  return (new);
}

void	epurLast(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  while (--i > 0 && (str[i] == ' ' || str[i] == '\t'))
    str[i] = '\0';
}
