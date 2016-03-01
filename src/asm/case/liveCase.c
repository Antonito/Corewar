/*
** liveCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Tue Mar  1 01:17:49 2016 Antoine Baché
*/

#include "asm.h"
#include "errors.h"
#include "tools.h"

int	writeLive(int new, t_parsing *tmp)
{
  int	nb;

  nb = 0;
  nb |= (tmp->value[0] & 0xFF000000) >> 24;
  nb |= (tmp->value[0] & 0x00FF0000) >> 8;
  nb |= (tmp->value[0] & 0x0000FF00) << 8;
  nb |= (tmp->value[0] & 0x000000FF) << 24;
  if (write(new, &nb, 4) < 0)
    return (1);
  return (0);
}

int	getLabelLive(t_data *data, t_parsing *elem, int *offset)
{
  return (0);
}

int	getLive(t_data *data, t_parsing *elem, int *offset)
{
  int	tmp;
  int	i;
  char	*nb;

  tmp = (*offset) - 1;
  while (data->str[++tmp]);
  if (!(nb = malloc(sizeof(char) * (tmp - (*offset) + 1))))
    return (errorMalloc());
  i = 0;
  while ((*offset) + i < tmp && (nb[i] = data->str[(*offset + i)]))
    if (nb[i] < '0' || nb[i++] > '9')
      return (errorSyntax(data->line));
  nb[tmp - (*offset)] = 0;
  elem->value[0] = my_getnbr(nb);
  free(nb);
#ifdef	DEBUG
  write(1, "[INFOS] Live ", 13);
  my_put_nbr(elem->value[0]);
  write(1, "\n", 1);
#endif
  return (0);
}

int	liveCase(t_data *data, t_parsing *elem, int *offset)
{
  *offset += 3;
  if (data->str[++(*offset)] != ' ' || data->str[++(*offset)] != '%')
    return (errorSyntax(data->line));
  if (data->str[++(*offset)] == ':')
    return (getLabelLive(data, elem, offset));
  else if (data->str[*offset] > '0' && data->str[*offset] <= '9')
    return (getLive(data, elem, offset));
  else
    return (errorSyntax(data->line));
  return (0);
}
