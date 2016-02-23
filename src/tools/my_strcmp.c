/*
** my_strcmp.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:07:59 2016 Antoine Baché
** Last update Tue Feb 23 16:08:06 2016 Antoine Baché
*/

#include "tools.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;
  int	t;

  i = 0;
  j = 0;
  t = my_strlen(s1);
  if (t < my_strlen(s2))
    t = my_strlen(s2);
  while (i < t + 1 && !j)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
