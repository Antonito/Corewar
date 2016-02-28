/*
** get_label.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 05:41:59 2016 Antoine Baché
** Last update Sat Feb 27 22:31:17 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"

int	getLabel(t_data *data, t_parsing *elem, int *offset, int i)
{
  int	tmp;

  tmp = *offset;
  while (data->str[tmp] && data->str[tmp] != ',' &&
	 data->str[tmp] != '\n' && ++tmp);
  if (data->str[tmp] != ',' && data->str[tmp] != '\n')
    return (errorSyntax(data->line));
  *offset = tmp;
  if (data->str[tmp] == ',' && data->str[++(*offset)] != ' ')
    return (errorSyntax(data->line));
  return (0);
}
