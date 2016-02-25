/*
** check_file.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:56:31 2016 Antoine Baché
** Last update Wed Feb 24 17:00:36 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "decompiler.h"
#include "tools.h"

int	errorCloseFile(char *str)
{
  write(2, "Cannot close file ", 18);
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (1);
}

int	errorCreateFile(char *str)
{
  write(2, "Cannot create file ", 19);
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (1);
}

int	errorOpenFile(char *str)
{
  write(2, "Cannot open file ", 17);
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (1);
}

void	getName(char *str)
{
  int	i;
  int	location;
  int	size;

  i = -1;
  location = -1;
  size = my_strlen(str);
  while (str[++i])
    if (str[i] == '/')
      location = i;
  i = 0;
  if (location != -1)
    {
      while (i + location < size && (str[i] = str[i + location]) && ++i);
      i = 0;
      while (str[i] && (str[i] = str[i + 1]) && ++i);
    }
  i = 0;
  while (str[i] && str[i++] != '.');
  str[i++] = 's';
  str[i] = 0;
}

int	check_file(char *str)
{
  int	fd;
  int	new;

  if ((fd = open(str, O_RDONLY)) < 0)
    return (errorOpenFile(str));
  getName(str);
  if ((new = open(str, O_RDWR | O_CREAT | O_TRUNC, 00644)) < 0)
    return (errorCreateFile(str));
  if (load(fd, new))
    return (1);
  if (close(fd) < 0)
    return (errorCloseFile(str));
  if (close(new) < 0)
    return (errorCloseFile(str));
  return (0);
}
