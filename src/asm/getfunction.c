/*
** getfunction.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 11:04:59 2016 Antoine Baché
** Last update Fri Feb 26 13:56:38 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "errors.h"

int	findName(const char *str, const int offset, char **ins)
{
  int	i;

  i = 0;
  str += offset;
  while (i < 16)
    {
      if (!my_strncmp(str, ins[i], my_strlen(ins[i])))
	return (i);
      ++i;
    }
  return (-1);
}

int	getFunction(t_data *data, char *str, t_parsing *elem)
{
  int	i;

  i = 0;
  if (str[i] != '\t')
    {
      while (str[i] && str[i] != ':' && ++i);
      ++i;
    }
  ++i;
  if ((elem->function = findName(str, i, data->ins)) == -1)
    return (errorSyntax(data->line));
  if (getArgs(data, str, elem, i))
    return (1);
  return (0);
}
