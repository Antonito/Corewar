/*
** parser.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 20:59:17 2016 Antoine Baché
** Last update Fri Mar  4 16:22:52 2016 Antoine Baché
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "errors.h"
#include "tools.h"
#include "endianness.h"

int	prepare_ins(char **inst)
{
  inst[0x10] = NULL;
  if (!(inst[0x00] = my_strdup("live ")) ||
      !(inst[0x01] = my_strdup("ld ")) ||
      !(inst[0x02] = my_strdup("st ")) ||
      !(inst[0x03] = my_strdup("add ")) ||
      !(inst[0x04] = my_strdup("sub ")) ||
      !(inst[0x05] = my_strdup("and ")) ||
      !(inst[0x06] = my_strdup("or ")) ||
      !(inst[0x07] = my_strdup("xor ")) ||
      !(inst[0x08] = my_strdup("zjmp ")) ||
      !(inst[0x09] = my_strdup("ldi ")) ||
      !(inst[0x0a] = my_strdup("sti ")) ||
      !(inst[0x0b] = my_strdup("fork ")) ||
      !(inst[0x0c] = my_strdup("lld ")) ||
      !(inst[0x0d] = my_strdup("lldi ")) ||
      !(inst[0x0e] = my_strdup("lfork ")) ||
      !(inst[0x0f] = my_strdup("aff ")))
    return (1);
  return (0);
}

int		prepareElems(t_data *data)
{
  if (!(data->elem = malloc(sizeof(t_parsing))))
    return (1);
  my_bzero(data->elem, sizeof(t_parsing));
  data->elem->line = data->line;
  data->elem->next = NULL;
  return (0);
}

t_parsing      	*addElem(t_parsing *new, t_parsing *old)
{
  if (!(new = malloc(sizeof(t_parsing))))
    return (NULL);
  my_bzero(new, sizeof(t_parsing));
  new->offset = old->offset + old->size;
  new->next = NULL;
  old->next = new;
  return (new);
}

int		parseFile(int fd, t_data *data)
{
  t_parsing	*tmp_parse;
  t_parsing	*elem;

  tmp_parse = data->elem;
  while ((data->str = get_next_line(fd)) && ++data->line)
    {
      if (data->str[0])
	{
	  if (!(elem = addElem(elem, tmp_parse)))
	    return (free(data->str), errorMalloc());
	  epurStr(data->str);
	  elem->line = data->line;
	  if (getFunction(data, elem))
	    return (free(data->str), 1);
	  tmp_parse = tmp_parse->next;
	}
      free(data->str);
    }
  return (free(data->str), 0);
}

/*
** lseek si pas de com'?
*/
int		check_file(char *str)
{
  t_data	data;

  data.line = 0;
  data.endianness = findEndian();
  if (!(data.ins = malloc(sizeof(char *) * 17)) || prepare_ins(data.ins) ||
      !(data.list = selector()) || prepareLabels(&data))
    return (errorMalloc());
  my_bzero(&data.header, sizeof(t_header));
  if ((data.fd = open(str, O_RDONLY)) < 0)
    return (errorFileName(str));
  if (prepareElems(&data) ||
      prepareHeader(data.fd, &data.header, &data.line) ||
      parseFile(data.fd, &data))
    return (free_elems(&data), 1);
  if (close(data.fd) < 0 || completeLastLabels(&data) || writeFile(&data))
    return (free_elems(&data), 1);
  return (free_elems(&data), 0);
}
