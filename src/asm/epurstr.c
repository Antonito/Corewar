/*
** epurstr.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Feb 29 17:19:03 2016 Antoine Baché
** Last update Sat Mar  5 21:41:04 2016 Antoine Baché
*/

#include <stdbool.h>
#include "asm.h"
#include "tools.h"

bool	checkLabel(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != '#' && (str[i] == ' ' || str[i] == '\t') && ++i);
  while (str[i] && str[i] != '#' && (str[i] != ' ' && str[i] != '\t'))
    if (str[i++] == ':')
      return (true);
  return (false);
}

int	epurStrLabel(char *str, int len)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] && str[i] != '#' && (str[i] != ' ' && str[i] != '\t') && ++i);
  if (i == len - 1 || !str[i])
    return (1);
  while (str[i] && str[i] != '#' && (str[i] == ' ' || str[i] == '\t') && ++i);
  if (!str[i])
    return (1);
  while (str[i] && str[i] != '#' && (str[i] != ' ' && str[i] != '\t') && ++i);
  if (!str[i])
    return (1);
  j = i;
  str[j++] = ' ';
  return (0);
}

int	epurStrBeginning(char *str, int len, bool isLabel, int i)
{
  int	j;

  while (str[++i] && str[i] != '#' && (str[i] == ' ' || str[i] == '\t'));
  if (!(j = 0) && isLabel && --j)
    {
      while (++j + i < len && (str[j] = str[j + i]));
      if (!(i = 0) && str[j - 1] == ':' && str[j] != ':' && !(str[j] = 0))
	return (1);
    }
  else if ((str[0] = '\t'))
    {
      while (++j + i - 1 < len && (str[j] = str[j + i - 1]));
      while (j < len && (str[j++] = 0));
      i = 1;
    }
  if (isLabel && epurStrLabel(str, len))
    return (1);
  while ((j = i) >= 0 &&
	 str[i] && str[i] != '#' && (str[i] != ' ' && str[i] != '\t') && ++i);
  while (i < len && str[i] != '#' && (str[i] == ' ' || str[i] == '\t') && ++i);
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
  while (str[i] && str[i] != '#' && (str[i] == ' ' || str[i] == '\t') && ++i);
  i -= (j + 1);
  str[j++] = ' ';
  while (j + i < len && (str[j] = str[j + i]) && ++j);
  while (j < len && !(str[j++] = 0));
  j = i;
  while (str[++i] && i < len && str[i] != '#' && str[i] != ',');
  while (str[++i] && i < len && str[i] != '#' && str[i] != ',');
  if ((j = i) && !str[i])
    return ;
  while (++i < len && str[i] &&
	 str[i] != '#' && (str[i] == ' ' || str[i] == '\t'));
  (j < len) ? (str[++j] = ' ') : (str[j++] = ' ');
  i -= j + 1;
  while (j + i < len &&
	 (str[j] = str[j + i]) && ++j);
  while (j++ < len && !(str[j] = 0));
}

void	epurStr(char *str)
{
  int	len;
  bool	isLabel;
  bool	correct;
  int	i;

  if (!str)
    return ;
  len = my_strlen(str);
  isLabel = checkLabel(str);
  i = -1;
  correct = false;
  while (str[++i] && str[i] != '#')
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
      correct = true;
  if (correct == false && !(str[0] = '\0'))
    return ;
  if (str[i] == '#')
    str[i] = 0;
  if (epurStrBeginning(str, len, isLabel, -1))
    return ;
  epurStrFirstArg(str, len, isLabel);
  epurLast(str, len);
}
