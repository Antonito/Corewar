/*
** common_errors.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:50:27 2016 Antoine Baché
** Last update Fri Mar 11 05:53:04 2016 Antoine Baché
*/

#include "errors.h"
#include "tools.h"

int	errorMalloc(void)
{
  write(2, "Can't perform malloc\n", 21);
  return (1);
}

int	errorFileName(const char *name)
{
  write(2, "File ", 5);
  write(2, name, my_strlen(name));
  write(2, " not accessible\n", 16);
  return (1);
}
