/*
** header.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 21:45:58 2016 Antoine Baché
** Last update Fri Feb 26 10:27:26 2016 Antoine Baché
*/

#include <stdlib.h>
#include "asm.h"
#include "errors.h"
#include "tools.h"

int	warningComment(int line, char *tmp)
{
  if (tmp)
    free(tmp);
  write(2, "Warning: Line ", 14);
  my_write_nb(line, 1, 2);
  write(2, ": No comment specified.\n", 24);
  return (0);
}

int	errorName(int line, char *tmp)
{
  if (tmp)
    free(tmp);
  write(2, "Line ", 5);
  my_write_nb(line, 1, 2);
  write(2, ": No name specified.\n", 21);
  return (1);
}

int	getComment(char *tmp, t_header *header, int *line, int fd)
{
  int	i;
  int	j;

  i = 0;

  while (tmp[i] && tmp[i] != '.' && ++i);
  if ((!tmp[i] || tmp[++i] != 'c' || tmp[++i] != 'o' || tmp[++i] != 'm' ||
      tmp[++i] != 'm' || tmp[++i] != 'e' || tmp [++i] != 'n' ||
       tmp[++i] != 't' || tmp[++i] != ' ' || tmp[++i] != '"') && (*line)--)
    return (((lseek(fd, 0, SEEK_CUR) != -1) ?
	     warningComment(*line + 1, NULL) : 1));
  j = 0;
  while (tmp[++i] && tmp[i] != '"' && (header->comment[j] = tmp[i]) &&
	 ++j < 2047);
  if (tmp[i] != '"')
    return (((j == 2047) ?
	     write(2, "The program name is too long. It will be truncated.\n",
		   52) : errorSyntax(* line)));
  return (0);
}

int	getHeaderName(char *tmp, t_header *header, int line)
{
  int	i;
  int	j;

  i = 0;
  while (tmp[i] && tmp[i] != '.' && ++i);
  if (!tmp[i] || tmp[++i] != 'n' || tmp[++i] != 'a' || tmp[++i] != 'm' ||
      tmp[++i] != 'e' || tmp[++i] != ' ' || tmp[++i] != '"')
    return (errorName(line, tmp));
  j = 0;
  while (tmp[++i] && tmp[i] != '"' && (header->name[j] = tmp[i]) && ++j < 127);
  if (tmp[i] != '"')
    return (((j == 127) ?
	     write(2, "The program name is too long. It will be truncated.\n",
		   52) : errorSyntax(line)));
  return (0);
}

int	prepareHeader(int fd, t_header *header, int *line)
{
  char	*tmp;

  header->magic = (int)0xF383EA00;
  if (!(tmp = get_next_line(fd)))
    return (errorMalloc());
  ++(*line);
  if (getHeaderName(tmp, header, *line))
    return (1);
  free(tmp);
  if (!(tmp = get_next_line(fd)))
    return (errorMalloc());
  ++(*line);
  if (getComment(tmp, header, line, fd))
    return (1);
  free(tmp);
  return (0);
}
