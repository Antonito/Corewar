/*
** write_file.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 22:42:05 2016 Antoine Baché
** Last update Wed Mar  2 07:21:54 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "tools.h"

int		errorWriting(char *str)
{
  write(2, "Error while writing file ", 25);
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (1);
}

int		writeArgs(int new, t_parsing *tmp, writetab tab, int endian)
{
  printf("Function = %d Offset = %d\n", tmp->function, tmp->offset);
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

int		writeFile(t_data *data)
{
  t_parsing	*tmp;
  writetab	tab;
  int		new;

  if (!(tab = selector_write()) ||
      (new = open("test.cor", O_RDWR | O_CREAT | O_TRUNC, 00644)) < 0 ||
      write(new, &data->header, sizeof(t_header)) < 0)
    return (errorWriting("test.cor"));
  tmp = data->elem->next;
  while (tmp)
    {
      ++tmp->function;
      if (((tmp->function <= 0x10) ? write(new, &tmp->function, 1) : 0) < 0 ||
	  ((tmp->bytecode) ? write(new, &tmp->bytecode, 1) : 0) < 0)
	return (errorWriting("test.cor"));
      if (writeArgs(new, tmp, tab, data->endianness))
	return (errorWriting("test.cor"));
      tmp = tmp->next;
    }
  free(tab);
  if (endHeader(new, data) || close(new) < 0)
    return (errorWriting("test.cor"));
  return (0);
}
