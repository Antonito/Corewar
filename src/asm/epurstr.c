/*
** epurstr.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Feb 29 17:19:03 2016 Antoine Baché
** Last update Tue Mar  1 00:59:39 2016 Antoine Baché
*/

#include <stdbool.h>
#include "tools.h"

bool	checkLabel(char *str)
{
  int	i;

  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i);
  while (str[i] && (str[i] != ' ' || str[i] != '\t'))
    if (str[i++] == ':')
      return (true);
  return (false);
}

int	epurStrLabel(char *str, int len)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] && (str[i] != ' ' && str[i] != '\t') && ++i);
  if (i == len - 1 || !str[i])
    return (1);
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i);
  if (!str[i])
    return (1);
  while (str[i] && (str[i] != ' ' && str[i] != '\t') && ++i);
  if (!str[i])
    return (1);
  j = i;
  str[j++] = ' ';
  return (0);
}

int	epurStrBeginning(char *str, int len, bool isLabel)
{
  int	i;
  int	j;

  i = -1;
  while (str[++i] && (str[i] == ' ' || str[i] == '\t'));
  if (!(j = 0) && isLabel && --j)
    {
      while (++j + i < len && (str[j] = str[j + i]));
      if (!(i = 0) && str[j - 1] == ':' && !(str[j] = 0))
	return (1);
    }
  else if ((str[0] = '\t'))
    {
      while (++j + i < len && (str[j] = str[j + i - 1]));
      i = 1;
    }
  if (isLabel && epurStrLabel(str, len))
    return (1);
  while (str[i] && (str[i] != ' ' && str[i] != '\t') && ++i && (j = i));
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i);
  str[j] = ' ';
  i -= j;
  while (++j + (i - 1) < len && (str[j] = str[j + i - 1]));
  while (j < len && !(str[j++] = 0));
  return (0);
}

void	epurStrFirstArg(char *str, int len, bool isLabel)
{
  int	i;
  int	j;

  if (!(i = 0) && isLabel)
    i = -1;
  while (str[++i] && str[i] != ',');
  if ((j = ++i) && !str[i - 1])
    return ;
  while (str[i] && (str[i] == ' ' || str[i] == '\t') && ++i);
  i -= (j + 1);
  str[j++] = ' ';
  while (j + i < len && (str[j] = str[j + i]) && ++j);
  while (j < len && !(str[j++] = 0));
  j = i;
  while (str[++i] && str[i] != ',');
  while (str[++i] && str[i] != ',');
  if (!str[i])
    return ;
  j = i;
  while (str[++i]);
  str[++j] = ' ';
  i -= (++j + 2);
  while (j + i < len && (str[j] = str[j + i]) && ++j);
  while (j < len && !(str[j++] = 0));
}

void	epurStr(char *str)
{
  int	len;
  bool	isLabel;

  if (!str)
    return ;
  len = my_strlen(str);
  isLabel = checkLabel(str);
  if (epurStrBeginning(str, len, isLabel))
    return ;
  epurStrFirstArg(str, len, isLabel);
}