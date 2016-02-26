/*
** write_file.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 22:42:05 2016 Antoine Baché
** Last update Fri Feb 26 14:03:17 2016 Antoine Baché
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

int		write_file(char *str, t_data *data)
{
  t_parsing	*tmp;
  int		new;

  if ((new = open("test.cor", O_RDWR | O_CREAT | O_TRUNC, 00644)) < 0 ||
      write(new, &data->header, sizeof(t_header)) < 0)
    return (errorWriting("test.cor"));
  tmp = data->elem->next;
  while (tmp)
    {
      ++tmp->function;
      if (write(new, &tmp->function, 1) < 0 ||
	  ((tmp->bytecode) ? write(new, &tmp->bytecode, 1) : 0) < 0)
	return (errorWriting("test.cor"));
      tmp = tmp->next;
    }
  return (0);
}
