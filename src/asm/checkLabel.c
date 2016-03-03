/*
** checkLabel.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Mar  3 16:31:23 2016 Antoine Baché
** Last update Thu Mar  3 18:29:07 2016 Antoine Baché
*/

#include "asm.h"

char	*parseLabel(t_data *data, t_parsing *elem, int *offset)
{
  char *label;
  int	tmp;
  int	shift;
  int	j;

  tmp = ++(*offset);
  while (data->str[tmp] && data->str[tmp] != ' ' && data->str[tmp] != ',' &&
	 ++tmp);
  printf("StrOff: %c\n", data->str[*offset]);
  printf("StrTmp: %c\n", data->str[tmp]);
  shift = tmp  - (*offset);
  if (!(label = malloc(sizeof(char) * (shift + 1))))
    return (NULL);
  j = -1;
  while (++j < shift && (label[j] = data->str[j + (*offset)]));
  label[tmp - (*offset)] = 0;
  return (label);
}
