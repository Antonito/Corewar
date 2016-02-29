/*
** getfunction.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 11:04:59 2016 Antoine Baché
** Last update Mon Feb 29 18:27:01 2016 Antoine Baché
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

int	getFunction(t_data *data, t_parsing *elem)
{
  int	i;

  i = 0;
  if (data->str[i] != '\t')
    {
      while (data->str[i] && data->str[i] != ':' && ++i);
      ++i;
    }
  if (!data->str[i] && (elem->function = 16) && !(elem->bytecode = 0))
    return (0);
  ++i;
  if ((elem->function = findName(data->str, i, data->ins)) == -1)
    return (errorSyntax(data->line));
#ifdef	DEBUG
  write(1, "[INFOS] Found name !\n", 21);
#endif
  if (getArgs(data, elem, i))
    return (1);
#ifdef	DEBUG
  write(1, "[INFOS] Found args !\n", 21);
#endif
  return (0);
}
