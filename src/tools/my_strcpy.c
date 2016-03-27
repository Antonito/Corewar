/*
** my_strcpy.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 25 04:16:42 2016 Antoine Baché
** Last update Sun Mar 27 18:13:33 2016 Antoine Baché
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = -1;
  while (src[(i = i + 1)] != '\0')
  {
    dest[i] = src[i];
  }
  return (dest);
}
