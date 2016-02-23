/*
** my_strncpy.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:09:49 2016 Antoine Baché
** Last update Tue Feb 23 16:09:59 2016 Antoine Baché
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
