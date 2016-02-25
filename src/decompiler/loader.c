/*
** loader.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:31:41 2016 Antoine Baché
** Last update Thu Feb 25 01:44:14 2016 Antoine Baché
*/

#include <unistd.h>
#include "decompiler.h"
#include "tools.h"
#include "header.h"

int		check_header(t_header *header)
{
  if (header->magic != (int)0xF383EA00)
    {
      write(2, "Incorrect header\n", 17);
      return (1);
    }
  return (0);
}

int		load_header(int fd, int new)
{
  t_header	header;

  if (read(fd, &header, sizeof(t_header)) != sizeof(t_header) ||
      check_header(&header) ||
      write(new, "\t.name \"", 8) < 0 ||
      write(new, &header.name, my_strlen(header.name)) < 0 ||
      write(new, "\"\n\t.comment \"", 13) < 0 ||
      write(new, &header.comment, my_strlen(header.comment)) < 0 ||
      write(new, "\"\n\n", 3) < 0)
    {
      return (1);
    }
  return (0);
}

int		load(int fd, int new)
{
  if (load_header(fd, new) || load_champ(fd, new))
    return (1);
  return (0);
}
