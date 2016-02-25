/*
** errors.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:37:06 2016 Antoine Baché
** Last update Thu Feb 25 19:46:06 2016 Antoine Baché
*/

#include "errors.h"
#include "tools.h"

int	errorRegister(int line)
{
  write(2, "no such register line ", 22);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (1);
}

int	errorLabel(char *label, int line)
{
  write(2, "label ", 6);
  write(2, label, my_strlen(label));
  write(2, " undefined line ", 16);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (1);
}

int	errorSyntax(int line)
{
  write(2, "Syntax error line ", 18);
  my_write_nb(line, 1, 2);
  write(2, "\n", 1);
  return (1);
}
