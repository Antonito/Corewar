/*
** getHeader.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar  5 17:11:28 2016 Antoine Baché
** Last update Sun Mar  6 02:26:21 2016 Antoine Baché
*/

#include "tools.h"
#include "errors.h"

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

void	resetLine(int fd, int line)
{
  int	i;

  i = -1;
  lseek(fd, 0, SEEK_END);
  free(get_next_line(fd));
  lseek(fd, 0, SEEK_SET);
  while (++i < line)
    free(get_next_line(fd));
  warningComment(line + 1, NULL);
}

char	*getHeaderLine(int fd, int *line, char mod)
{
  char	*tmp;
  int	line_tmp;

  line_tmp = *line;
  while ((++line_tmp) && (tmp = get_next_line(fd)))
    {
      epurLine(tmp);
#ifdef	DEBUG
      write(1, "Line : ", 7);
      write(1, tmp, my_strlen(tmp));
      write(1, "\n", 1);
#endif
      if (tmp[0] == '.' && (*line = line_tmp))
	return (tmp);
      free(tmp);
    }
  if (mod)
    resetLine(fd, *line);
  return (NULL);
}
