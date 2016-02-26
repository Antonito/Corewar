/*
** parser.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 20:59:17 2016 Antoine Baché
** Last update Fri Feb 26 15:00:51 2016 Antoine Baché
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "errors.h"
#include "tools.h"

int	prepare_ins(char **inst)
{
  inst[16] = NULL;
  if (!(inst[0] = my_strdup("live ")) || !(inst[1] = my_strdup("ld ")) ||
      !(inst[2] = my_strdup("st ")) || !(inst[3] = my_strdup("add ")) ||
      !(inst[4] = my_strdup("sub ")) || !(inst[5] = my_strdup("and ")) ||
      !(inst[6] = my_strdup("or ")) || !(inst[7] = my_strdup("xor ")) ||
      !(inst[8] = my_strdup("zjmp ")) || !(inst[9] = my_strdup("ldi ")) ||
      !(inst[10] = my_strdup("sti ")) || !(inst[11] = my_strdup("fork ")) ||
      !(inst[12] = my_strdup("lld ")) || !(inst[13] = my_strdup("lldi ")) ||
      !(inst[14] = my_strdup("lfork ")) || !(inst[15] = my_strdup("aff ")))
    return (1);
  return (0);
}

int		prepareElems(t_data *data)
{
  if (!(data->elem = malloc(sizeof(t_parsing))))
    return (1);
  my_bzero(data->elem, sizeof(t_parsing));
  data->elem->next = NULL;
  return (0);
}

t_parsing      	*addElem(t_parsing *new, t_parsing *old)
{
  if (!(new = malloc(sizeof(t_parsing))))
    return (NULL);
  my_bzero(new, sizeof(t_parsing));
  new->next = NULL;
  old->next = new;
  return (new);
}

int		parseFile(int fd, t_data *data)
{
  char		*tmp;
  t_parsing	*tmp_parse;
  t_parsing	*elem;

  tmp_parse = data->elem;
  while ((tmp = get_next_line(fd)) && ++data->line)
    {
      if (tmp[0])
	{
	  if (!(elem = addElem(elem, tmp_parse)))
	    return (errorMalloc());
	  printf("Line %d: %s\n", data->line, tmp);
	  if (getFunction(data, tmp, elem))
	    return (1);
	  tmp_parse = tmp_parse->next;
	}
      free(tmp);
    }
  return (0);
}

/*
** Il faut encore checker le 'file_size' pour le header + lseek si pas de com'?
*/
int		check_file(char *str)
{
  t_data	data;

  data.line = 0;
  if (!(data.ins = malloc(sizeof(char *) * 17)) || prepare_ins(data.ins) ||
      !(data.list = selector()))
    return (errorMalloc());
  my_bzero(&data.header, sizeof(t_header));
  if ((data.fd = open(str, O_RDONLY)) < 0)
    return (errorFileName(str));
  if (prepareElems(&data) || prepareHeader(data.fd, &data.header, &data.line) ||
      parseFile(data.fd, &data))
    return (1);
  if (close(data.fd) < 0 || write_file(str, &data))
    return (1);
  free_elems(data.elem, data.ins);
  return (0);
}
