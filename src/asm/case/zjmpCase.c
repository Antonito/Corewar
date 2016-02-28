/*
** zjmpCase.c for Corewar in /CPE_2015_corewar/src/asm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 14:46:22 2016 Antoine Baché
** Last update Sat Feb 27 22:12:02 2016 Antoine Baché
*/

#include "asm.h"

int	zjmpCase(t_data *data, t_parsing *elem, int *offset)
{
  printf("ZJMP: [%d] = %c\n", *offset, data->str[*offset]);
  printf("Str = \"%s\"\n", data->str);
  return (0);
}
