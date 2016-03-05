/*
** getHeader.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar  5 17:11:28 2016 Antoine Baché
** Last update Sat Mar  5 17:37:32 2016 Antoine Baché
*/

#include "tools.h"

void	epurLine(char *str)
{
  int	i;
  int	j;
  int	len;

  i = -1;
  j = 0;
  len = my_strlen(str) + 1;
  while (str[++i] == ' ' || str[i] == '\t');
  while (str[i])
    str[j++] = str[i++];
  while (j < len)
    str[j++] = '\0';
}

char	*getHeaderLine(int fd, int *line)
{
  char	*tmp;

  while ((++(*line)) && (tmp = get_next_line(fd)))
    {
      epurLine(tmp);
      if (tmp[0] == '.')
	return (tmp);
      free(tmp);
    }
  return (NULL);
}
