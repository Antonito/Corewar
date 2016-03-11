/*
** isNum.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 08:02:54 2016 Antoine Baché
** Last update Fri Mar 11 08:10:48 2016 Antoine Baché
*/

#include <stdbool.h>

bool	isNum(const char *str)
{
  if (!str)
    return (false);
  while (*str)
    {
      if ((*str < '0' || *str > '9') && *str != '-')
	return (false);
      ++str;
    }
  return (true);
}
