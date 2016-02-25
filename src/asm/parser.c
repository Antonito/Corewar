/*
** parser.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 20:59:17 2016 Antoine Baché
** Last update Thu Feb 25 23:31:37 2016 Antoine Baché
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "errors.h"
#include "tools.h"

int		prepareElems(t_data *data)
{
  if (!(data->elem = malloc(sizeof(t_parsing))))
    return (1);
  my_bzero(data->elem, sizeof(t_parsing));
  data->elem->next = NULL;
  return (0);
}

int		parseFile(int fd, t_data *data)
{
  char		*tmp;

  while ((tmp = get_next_line(fd)) && ++data->line)
    {
      /* if (tmp[0]) */
      /* 	{ */
	  printf("Line %d: %s\n", data->line, tmp);
	/* } */
      free(tmp);
    }
  return (0);
}

/*
** Il faut encore checker le 'file_size' pour le header + lseek si pas de com'?
*/
int		check_file(char *str)
{
  int		fd;
  t_data	data;

  data.line = 0;
  my_bzero(&data.header, sizeof(t_header));
  if ((fd = open(str, O_RDONLY)) < 0)
    return (errorFileName(str));
  if (prepareElems(&data) || prepareHeader(fd, &data.header, &data.line) ||
      parseFile(fd, &data))
    return (1);
  if (close(fd) < 0 || write_file(str, &data))
    return (1);
  free_elems(data.elem);
  return (0);
}
