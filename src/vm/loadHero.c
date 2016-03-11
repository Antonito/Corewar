/*
** loadHero.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 05:33:52 2016 Antoine Baché
** Last update Fri Mar 11 06:03:52 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "header.h"
#include "errors.h"

int		loadHeader(t_hero *heros, int fd, const char *prog)
{
  t_header	header;

  if (read(fd, &header, sizeof(t_header)) < 0)
    return (write(2, "Error reading file\n", 19), 1);
  if (header.magic != (int)0xF383EA00)
    return (errorFileType(prog));
  return (0);
}

int		loadHero(t_hero *heros, char *prog)
{
  int		fd;

  if (!prog)
    return (write(2, "Corewar executable missing\n", 27), 1);
  if ((fd = open(prog, O_RDONLY)) == -1)
    return (errorFileName(prog));
  if (loadHeader(heros, fd, prog))
    return (close(fd), 1);
  if (close(fd) < 0)
    return (write(2, "Cannot close file\n", 18), 1);
  return (0);
}
