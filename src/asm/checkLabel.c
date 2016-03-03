/*
** checkLabel.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar  3 16:31:23 2016 Antoine Baché
** Last update Fri Mar  4 00:51:06 2016 Antoine Baché
*/

#include "asm.h"

int		calcOffset(t_parsing *tmp, t_parsing *elem, bool isSmaller)
{
  int		total;
  t_parsing	*another_tmp;

  total = 0;
  another_tmp = elem;
  if (isSmaller)
    {
      while (tmp != NULL && tmp != elem)
	{
	  total -= tmp->size;
	  tmp = tmp->next;
	}
    }
  else
    {
      while (another_tmp != NULL && tmp != another_tmp)
	{
	  total += another_tmp->size;
	  another_tmp = another_tmp->next;
	}
    }
  return ((unsigned short)total);
}

char	*parseLabel(t_data *data, t_parsing *elem, int *offset)
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
  return (label);
}
