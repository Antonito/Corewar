/*
** check_file.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:56:31 2016 Antoine Baché
** Last update Tue Feb 23 16:45:54 2016 Antoine Baché
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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

int	check_file(char *str)
{
  int	fd;
  int	new;

  if ((fd = open(str, O_RDONLY)) < 0)
    return (errorOpenFile(str));
  if ((new = open("newfile.s", O_RDWR | O_CREAT | O_TRUNC, 00777)) < 0)
    return (errorCreateFile("newfile.s"));
  if (load(fd, new))
    return (1);
  if (close(fd) < 0)
    return (errorCloseFile("newfile.s"));
  return (0);
}
