/*
** write_instruction.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 18:38:35 2016 Antoine Baché
** Last update Thu Feb 25 01:21:12 2016 Antoine Baché
*/

#include "decompiler.h"
#include "bytecode.h"
#include "tools.h"

int		write_register(int new, unsigned char *buff, int fd)
{
  unsigned char	str[3];

  my_bzero(buff, 5);
  if (read(fd, buff, 1) < 0)
    return (1);
  printf("Buff[0] = %d\n", buff[0]);
  printf("Buff[1] = %d\n", buff[1]);
  if (buff[0] < 1 || buff[0] > 16)
    return (1);
  printf("Coucou\n");
  my_bzero(&str, 3);
  if (buff[0] <= 9)
    str[0] = buff[0] + 48;
  else
    {
      str[0] = '1';
      str[1] = (buff[0] - 10) + 48;
    }
  if (write(new, "r", 1) < 0 || write(new, str, my_strlen(str)) < 0)
    return (1);
  return (0);
}

int		write_params(int new, unsigned char *buff, int fd)
{
  t_bytecode	byte;
  int		i;
  int		code;

  i = -1;
  byte.bytecode = buff[0];
  while (++i < 4)
    {
      code = getByteCode(&byte);
      my_bzero(buff, 5);
      if (!code && write_register(new, buff, fd))
	return (1);
      if (code == 1 && write_direct(new, buff, fd))
	return (1);
      if (code == 2 && write_indirect(new, buff, fd))
	return (1);
      if (code != -1 && i != 2 && write(new, ", ", 2) < 0)
	return (1);
      byte.bytecode <<= 2;
    }
  return (0);
}

int	write_instruction(int new, unsigned char *buff, char **inst)
{
  int	index;

  if ((index = buff[0] - 1) < 0 || index > 15 ||
      write(new, inst[index], my_strlen(inst[index])) < 0)
    return (1);
  return (0);
}
