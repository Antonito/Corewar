/*
** loadHero.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 05:33:52 2016 Antoine Baché
** Last update Fri Mar 25 12:56:38 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "common.h"
#include "tools.h"
#include "header.h"
#include "errors.h"
#include "endianness.h"

t_hero		*genLive(t_hero *heros, t_params *data)
{
  int		i;
  t_hero	*tmp;

  tmp = heros;
  i = 0;
  while (tmp && i < data->process)
    {
      tmp->reg[0] = tmp->id;
      tmp = tmp->next;
      ++i;
    }
  return (heros);
}

void		debugHero(const t_hero *heros, const char *prog)
{
  write(1, "File: ", 6);
  write(1, prog, my_strlen(prog));
  write(1, "\nName: ", 7);
  write(1, heros->name, my_strlen(heros->name));
  write(1, "\nComment: ", 10);
  write(1, heros->comment, my_strlen(heros->comment));
  write(1, "\n", 1);
}

int		loadHeroData(t_hero *heros, int fd, int size)
{
  char		buff[BUFF_SIZE];
  int		i;
  int		check;
  int		readed;

  if (size)
    {
      if (size > MEM_SIZE)
	return (heros->data = NULL, write(2, "Hero is too big\n", 16), 1);
      if (!(heros->data = malloc(sizeof(char) * size)))
	return (errorMalloc());
      my_bzero(buff, BUFF_SIZE);
      check = -1;
      while (i = -1, (readed = read(fd, buff, BUFF_SIZE - 1)) > 0)
	{
	  if (readed < 0)
	    return (write(2, "Error while reading file\n", 25), 1);
	  while (++i < readed && ++check > -1)
	    heros->data[check] = buff[i];
	  my_bzero(buff, BUFF_SIZE);
	}
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
  reverseInt(&header.prog_size, findEndian());
  heros->size = header.prog_size;
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
#ifdef	DEBUG
  debugHero(heros, prog);
#endif
  return (0);
}
