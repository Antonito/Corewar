/*
** write_file.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 22:42:05 2016 Antoine Baché
** Last update Mon Mar  7 14:19:35 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "tools.h"

int		errorWriting(char *str)
{
  write(2, "Error while writing file ", 25);
  if (str)
    write(2, str, my_strlen(str));
  write(2, "\n", 1);
  if (str)
    free(str);
  return (1);
}

int		writeArgs(int new, t_parsing *tmp, writetab tab, int endian)
{
  return (tab[(int)(tmp->function - 1)](new, tmp, endian));
}

int		endHeader(int new, t_data *data)
{
  int		size;

  if ((size = lseek(data->fd, 0, SEEK_END)) == -1 ||
      (size = size - sizeof(t_header)) < 0 ||
      reverseInt(&size, data->endianness) ||
      lseek(new, OFFSETOF(t_header, prog_size), SEEK_SET) == -1 ||
      write(new, &size, sizeof(int)) < 0)
    return (1);
  return (0);
}

char	*getName(char *str)
{
  int	i;
  char	*new;
  int	location;
  int	size;

  i = -1;
  if (!(location = -1) || !(new = malloc((size = my_strlen(str)) + 3)) ||
      (my_bzero(new, size + 3), !(new = my_strncpy(new, str, size + 3))))
    return (NULL);
  while (new[++i])
    if (new[i] == '/')
      location = i;
  if (!(i = 0) && location != -1)
    {
      while (i + location < size && (new[i] = new[i + location]) && ++i);
      i = 0;
      while (new[i] && (new[i] = new[i + 1]) && ++i);
    }
  i = -1;
  while (new[++i] && new[i] != '.');
  if (!new[i++] && (free(new), (new = malloc(9)) || 1))
    return (my_bzero(new, 9), (new = my_strncpy(new, "file.cor", 8)));
  if ((new[i++] = 'c') && (new[i++] = 'o') && (new[i++] = 'r') && (new[i] = 0))
    return (NULL);
  return (new);
}

int		writeFile(t_data *data, char *str)
{
  char		*name;
  t_parsing	*tmp;
  writetab	tab;
  int		new;

  if (!(tab = selector_write()) || !(name = getName(str)) ||
      (new = open(name, O_RDWR | O_CREAT | O_TRUNC, 00644)) < 0 ||
      write(new, &data->header, sizeof(t_header)) < 0)
    return (errorWriting(name));
  tmp = data->elem->next;
  while (tmp)
    {
      ++tmp->function;
      if (((tmp->function <= 0x10) ? write(new, &tmp->function, 1) : 0) < 0 ||
	  ((tmp->bytecode) ? write(new, &tmp->bytecode, 1) : 0) < 0)
	return (errorWriting(name));
      if (writeArgs(new, tmp, tab, data->endianness))
	return (errorWriting(name));
      tmp = tmp->next;
    }
  free(tab);
  if (endHeader(new, data) || close(new) < 0)
    return (errorWriting(name));
  return (free(name), 0);
}
