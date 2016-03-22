/*
** checkLabel.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar  3 16:31:23 2016 Antoine Baché
** Last update Sun Mar  6 04:39:28 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"

int		prepareLabels(t_data *data)
{
  if (!(data->label = malloc(sizeof(t_label))))
    return (1);
  my_bzero(data->label, sizeof(t_label));
  data->label->label = NULL;
  data->label->next = NULL;
  return (0);
}

t_label		*addLabel(t_label *new, t_label *old)
{
  if (!(new = malloc(sizeof(t_label))))
    return (NULL);
  my_bzero(new, sizeof(t_label));
  new->next = NULL;
  old->next = new;
  return (new);
}

int		calcOffset(t_parsing *tmp, t_parsing *elem, bool isSmaller)
{
  int		total;
  t_parsing	*another_tmp;

  total = 0;
  another_tmp = elem;
  if (isSmaller)
    {
      while (tmp != NULL && tmp->line != elem->line)
	{
	  total -= tmp->size;
	  tmp = tmp->next;
	}
    }
  else
    {
      while (another_tmp != NULL && tmp->line != another_tmp->line)
	{
	  total += another_tmp->size;
	  another_tmp = another_tmp->next;
	}
    }
  return ((unsigned short)total);
}

int		completeLastLabels(t_data *data)
{
  t_parsing	*tmp;
  t_label	*tmp2;
  int		i;

  tmp = data->elem;
  while (tmp && (i = -1))
    {
      while (++i < 3 && (tmp2 = data->label))
	if (tmp->labelId[i] != 0)
	  while (tmp2)
	    {
	      if (tmp2->id && tmp2->id == tmp->labelId[i])
		{
#ifdef	DEBUG
		  write(1, tmp2->label, my_strlen(tmp2->label));
		  write(1, "\n", 1);
#endif
		  loopLastLabels(tmp2->id, data, tmp, i);
		  break;
		}
	      tmp2 = tmp2->next;
	    }
      tmp = tmp->next;
    }
  return (0);
}

char	*parseLabel(t_data *data, int *offset)
{
  char *label;
  int	tmp;
  int	shift;
  int	j;

  tmp = ++(*offset);
  while (data->str[tmp] && data->str[tmp] != ' ' && data->str[tmp] != ',' &&
	 ++tmp);
  shift = tmp  - (*offset);
  if (!(label = malloc(sizeof(char) * (shift + 1))))
    return (NULL);
  j = -1;
  while (++j < shift && (label[j] = data->str[j + (*offset)]));
  label[tmp - (*offset)] = 0;
  *offset = tmp + 1;
  return (label);
}
