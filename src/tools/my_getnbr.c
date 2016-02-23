/*
** my_getnbr.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:05:50 2016 Antoine Baché
** Last update Tue Feb 23 16:06:12 2016 Antoine Baché
*/

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  long	r;

  i = 0;
  s = 1;
  r = 0;
  if (!str)
    return (0);
  while (str[i] == 43 || str[i] == 45)
    {
      if (str[i] == 45)
	s = -s;
      i++;
    }
  str += i;
  i = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      r = r * 10;
      r = r + str[i] - 48;
      i++;
    }
  return (r > 2147483647 || r < -2147483648 ? 0 : s * r);
}
