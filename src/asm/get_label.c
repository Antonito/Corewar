/*
** get_label.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 05:41:59 2016 Antoine Baché
** Last update Sun Mar  6 04:39:12 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "errors.h"

int	getLabelLine(int fd, char *label, int dataline)
{
  char	*line;
  int	nb_line;
  int	size;
  int	i;

  if (!(nb_line = 0) && (i = -1) && (size = my_strlen(label)) &&
      (lseek(fd, 0, SEEK_END) < 0 ||
       (free(get_next_line(fd)), lseek(fd, 0, SEEK_SET) < 0)))
    return (1);
  while (++nb_line && (line = get_next_line(fd)))
    {
      if (epurStr(line), nb_line > 1 && !my_strncmp(line, label, size))
	{
	  if (lseek(fd, 0, SEEK_SET) == -1)
	    return (1);
	  while (++i < dataline)
	    free(get_next_line(fd));
	  return (free(line), nb_line);
	}
      free(line);
    }
  lseek(fd, 0, SEEK_SET);
  while (++i < dataline)
    free(get_next_line(fd));
  return (errorLabel(label, dataline));
}

int		getLowerLabel(t_data *data, t_parsing *elem, int line, int i)
{
  t_parsing	*tmp;

  tmp = data->elem;
  while (tmp != NULL)
    {
      if (line == tmp->line)
	break;
      tmp = tmp->next;
    }
  if (!tmp)
    return (1);
  elem->value[i] = calcOffset(tmp, elem, 1);
  return (0);
}

void		loopLastLabels(int line, t_data *data, t_parsing *elem, int j)
{
  t_parsing	*label;

  label = data->elem;
  while (label && label->line != line)
    label = label->next;
  elem->value[j] = calcOffset(label, elem, 0);
}

int		prepareInfosLabel(t_data *data, t_parsing *elem,
				  int i, char *label)
{
  t_label	*new;
  t_label	*tmp;

  tmp = data->label;
  while (tmp->next)
    tmp = tmp->next;
  new = NULL;
  if (!(new = addLabel(new, tmp)) ||
      !(new->label = my_strdup(label)))
    return (1);
  new->id = elem->labelId[i];
  return (0);
}

int	getLabel(t_data *data, char *label, t_parsing *elem, int i)
{
  int	line;

  if (!(label = labelize(label)) ||
      (line = getLabelLine(data->fd, label, data->line)) == 1)
    return (1);
#ifdef	DEBUG
  write(1, "Label [", 7);
  my_put_nbr(line);
  write(1, "] : ", 4);
  write(1, label, my_strlen(label));
  write(1, "\n", 1);
#endif
  if (line < data->line)
    {
      if (getLowerLabel(data, elem, line, i))
	return (1);
    }
  else
    {
      elem->labelId[i] = line;
      if (prepareInfosLabel(data, elem, i, label))
	return (1);
    }
  return (free(label), 0);
}
