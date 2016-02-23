/*
** my_strlen.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:08:27 2016 Antoine Baché
** Last update Tue Feb 23 16:08:42 2016 Antoine Baché
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && *str != '\0' && (str++) && (++i));
  return (i);
}
