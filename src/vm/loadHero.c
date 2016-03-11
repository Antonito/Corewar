/*
** loadHero.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 05:33:52 2016 Antoine Baché
** Last update Fri Mar 11 06:37:06 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "common.h"
#include "tools.h"
#include "header.h"
#include "errors.h"

int		loadHeroData(t_hero *heros, int fd, int size)
{
  if (size)
    {
      if (size > MEM_SIZE)
	return (write(2, "Hero is too big\n", 16), 1);
      printf("size = %d\n", size);
      if (!(heros->data = malloc(sizeof(char) * size)))
	return (errorMalloc());
      if (read(fd, heros->data, size) < 0)
	return (write(2, "Error reading hero\n", 19), 1);
    }
  return (0);
}

int		loadHeader(t_hero *heros, int fd, const char *prog)
{
  t_header	header;

  if (read(fd, &header, sizeof(t_header)) < 0)
    return (write(2, "Error reading file\n", 19), 1);
  if (header.magic != (int)0xF383EA00)
    return (errorFileType(prog));
  if (!(heros->name = my_strdup(header.name)) ||
      !(heros->comment = my_strdup(header.comment)))
    return (errorMalloc());
  return (loadHeroData(heros, fd, header.prog_size));
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
