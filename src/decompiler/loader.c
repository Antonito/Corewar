/*
** loader.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:31:41 2016 Antoine Baché
** Last update Tue Feb 23 16:55:29 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools.h"
#include "header.h"


/*
** Penser a tester sans .name ET / OU .comment
*/
int		load(int fd, int new)
{
  t_header	header;

  if (read(fd, &header, sizeof(t_header)) != sizeof(t_header) ||
      write(new, "\t.name \"", 8) < 0 ||
      write(new, &header.name, my_strlen(header.name)) < 0 ||
      write(new, "\"\n\t.comment \"", 13) < 0 ||
      write(new, &header.comment, my_strlen(header.comment)) < 0 ||
      write(new, "\"\n", 2) < 0)
    return (1);
  return (0);
}
