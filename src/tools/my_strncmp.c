/*
** my_strncmp.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:09:27 2016 Antoine Baché
** Last update Tue Mar 22 22:55:52 2016 Antoine Baché
*/

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j == 0 && s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return ((i > 0) ? j : -1);
}

int	my_strncmp_(const char *s1, const char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j == 0 && i < n)
    {
      if (i == n - 1)
	return (s1[i] - s2[i]);
      if (!s1[i] || !s2[i] || s1[i] != s2[i])
	return (1);
      ++i;
    }
  return (0);
}
